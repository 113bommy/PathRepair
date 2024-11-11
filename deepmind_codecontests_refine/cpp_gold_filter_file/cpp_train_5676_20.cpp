#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') f = -1;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}
const int maxn = 100010;
int n, A, cf, cm, val[maxn];
long long m, sum[maxn];
pair<int, int> a[maxn];
bool check(int x, long long left, int mr) {
  int l = 1, r = mr;
  while (l <= r) {
    int mid = l + r >> 1;
    if (a[mid].first <= x)
      l = mid + 1;
    else
      r = mid - 1;
  }
  l--;
  return (1ll * l * x - sum[l]) <= left;
}
int main() {
  n = read(), A = read(), cf = read(), cm = read();
  scanf("%I64d", &m);
  for (int i = 1; i <= n; i++) {
    a[i].first = read();
    a[i].second = i;
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i].first;
  long long ans = -1, _max, _min;
  for (int i = 0; i <= n; i++) {
    long long left = m - 1ll * i * A + (sum[n] - sum[n - i]);
    if (left < 0) break;
    int l = 0, r = A;
    while (l <= r) {
      int mid = l + r >> 1;
      if (check(mid, left, n - i))
        l = mid + 1;
      else
        r = mid - 1;
    }
    l--;
    long long tmp = 1ll * l * cm + 1ll * i * cf;
    if (tmp > ans) {
      ans = tmp;
      _max = i;
      _min = l;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i + _max > n)
      val[a[i].second] = A;
    else if (a[i].first < _min)
      val[a[i].second] = _min;
    else
      val[a[i].second] = a[i].first;
  }
  printf("%I64d\n", ans);
  for (int i = 1; i <= n; i++) printf("%d ", val[i]);
  return 0;
}
