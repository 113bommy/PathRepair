#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("2")
#pragma GCC optimize("inline")
using namespace std;
template <class T>
inline void read(T &x) {
  int f = 0, ch = 0;
  x = 0;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = 1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
  if (f) x = -x;
}
const long long N = 500005;
map<long long, long long> mp;
long long a[N], b[N], A[N], B[N], n, m, Y1, Y2, ans = 0;
signed main() {
  read(n), read(Y1);
  for (long long i = 1; i <= n; i++) read(a[i]), mp[b[i]]++;
  read(m), read(Y2);
  for (long long i = 1; i <= m; i++) read(b[i]), mp[a[i]]++;
  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);
  for (long long k = 1; k <= (long long)(1e9); k <<= 1) {
    for (long long i = 1; i <= n; i++) A[i] = a[i] % (2ll * k);
    for (long long i = 1; i <= m; i++) B[i] = b[i] % (2ll * k);
    sort(A + 1, A + n + 1);
    sort(B + 1, B + m + 1);
    long long lst = 0;
    for (long long i = 1; i <= n; i = lst + 1) {
      lst = i;
      while (A[lst] == A[lst + 1] && lst < n) lst++;
      long long v = (A[i] + k) % (k << 1ll);
      ans = max(ans, lst - i + 1 +
                         (long long)(upper_bound(B + 1, B + m + 1, v) -
                                     lower_bound(B + 1, B + m + 1, v)));
    }
    for (long long i = 1; i <= m; i = lst + 1) {
      lst = i;
      while (B[lst] == B[lst + 1] && lst < m) lst++;
      ans = max(ans, lst - i + 1);
    }
  }
  static map<long long, long long>::iterator it;
  for (it = mp.begin(); it != mp.end(); it++) ans = max(ans, it->second);
  cout << ans;
  return 0;
}
