#include <bits/stdc++.h>
using namespace std;
template <typename _T>
void read(_T &x) {
  _T f = 1;
  x = 0;
  char s = getchar();
  while (s > '9' || s < '0') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = (x << 3) + (x << 1) + (s ^ 48);
    s = getchar();
  }
  x *= f;
}
pair<long long, long long> c[500005], sum[500005];
long long id[500005], a[500005], b[500005], ans[500005];
long long n, m;
signed main() {
  read(n);
  read(m);
  for (long long i = 1; i <= n; i++) {
    read(a[i]);
    read(b[i]);
    c[i] = make_pair(a[i] - b[i], i);
  }
  sort(c + 1, c + n + 1);
  for (long long i = 1; i <= n; i++) id[c[i].second] = i;
  sum[0] = sum[n + 1] = make_pair(0, 0);
  for (long long i = 1; i <= n; i++)
    sum[i].first = sum[i - 1].first + a[c[i].second];
  for (long long i = n; i > 0; i--)
    sum[i].second = sum[i + 1].second + b[c[i].second];
  for (long long i = 1; i <= n; i++)
    ans[i] = a[i] * (n - id[i]) + b[i] * (id[i] - 1) + sum[id[i] - 1].first +
             sum[id[i] + 1].second;
  for (long long i = 1; i <= m; i++) {
    long long x, y, tmp;
    read(x);
    read(y);
    tmp = id[x] < id[y] ? a[x] + b[y] : a[y] + b[x];
    ans[x] -= tmp;
    ans[y] -= tmp;
  }
  for (long long i = 1; i <= n; i++) printf("%d ", ans[i]);
  return 0;
}
