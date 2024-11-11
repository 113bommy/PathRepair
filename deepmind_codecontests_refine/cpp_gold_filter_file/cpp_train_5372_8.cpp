#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
int n, k, s[100009 << 2], arr[100009];
int mod(long long x) { return (x % k); }
void build(int nd, int x, int y) {
  if (x == y) {
    s[nd] = arr[x] % k;
    return;
  }
  int mid = (x + y) >> 1;
  build(nd << 1, x, mid);
  build(nd << 1 | 1, mid + 1, y);
  s[nd] = mod(s[nd << 1] * 1LL * s[nd << 1 | 1]);
}
int tap(int l, int r, int nd, int x, int y) {
  if (l > y or x > r) return 1;
  if (l <= x and y <= r) return s[nd];
  int mid = (x + y) >> 1;
  return mod(tap(l, r, nd << 1, x, mid) * 1LL *
             tap(l, r, nd << 1 | 1, mid + 1, y));
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", arr + i);
  build(1, 1, n);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int st = i, en = n;
    while (st + 1 < en) {
      int mid = (st + en) >> 1;
      if (!tap(i, mid, 1, 1, n))
        en = mid;
      else
        st = mid;
    }
    if (tap(i, en, 1, 1, n))
      ans += n - en;
    else if (tap(i, st, 1, 1, n))
      ans += n - st;
    else
      ans += n - i + 1;
  }
  printf("%lld\n", ans);
  return 0;
}
