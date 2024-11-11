#include <bits/stdc++.h>
using namespace std;
int low[50005], col[50005];
void solve() {
  memset(low, 0, sizeof(low));
  memset(col, 0, sizeof(col));
  int n, m, maxn(0), maxm(0), maxx(0), maxy(0);
  cin >> n >> m;
  map<int, int> maps[n + 10];
  char x;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> x;
      if (x == '*') {
        low[i]++, col[j]++;
        maps[i][j] = 1;
      }
    }
  int sum = 0x7ffff;
  for (int i = 0; i < n; i++) {
    if (maxn <= low[i]) {
      maxn = low[i], maxx = i;
      for (int j = 0; j < m; j++) {
        if (maxm < col[j] || maxm == col[j] && maps[i].count(j) == 1)
          maxm = col[j], maxy = j;
      }
    }
    sum = min(sum, m + n - maxn - maxm - (maps[maxx].count(maxy) != 1));
  }
  cout << sum << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
