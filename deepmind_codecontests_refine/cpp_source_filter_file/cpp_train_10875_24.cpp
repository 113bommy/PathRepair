#include <bits/stdc++.h>
using namespace std;
int mp[55][55], m, n;
int h[55][55];
int find(int p, int q) {
  if ((p > n) || (q > m)) return 100000000;
  int i, j, k, t, res = 100000000;
  for (i = p; i <= n; i++)
    for (j = q; j <= m; j++) {
      t = h[i][j] - h[i - p][j] - h[i][j - q] + h[i - p][j - q];
      if (res > t) res = t;
    }
  return res;
}
int main() {
  int i, j, k, tmp, ans, a, b;
  cin >> n >> m;
  memset(h, 0, sizeof(h));
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      cin >> k;
      h[i][j] = h[i][j - 1] + h[i - 1][j] - h[i - 1][j - 1];
      if (k) h[i][j]++;
    }
  cin >> a >> b;
  ans = find(a, b);
  tmp = find(b, a);
  if (ans > tmp) ans = tmp;
  cout << tmp << endl;
  return 0;
}
