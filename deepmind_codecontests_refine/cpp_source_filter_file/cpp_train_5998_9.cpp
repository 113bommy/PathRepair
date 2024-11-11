#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 10;
const int mod = 1e9 + 7;
int n, m;
int fpow(int base, int top) {
  int ret = 1;
  for (; top; top >>= 1) {
    if (top & 1) ret = 1ll * ret * base % mod;
    base = 1ll * base * base % mod;
  }
  return ret;
}
inline void init(void) { scanf("%d%d", &n, &m); }
inline int Div(int x) { return fpow(x, mod - 2); }
inline void work(void) {
  int ans = 1;
  ans = 1ll * ans * (m + 1 - n) * Div(m + 1) % mod;
  ans = 1ll * ans * fpow(2 * (m + 1), n) % mod;
  printf("%d", ans);
}
int main() {
  init();
  work();
  return 0;
}
