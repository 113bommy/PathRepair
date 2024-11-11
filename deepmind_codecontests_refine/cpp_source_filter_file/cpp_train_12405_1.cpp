#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, hgs = 998244353;
int fac[N], n, ans = 1, in[N];
vector<int> v[N];
signed main() {
  int x, y;
  scanf("%d", &n);
  fac[0] = 1;
  for (register int i = (1); i <= (n); ++i) fac[i] = 1ll * fac[i - 1] * i;
  for (register int i = (2); i <= (n); ++i) {
    scanf("%d %d", &x, &y);
    in[x]++;
    in[y]++;
  }
  for (register int i = (1); i <= (n); ++i) ans = 1ll * ans * fac[in[i]] % hgs;
  ans = 1ll * ans * n % hgs;
  printf("%d\n", ans);
  return 0;
}
