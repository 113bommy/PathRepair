#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const long long inf = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int mod = 1e9 + 7;
inline long long mul(long long x, long long y, long long mod) {
  long long res = (x * y - (long long)(long double)(x / mod * y + 1e-8) * mod);
  return res < 0 ? res + mod : res;
}
long long qPow(long long base, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = (res * base);
    base = (base * base);
    n >>= 1;
  }
  return res;
}
int n;
pair<int, int> a[maxn], b[maxn];
bool cmp(pair<int, int> x, pair<int, int> y) {
  if (x.first != y.first) return x.first > y.first;
  return x.second < y.second;
}
bool cmp1(pair<int, int> x, pair<int, int> y) {
  if (x.second != y.second) return x.second < y.second;
  return x.first > y.first;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i].first, &a[i].second);
    b[i] = a[i];
  }
  sort(a + 1, a + 1 + n, cmp);
  sort(b + 1, b + 1 + n, cmp1);
  int ans = 0, l = 0, r = 0x3f3f3f3f;
  for (int i = 2; i <= n; i++) {
    if (a[i].first >= l && a[i].second <= r)
      l = a[i].first, r = a[i].second;
    else if (a[i].first >= l && a[i].first <= r)
      l = a[i].first, r = min(a[i].second, r);
    else if (a[i].second >= l && a[i].second <= r)
      l = max(a[i].first, l), r = a[i].second;
    else if (l >= a[i].first && r <= a[i].second)
      ;
    else {
      l = 0, r = 0;
    }
  }
  ans = max(ans, r - l);
  l = 0, r = 0x3f3f3f3f;
  for (int i = 2; i <= n; i++) {
    if (b[i].first >= l && b[i].second <= r)
      l = b[i].first, r = b[i].second;
    else if (b[i].first >= l && b[i].first <= r)
      l = b[i].first, r = min(b[i].second, r);
    else if (b[i].second >= l && b[i].second <= r)
      l = max(b[i].first, l), r = b[i].second;
    else if (l >= b[i].first && r <= b[i].second)
      ;
    else {
      l = 0, r = 0;
    }
  }
  ans = max(ans, r - l);
  printf("%d\n", ans);
  return 0;
}
