#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    vector<string> suduko(9);
    for (int i = 0; i < 9; ++i) {
      cin >> suduko[i];
    }
    suduko[0][0] = suduko[0][1];
    suduko[1][3] = suduko[1][4];
    suduko[2][6] = suduko[2][7];
    suduko[3][2] = suduko[3][3];
    suduko[4][4] = suduko[4][5];
    suduko[5][7] = suduko[5][8];
    suduko[6][2] = suduko[6][1];
    suduko[7][5] = suduko[7][4];
    suduko[8][8] = suduko[8][7];
    for (int i = 0; i < 9; ++i) {
      cout << suduko[i] << endl;
    }
  }
}
