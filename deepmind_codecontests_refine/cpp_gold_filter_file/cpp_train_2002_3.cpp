#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
int ar[MAXN][MAXN], star[MAXN][MAXN];
int main() {
  int n, m, t;
  char a;
  cin >> n >> m >> t;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf(" %c", &a);
      ar[i][j] = a - '0';
    }
  for (int i = 2; i < n; i++)
    for (int j = 2; j < m; j++)
      if (ar[i][j] && ar[i - 1][j] && ar[i][j - 1] && ar[i + 1][j] &&
          ar[i][j + 1])
        star[i][j] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      star[i][j] += star[i][j - 1] + star[i - 1][j] - star[i - 1][j - 1];
  long long tmp, fl, res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      tmp = 1;
      for (int k = j - 2; k >= 1; k--) {
        fl = 1;
        while (fl && tmp < i - 1) {
          fl = 0;
          if (star[i - 1][j - 1] - star[tmp][j - 1] - star[i - 1][k] +
                  star[tmp][k] >=
              t)
            tmp++, fl = 1;
        }
        res += tmp - 1;
      }
    }
  }
  cout << res << endl;
  return 0;
}
