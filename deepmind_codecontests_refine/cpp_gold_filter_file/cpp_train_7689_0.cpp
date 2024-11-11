#include <bits/stdc++.h>

using namespace std;

int main() {

    char num[10][10];

    while(1) {

        for(int i = 0; i < 10; ++i) {
            if(!(cin >> num[0][i])) {
                return 0;
            }
            num[0][i] -= '0';
        }

        for(int i = 1; i < 10; ++i) {
            for(int j = 0; j < 10 - i; ++j) {
                num[i][j] = (num[i - 1][j] + num[i - 1][j + 1]) % 10;
            }
        }

        cout << (int)num[9][0] << endl;

    }

}