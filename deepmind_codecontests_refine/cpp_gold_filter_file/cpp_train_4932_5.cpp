#include <bits/stdc++.h>
using namespace std;
double f[55][55], res;
int a[55];
int n, P;
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cin >> P;
  for (int last = 1; last <= n; last++) {
    memset(f, 0, sizeof f);
    f[0][0] = 1;
    for (int curPerson = 1; curPerson <= n; curPerson++) {
      if (curPerson == last) continue;
      for (int i = P; i >= 0; i--)
        for (int j = n; j >= 0; j--) {
          if (f[i][j] == 0) continue;
          if (i + a[curPerson] <= P)
            f[i + a[curPerson]][j + 1] += f[i][j] / (n - j) * (j + 1);
        }
    }
    for (int i = P - a[last] + 1; i <= P; i++) {
      if (i <= 0) continue;
      for (int j = 1; j <= n; j++) {
        if (f[i][j] == 0) continue;
        res += f[i][j] / (n - j) * j;
      }
    }
    for (int i = 0; i <= P - a[last]; i++) {
      if (f[i][n - 1] == 0) continue;
      res += f[i][n - 1] * n;
    }
  }
  cout << fixed << setprecision(9) << res << "\n";
  return 0;
}
