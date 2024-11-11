#include <bits/stdc++.h>
using namespace std;
const int INT = int(1e5) + 5;
const int inf = int(1e9) + 7;
inline void boost() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int used[6][6];
int main() {
  boost();
  string a;
  cin >> a;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == '0') {
      if (used[1][1] + used[2][1] == 2) {
        used[1][1] = 0;
        used[2][1] = 0;
        cout << 3 << " " << 1 << endl;
      } else {
        used[1][1] = 1;
        used[2][1] = 1;
        cout << 1 << " " << 1 << endl;
      }
    } else {
      if (used[1][4] + used[2][4] + used[3][4] == 3) {
        for (int j = 1; j <= 3; j++) {
          used[j][4] = 0;
          used[j][3] = 0;
        }
        cout << 4 << " " << 3 << endl;
      } else if (used[1][4] + used[2][4] == 2) {
        used[3][4] = 1;
        used[3][3] = 1;
        cout << 3 << " " << 3 << endl;
      } else if (used[1][4] == 1) {
        used[2][3] = 1;
        used[2][4] = 1;
        cout << 2 << " " << 4 << endl;
      } else {
        used[1][3] = 1;
        used[1][4] = 1;
        cout << 1 << " " << 3 << endl;
      }
    }
  }
  return 0;
}
