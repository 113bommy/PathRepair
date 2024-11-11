#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    f |= ch == '-';
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return f ? -x : x;
}
const int base = 23, mod = (int)((1ll << 31) - 1);
int pre[5000005], nxt[5000005], f[5000005], len, powb[5000005] = {1}, ans = 0;
char s[5000005];
inline void init() {
  for (register int i = 1; i <= 5000000; ++i)
    (powb[i] = powb[i - 1] * base) >= mod ? powb[i] %= mod : 0;
}
inline bool is_level(int l, int r) {
  return (pre[r] - pre[l - 1]) * powb[len - r - l + 1] == (nxt[l] - nxt[r + 1]);
}
int main() {
  init();
  scanf("%s", s + 1);
  len = strlen(s + 1);
  for (register int i = 1; i <= len; ++i)
    pre[i] = ((pre[i - 1] + s[i]) * powb[i - 1]) % mod;
  for (register int i = len; i >= 1; --i)
    nxt[i] = ((nxt[i + 1] + s[i]) * powb[len - i]) % mod;
  for (register int i = 1; i <= len; ans += f[i], ++i)
    if (is_level(1, i)) f[i] = f[i >> 1] + 1;
  cout << ans;
  return 0;
}
