#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
char ch[30][30];
int d[1500000], a[30][30], bit[30][30], cost[30][30];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) cin >> ch[i][j];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) cin >> a[i][j];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      int Max = 0;
      for (int k = 1; k <= n; ++k)
        if (ch[i][j] == ch[k][j]) {
          cost[i][j] += a[k][j];
          Max = max(Max, a[k][j]);
          bit[i][j] |= (1 << k - 1);
        }
      cost[i][j] -= Max;
    }
  int e = (1 << n);
  for (int i = 1; i < e; ++i) d[i] = INF;
  for (int i = 0; i < e - 1; ++i) {
    if (d[i] >= INF) continue;
    int k;
    for (int j = 0; j < n; ++j)
      if ((i & (1 << j)) == 0) {
        k = j;
        break;
      }
    for (int j = 1; j <= m; ++j) {
      d[i | (1 << k)] = min(d[i | (1 << k)], d[i] + a[k + 1][j]);
      d[i | bit[k + 1][j]] = min(d[i | bit[k + 1][j]], d[i] + cost[k + 1][j]);
    }
  }
  cout << d[e - 1] << endl;
  return 0;
}
