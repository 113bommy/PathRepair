#include <bits/stdc++.h>
using namespace std;
const int MX = 400000 + 10;
int n, m, mm, k, ans, t;
long long d[MX][64];
long long a[MX], sum[MX];
long long maxx(long long x1, long long x2) { return x1 < x2 ? x2 : x1; }
void init() {
  mm = n - k + 1;
  for (int i = 1; i <= mm; ++i) {
    d[i][0] = sum[i];
  }
  for (int j = 1; (1 << j) <= mm; ++j) {
    for (int i = 1; i + j - 1 <= mm; ++i) {
      d[i][j] = maxx(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
    }
  }
}
long long RMQ(int l, int r) {
  int k = 0;
  while (1 << (k + 1) <= r - l + 1) k++;
  return maxx(d[l][k], d[r - (1 << k) + 1][k]);
}
int main() {
  ios::sync_with_stdio(0);
  int i, j, s, e;
  long long ma, tmp;
  cin >> n >> k;
  sum[1] = 0;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    if (i <= k) sum[1] += a[i];
  }
  for (i = 2; i <= n - k + 1; i++) {
    sum[i] = sum[i - 1] - a[i - 1] + a[i + k - 1];
  }
  init();
  m = n - 2 * k + 1;
  ma = -1;
  for (i = 1; i <= m; i++) {
    tmp = sum[i] + RMQ(i + k, n - k + 1);
    if (tmp > ma) {
      s = i;
      ma = tmp;
    }
  }
  tmp = ma - sum[s];
  for (i = s + k; i <= n - k + 1; i++) {
    if (sum[i] == tmp) {
      e = i;
      break;
    }
  }
  cout << s << " " << e << endl;
  return 0;
}
