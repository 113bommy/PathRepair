#include <bits/stdc++.h>
using namespace std;
template <class T>
bool setmax(T &_a, T _b) {
  if (_b > _a) {
    _a = _b;
    return true;
  }
  return false;
}
template <class T>
bool setmin(T &_a, T _b) {
  if (_b < _a) {
    _a = _b;
    return true;
  }
  return false;
}
template <class T>
T gcd(T _a, T _b) {
  return _b == 0 ? _a : gcd(_b, _a % _b);
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  static int a[100000];
  memset(a, 0, sizeof(a));
  for (int i = int(0); i <= int((n)-1); ++i) {
    static char s[100010];
    scanf("%s", s);
    for (int j = int(0); j <= int((m)-1); ++j)
      if (s[j] == '1') a[j] |= (1 << i);
  }
  static int f[21][1 << 20];
  memset(f, 0, sizeof(f));
  for (int j = int(0); j <= int((m)-1); ++j) f[0][a[j]] = 1;
  for (int k = int(0); k <= int((n)-1); ++k) {
    for (int i = int(n); i >= int(1); --i)
      for (int s = int(0); s <= int((1 << n) - 1); ++s)
        f[i][s] += f[i - 1][s ^ (1 << k)];
  }
  int ans = 1 << 30;
  for (int s = int(0); s <= int((1 << n) - 1); ++s) {
    int cur = 0;
    for (int i = int(0); i <= int(n); ++i) cur += min(i, n - i) * f[i][s];
    setmin(ans, cur);
  }
  printf("%d\n", ans);
  return 0;
}
