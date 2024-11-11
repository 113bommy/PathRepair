#include <iostream>
#include <vector>
using namespace std;

class Dice{
public:
    long r[6];
    Dice(){};
    void roll(long a, long b, long c, long d){
        swap(r[a], r[b]);
        swap(r[b], r[c]);
        swap(r[c], r[d]);
    }
    void spinW(){roll(0, 2, 5, 3);}
    void spinN(){roll(0, 1, 5, 4);}
};

int main() {
    int ans = 0;
    int n;
    cin >> n;
    vector<Dice> D(n);
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < 6; j++) cin >> D[i].r[j];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1 ; j < n ; j++) {
            char SWS[8]={"NNNWNNN"};
            for (int k = 0; k < 8; k++){
                if (D[i].r[1] == D[j].r[1]) break;
                if (SWS[k] == 'W') D[j].spinW();
                else D[j].spinN();
            }
            for (int k = 0; k < 4; k++){
                if (D[i].r[0] == D[j].r[0]){
                    if (D[i].r[1] == D[j].r[1] && D[i].r[2] == D[j].r[2] && D[i].r[3]==D[j].r[3] && D[i].r[4] == D[j].r[4] && D[i].r[5] == D[j].r[5])
                        ans++;
                }
                D[j].spinW();
            }
        }
    }

    if (ans == 0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}