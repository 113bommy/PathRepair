#include <bits/stdc++.h>
using namespace std;
int x[2000][2000], n, m, up[2000][2000], down[2000][2000];
int l[2000][2000], r[2000][2000];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      char a;
      cin >> a;
      x[i][j] = (a - 'a');
      up[i][j] = down[i][j] = 1;
      l[i][j] = r[i][j] = 1;
    }
  for (int i = 0; i < m; i++)
    for (int j = 1; j < n; j++)
      up[j][i] = (x[j - 1][i] == x[j][i]) ? up[j - 1][i] + 1 : 1;
  for (int i = 0; i < m; i++)
    for (int j = n - 2; j >= 0; j--)
      down[j][i] = (x[j + 1][i] == x[j][i]) ? down[j + 1][i] + 1 : 1;
  for (int i = 1; i < m; i++)
    for (int j = 1; j < n; j++)
      l[j][i] = (x[j][i] == x[j][i - 1])
                    ? min(l[j][i - 1] + 1, min(up[j][i], down[j][i]))
                    : 1;
  for (int i = m - 2; i >= 0; i--)
    for (int j = 1; j < n; j++)
      r[j][i] = (x[j][i] == x[j][i + 1])
                    ? min(r[j][i + 1] + 1, min(up[j][i], down[j][i]))
                    : 1;
  long long res = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) res += min(l[i][j], r[i][j]);
  cout << res;
  return 0;
}
