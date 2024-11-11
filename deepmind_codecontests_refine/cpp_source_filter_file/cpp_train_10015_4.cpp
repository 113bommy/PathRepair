#include <bits/stdc++.h>
using namespace std;
const int maxn = 133;
char a[maxn][maxn];
int d[maxn], n, m, k, g;
string hh = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
char nxt(int x, int y) {
  if (d[g] == 0) g++;
  if (a[x][y] == 'R') d[g]--;
  return hh[min(g - 1, k)];
}
void solve() {
  int cnt = 0;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'R') cnt++;
    }
  for (int i = 1; i <= k; i++) d[i] = 0;
  int it = 1;
  while (cnt > 0) {
    d[it]++;
    cnt--;
    it = (it % k) + 1;
  }
  g = 1;
  for (int i = 1; i <= n; i++)
    if (i % 2) {
      for (int j = 1; j <= m; j++) a[i][j] = nxt(i, j);
    } else {
      for (int j = m; j >= 1; j--) a[i][j] = nxt(i, j);
    }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cout << a[i][j];
    cout << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
