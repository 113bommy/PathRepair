#include <bits/stdc++.h>
using namespace std;
const int Size = 1024;
const int mod = 1e9 + 7;
const int mod2 = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 15;
const int base = 307;
long long a[maxn];
long long pos[50][maxn];
long long m;
long long dfs(long long n, long long t) {
  if (t == 0 || n == 0) return 0;
  long long f1 = 0, f2 = 0;
  long long tot = 0;
  for (long long i = 1ll; n >= i; i++) {
    if ((a[pos[t][i]] >> (t - 1ll)) & 1ll) {
      pos[t - 1][++tot] = pos[t][i];
      f1 = 1;
    }
  }
  long long ans1 = dfs(tot, t - 1ll);
  tot = 0ll;
  for (long long i = 1ll; n >= i; i++) {
    if (((a[pos[t][i]] >> (t - 1ll)) & 1ll) == 0ll) {
      pos[t - 1ll][++tot] = pos[t][i];
      f2 = 1;
    }
  }
  long long ans2 = dfs(tot, t - 1);
  if (f1 == 1 && f2 == 1)
    return (1 << (t - 1)) + min(ans1, ans2);
  else
    return min(ans1, ans2);
}
int main() {
  long long n;
  scanf("%lld", &n);
  long long mx = 0;
  for (long long i = 1; n >= i; i++) {
    scanf("%lld", &a[i]);
    mx = max(mx, a[i]);
  }
  n = unique(a + 1, a + n + 1) - a - 1;
  long long t = 0;
  while (mx) {
    t++;
    mx >>= 1;
  }
  for (long long i = 1; n >= i; i++) pos[t][i] = i;
  m = t;
  printf("%lld\n", dfs(n, t));
  return 0;
}
