#include <bits/stdc++.h>
using namespace std;
template <class T>
int getbit(int i, T X) {
  return (X & (1 << (i - 1)));
}
template <class T>
T onbit(int i, T X) {
  return (X | (1 << (i - 1)));
}
template <class T>
T offbit(int i, T X) {
  return (X | (1 << (i - 1)) - (1 << (i - 1)));
}
template <class T>
T sqr(T x) {
  return (x * x);
}
template <class T>
T cube(T x) {
  return (x * x * x);
}
template <class T>
T gcd(T a, T b) {
  T r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
int csx[4] = {0, 0, -1, 1};
int csy[4] = {-1, 1, 0, 0};
const int MOD = 1000000007;
const int infi = 1e9;
const int maxn = 2e5 + 5;
const int maxV = 1e6 + 5;
int n, a[maxn + 5], f[2 * maxV + 5], d[maxV];
void enter() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
}
void solve() {
  sort(a + 1, a + n + 1);
  n = unique(a + 1, a + n + 1) - &a[1];
  memset(d, 0, sizeof(d));
  for (int i = 1; i <= n; i++) d[a[i]] = 1;
  f[0] = 0;
  for (int i = 1; i <= 2 * a[n] + 5; i++) {
    f[i] = f[i - 1];
    if (d[i]) f[i] = i;
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 2 * a[i]; j <= 2 * a[n]; j += a[i]) {
      if (f[j - 1] >= a[i]) {
        res = max(res, f[j - 1] % a[i]);
      }
    }
  }
  cout << res;
}
int main() {
  enter();
  solve();
  return 0;
}
