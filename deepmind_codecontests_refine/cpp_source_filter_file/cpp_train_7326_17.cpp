#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 7, mod = 1e9 + 7, inf = 1e9 + 7;
const long long linf = (long long)1e18 + 7;
const long double eps = 1e-15, pi = 3.141592;
const int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1},
          dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
int n, sz;
long long ans;
long long a[N], suff[N];
int t[N][2];
inline void add(long long x) {
  int v = 0;
  for (int i = 40; i >= 0; --i) {
    int type = ((x & (1LL << i)) > 0);
    if (!t[v][type]) t[v][type] = ++sz;
    v = t[v][type];
  }
}
inline long long get(long long x) {
  int v = 0;
  long long res = 0;
  for (int i = 40; i >= 0; --i) {
    int type = 1 - ((x & (1LL << i)) > 0);
    if (t[v][type])
      res += 1LL << i, v = t[v][type];
    else
      v = t[v][1 - type];
  }
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
  for (int i = n; i >= 1; --i) suff[i] = suff[i + 1] ^ a[i];
  long long pref = 0;
  add(0);
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, get(suff[i]));
    add(pref ^= a[i]);
  }
  cout << ans;
  exit(0);
}
