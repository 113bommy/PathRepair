#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T = int>
T rd() {
  T res = 0;
  T fg = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') fg = -1;
    ch = getchar();
  }
  while (isdigit(ch)) res = (res << 1) + (res << 3) + (ch ^ 48), ch = getchar();
  return res * fg;
}
const int N = 300010;
template <typename T = int>
struct Fenwick {
  const int n;
  T t[N];
  Fenwick(int n) : n(n) { memset(t, 0, sizeof t); }
  void add(int k, T v) {
    for (; k <= n; k += k & -k) t[k] += v;
  }
  T qsum(int k) {
    T v = 0;
    for (; k; k -= k & -k) v += t[k];
    return v;
  }
  T get(int l, int r) { return qsum(r) - qsum(l - 1); }
};
int n;
int a[N];
int main() {
  n = rd();
  for (int i = 1; i <= n; i++) a[i] = rd();
  Fenwick<ll> f1(300000), f2(300000);
  ll pre = 0, ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += a[i] * (i - 1);
    ans += pre;
    ans -= f1.qsum(a[i]);
    for (int j = a[i]; j <= 300000; j += a[i]) {
      int l = j, r = min(300000, j + a[i] - 1);
      ans -= f2.get(l, r) * j;
      f1.add(l, a[i]);
    }
    f2.add(a[i], 1);
    pre += a[i];
    printf("%lld%c", ans, " \n"[i == n]);
  }
  return 0;
}
