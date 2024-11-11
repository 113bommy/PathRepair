#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c = 0, i, j, t, k, lie, m, n, o, x, y, z;
  scanf("%lld", &t);
  while (t--) {
    string s[9];
    for (i = 0; i < 9; i++) cin >> s[i];
    for (i = 0; i < 9; i++) {
      for (j = 0; j < 9; j++) {
        if (i == 0 && j == 0 || i == 1 && j == 3 || i == 2 && j == 6 ||
            i == 3 && j == 1 || i == 4 && j == 4 || i == 5 && j == 7 ||
            i == 6 && j == 2 || i == 7 && j == 5 || i == 8 && j == 8) {
          if (s[i][j] == '1')
            s[i][j] = '2';
          else
            s[i][j] = '1';
        }
      }
    }
    for (i = 0; i < 9; i++) cout << s[i] << "\n";
  }
  return 0;
}
