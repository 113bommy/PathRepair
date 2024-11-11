#include <bits/stdc++.h>
using namespace std;
int n, m, p, k;
bool swp;
int x[1020], y[1020], v[1020];
int a[1020][1020];
int main() {
  scanf("%d%d%d", &n, &m, &k);
  if ((n - m) & 1) {
    puts("0");
    return 0;
  }
  if (n < m) swp = 1, swap(n, m);
  for (int i = 1; i <= k; ++i) {
    scanf("%d%d%d", &x[i], &y[i], &v[i]);
    if (swp) swap(x[i], y[i]);
    a[x[i]][y[i]] = v[i];
  }
  scanf("%d", &p);
  int x = 0, flag = 1;
  for (int i = 1; i <= n; ++i) {
    int f = 0, cnt = 0;
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] != 0) ++cnt;
      if (a[i][j] == -1) f ^= 1;
    }
    if (cnt == m) {
      if (f == 0) {
        flag = 0;
        break;
      }
      ++x;
    }
  }
  if (!flag) {
    puts("0");
    return 0;
  }
  int t = n * m - n - m + 1 + x - k;
  x = 2;
  int ans = 1;
  while (t) {
    if (t & 1) ans = 1LL * ans * x % p;
    t >>= 1;
    x = 1LL * x * x % p;
  }
  cout << ans << endl;
  return 0;
}
