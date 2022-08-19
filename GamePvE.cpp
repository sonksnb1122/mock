#include "GamePvE.h"
#include <cstdlib>
#include <math.h>


GamePvE::GamePvE(): 
    Game() {}
GamePvE::GamePvE(int size, Person *character1, Person *character2):
    Game(size, character1, character2) {}
GamePvE::GamePvE(int size):
    Game(size) {}

Game *GamePvE::clone() {
    return new GamePvE(*this);
}

void GamePvE::play() {
    int mode; 
    cout << "Nhập 1 để chọn mức dễ.\n";
    cout << "Nhập 2 để chọn mức khó.\n";
    cout << "Xin mời nhập lựa chọn : ";
    cin >> mode;
    Person *player;  
    player = get_character1();
    cout << player->get_name() << " đi trước.\n";
    int turn = 1;
    int random_value = rand() % 2;
    bool character1_first = random_value == 1 ? true : false;
    if (mode == 2){
        while (1) {
            if (turn % 2 == 1) {
                cout << "Mời " << player->get_name() << " nhập tọa độ quân cờ: ";
                int x, y;   
                cin >> x >> y;    
                add_stone(x, y, character1_first);
                render();
            } 
            else {
                cout << "Đến lượt bot nhập tọa độ quân cờ !!! ";
                int x, y;
                x = Tim_Kiem_NuocDi_1().get_x();
                y = Tim_Kiem_NuocDi_1().get_y();
                cout << x << " " << y << endl;
                add_stone(x, y, character1_first);
                cout << endl;
                render();
            }
            turn ++;
            if (check_win() == -1) continue;
            set_winner_PvE();
            finish_game();
            break;
        }
    }
    else {
        while (1) {
            if (turn % 2 == 1) {
                cout << "Mời " << player->get_name() << " nhập tọa độ quân cờ: ";
                int x, y;   
                cin >> x >> y;    
                add_stone(x, y, character1_first);
                render();
            } 
            else {
                cout << "Đến lượt bot nhập tọa độ quân cờ !!! ";
                int x, y;
                x = Tim_Kiem_NuocDi_2().get_x();
                y = Tim_Kiem_NuocDi_2().get_y();
                cout << x << " " << y << endl;
                add_stone(x, y, character1_first);
                cout << endl;
                render();
            }
            turn ++;
            if (check_win() == -1) continue;
            set_winner_PvE();
            finish_game();
            break;
        }
    }
    
    
}