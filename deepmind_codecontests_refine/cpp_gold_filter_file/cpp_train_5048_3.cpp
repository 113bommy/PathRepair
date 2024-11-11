#include <bits/stdc++.h>
using namespace std;
int x[2001], y[2001], id[2001];
int ucln(int x, int y) {
  if (!x) return y;
  if (!y) return x;
  if (x > y)
    return ucln(x % y, y);
  else
    return ucln(x, y % x);
}
bool cmp(int xx, int yy) {
  return ((x[xx] < x[yy]) || (x[xx] == x[yy] && y[xx] < y[yy]));
}
bool check(int i, int j) { return (x[i] == x[j] && y[i] == y[j]); }
int main() {
  int n;
  long long res = 0;
  cin >> n;
  int a[2001], b[2001];
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }
  int u;
  for (int i = 1; i <= n; i++) {
    int m = 0;
    for (int j = 1; j <= n; j++)
      if (j != i) {
        x[++m] = a[i] - a[j];
        y[m] = b[i] - b[j];
        if (x[m] < 0) {
          x[m] = -x[m];
          y[m] = -y[m];
        }
        if (!y[m]) x[m] = 1;
        if (!x[m]) y[m] = 1;
        u = ucln(x[m], abs(y[m]));
        x[m] /= u;
        y[m] /= u;
        id[m] = m;
      }
    if (m != 0) sort(id + 1, id + 1 + m, cmp);
    for (int j = 1; j <= m; j++)
      if (j == 1 || !check(id[j], id[j - 1])) {
        int t = j;
        while (t <= m && check(id[j], id[t])) t++;
        long long v = t - j + 1;
        res += (v - 1) * (n - v);
      }
  }
  res /= 6;
  cout << res;
}
