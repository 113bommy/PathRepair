#include <bits/stdc++.h>
using namespace std;
char arr[100][100];
int n, m, k, i, j, aa = 100, bb = 100;
int main() {
  int n = 8;
  for (i = 1; i <= 8; i++)
    for (j = 1; j <= 8; j++) cin >> arr[i][j];
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (arr[i][j] == 'W') {
        int a = 0;
        for (k = i + 1; k <= n; k++)
          if (arr[k][j] != '.')
            a = 100;
          else
            a++;
        aa = min(a, aa);
      }
      if (arr[i][j] == 'B') {
        int a = 0;
        for (k = i - 1; k >= 1; k--) {
          if (arr[k][j] != '.')
            a = 100;
          else
            a++;
        }
        bb = min(a, bb);
      }
    }
  }
  if (bb >= aa)
    cout << "A" << '\n';
  else
    cout << "B" << '\n';
}
