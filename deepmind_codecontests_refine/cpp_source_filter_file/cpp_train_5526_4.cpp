#include <iostream>
using namespace std;

int D[6];
void spin(char c)
{
    if(c=='E'){
        swap(D[0],D[3]);swap(D[3],D[5]);swap(D[5],D[2]);
    }
    else if(c=='W'){
        swap(D[0],D[2]);swap(D[2],D[5]);swap(D[5],D[3]);
    }
    else if(c=='S'){
        swap(D[0],D[1]);swap(D[0],D[4]);swap(D[4],D[5]);
    }
    else if(c=='N'){
        swap(D[0],D[1]);swap(D[1],D[5]);swap(D[5],D[4]);
    }
}


int main() {
    //?????¢???????????????
    for (int i = 0; i < 6 ; ++i) {
        cin >> D[i];
    }
    int Dice[6];

    //?????????????????????
    for (int i = 0; i < 6 ; ++i) {
        cin >> Dice[i];
    }

    bool ans = 0;

    //?????¢???????????????
    char SWS[10]={"SSSSWSSSS"};
    for(int i=0;i<10;i++){
        if(D[1]==Dice[1])break;
        spin(SWS[i]);
    }
    //?????¢???????????????
    for(int j=0;j<4; ++j){
        if(D[0] == Dice[0]){
            if(D[2]==Dice[2] && D[3]==Dice[3] &&D[4]==Dice[4] && D[5]==Dice[5])
                ans = 1;
        }
        spin('W');
        }
    
    //??????
    if (ans == 1){
        cout << "Yes" <<endl;
    }else{
        cout << "No" << endl;
    }

    return 0;