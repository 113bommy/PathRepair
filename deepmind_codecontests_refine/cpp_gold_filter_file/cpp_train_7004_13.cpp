#include <bits/stdc++.h>
using namespace std;
int const N = 200200;
long long const mod = 998244353;
int pos[N], b[N];
int seq[N];
long long powMod(long long a, long long b, long long c) {
  long long ret = 1 % c;
  for (; b; a = a * a % c, b >>= 1)
    if (b & 1) ret = ret * a % c;
  return ret;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= (n); ++i) {
      int x;
      scanf("%d", &x);
      pos[x] = i;
    }
    for (int i = 1; i <= (m); ++i) {
      scanf("%d", &b[i]);
    }
    for (int i = 1; i <= (n + 1); ++i) seq[i] = 0;
    for (int i = 1; i <= (m); ++i) {
      seq[pos[b[i]]] = i;
    }
    int c2 = 0;
    bool ok = 1;
    for (int i = 1; i <= (n); ++i) {
      int t = 1;
      if (i > 1 && i < n) ++t;
      if (seq[i] > 0) {
        if (seq[i - 1] > seq[i]) --t;
        if (seq[i + 1] > seq[i]) --t;
        if (t == 0) {
          ok = 0;
          break;
        }
        if (t == 2) ++c2;
      }
    }
    if (!ok)
      puts("0");
    else
      printf("%lld\n", powMod(2, c2, mod));
  }
  return 0;
}
