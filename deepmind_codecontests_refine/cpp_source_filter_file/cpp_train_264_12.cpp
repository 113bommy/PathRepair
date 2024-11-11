#include <bits/stdc++.h>
using namespace std;
long long int A[100009];
bool visit[100009];
int main() {
  long long int t, T, n, m, i, j, k, ans, a, b, c, x, y, l, r;
  string second[5];
  while (cin >> second[0]) {
    ans = 0;
    cin >> second[1];
    cin >> second[2];
    cin >> second[3];
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        x = 0;
        for (k = j; k < j + 3; k++) {
          if (k > 3) {
            x = 0;
            break;
          }
          if (second[i][k] == 'x') x++;
          if (second[i][k] == 'o') x--;
        }
        if (x == 2) ans = 1;
        x = 0;
        for (k = i; k < i + 3; k++) {
          if (k > 3) {
            x = 0;
            break;
          }
          if (second[k][j] == 'x') x++;
          if (second[i][k] == 'o') x--;
        }
        if (x == 2) ans = 1;
        x = 0;
        for (k = 0; k < 3; k++) {
          if (i + k > 3 || j + k > 3) {
            x = 0;
            break;
          }
          if (second[i + k][j + k] == 'x') x++;
          if (second[i + k][j + k] == 'o') x--;
        }
        if (x == 2) ans = 1;
        x = 0;
        for (k = 0; k < 3; k++) {
          if (i + k > 3 || j - k < 0) {
            x = 0;
            break;
          }
          if (second[i + k][j - k] == 'x') x++;
          if (second[i + k][j - k] == 'o') x--;
        }
        if (x == 2) ans = 1;
        if (ans == 1) break;
      }
      if (ans == 1) break;
    }
    if (ans == 1)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
