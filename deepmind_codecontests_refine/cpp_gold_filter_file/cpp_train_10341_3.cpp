#include <bits/stdc++.h>
template <typename Tp>
inline void read(Tp &x) {
  x = 0;
  bool f = true;
  char ch = getchar();
  for (; ch < '0' || ch > '9'; ch = getchar()) f ^= ch == '-';
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + (ch ^ 48);
  x = f ? x : -x;
}
const int Mod = 1e9 + 9;
int main() {
  int n;
  read(n);
  if (n == 2) return printf("10\n"), 0;
  int ans = 2, cur = 1, tmp = 1;
  for (int i = 2; i <= n / 2; ++i) {
    ans = (ans + 4LL * tmp) % Mod;
    cur = (2 * cur + 3) % Mod;
    tmp = 1LL * cur * tmp % Mod;
  }
  ans = (2LL * ans * ans + 2) % Mod;
  printf("%d\n", ans);
  return 0;
}
