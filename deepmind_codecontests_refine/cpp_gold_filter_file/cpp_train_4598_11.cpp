#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7, M = 2e6;
const long long mod = 1e9 + 7;
inline int read() {
  int ret = 0;
  char ch = getchar();
  bool f = 1;
  for (; !isdigit(ch); ch = getchar()) f ^= !(ch ^ '-');
  for (; isdigit(ch); ch = getchar()) ret = (ret << 1) + (ret << 3) + ch - 48;
  return f ? ret : -ret;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long ksm(long long a, long long b, long long mod) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}
long long inv2(long long a, long long mod) { return ksm(a, mod - 2, mod); }
int n;
int a[N], maxn[N], minn[N], arrmaxn[N], arrminn[N];
bool check(int x, bool in) {
  if (in) {
    int pre = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] >= x) continue;
      if (a[i] < pre) return false;
      pre = a[i];
    }
  } else {
    int pre = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] <= x) continue;
      if (a[i] < pre) return false;
      pre = a[i];
    }
  }
  return true;
}
int main() {
  int m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    maxn[i] = 0;
    minn[i] = n + 1;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    maxn[a[i]] = max(maxn[a[i]], i);
    minn[a[i]] = min(minn[a[i]], i);
  }
  int l = 1, r = m;
  while (l <= r) {
    long long mi = (l + r) / 2;
    if (check(mi, 1))
      l = mi + 1;
    else
      r = mi - 1;
  }
  int L = r;
  l = 1, r = m;
  while (l <= r) {
    long long mi = (l + r) / 2;
    if (check(mi, 0))
      r = mi - 1;
    else
      l = mi + 1;
  }
  int R = l;
  arrminn[m + 1] = n + 1;
  for (int i = 1; i <= L; i++) {
    arrmaxn[i] = max(arrmaxn[i - 1], maxn[i]);
  }
  for (int i = m; i >= R; i--) {
    arrminn[i] = min(arrminn[i + 1], minn[i]);
  }
  long long ans = 0;
  for (int i = R; i <= m; i++) {
    int it =
        lower_bound(arrmaxn + 1, arrmaxn + 1 + L, arrminn[i + 1]) - arrmaxn;
    if (it > L) it = L;
    ans += 1LL * min(it, i);
  }
  printf("%lld\n", ans);
  return 0;
}
