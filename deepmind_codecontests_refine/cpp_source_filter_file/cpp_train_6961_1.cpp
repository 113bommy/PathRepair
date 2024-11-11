#include<iostream>
using namespace std;
int main() {
	char c[10][10];
    while (cin>>c[0][0]){
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                if(i==0&&j==0)continue;
                cin >> c[i][j];
        int a, b;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (c[i][j] == '1') {
                    a = i;
                    b = j;
                    goto C;
                }
            }
        }
    C:
        if (c[a][b + 1] == '1') {
            if (c[a + 1][b] == '1') {
                if (c[a + 1][b + 1] == '1')
                    cout << 'A';
                else cout << 'G';
            }
            else {
                if (c[a + 1][b + 1] == '1')
                    cout << 'E';
                else cout << 'C';
            }
        }
        else if (c[a + 1][b + 1] == '1')
            cout << 'F';
        else if (c[a + 1][b - 1] == '1')
            cout << 'D';
        else cout << 'B';
        cout << endl;
    }
    return 0;
}