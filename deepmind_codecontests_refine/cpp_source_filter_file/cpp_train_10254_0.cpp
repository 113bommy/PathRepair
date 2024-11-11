#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5, inf = 1e9 + 7;
long long n, k, m, id = 0, z = 31;
long long A[2][N], p[N], in[N];
inline long long fpow(long long n, long long k, long long p = inf) {
  long long r = 1;
  for (; k; k >>= 1) {
    if (k & 1) r = r * n % p;
    n = n * n % p;
  }
  return r;
}
inline long long inv(long long a, long long p = inf) {
  return fpow(a, p - 2, p);
}
inline long long h(long long first, long long l, long long r) {
  return ((A[first][r] - A[first][l - 1]) * in[l] % inf + inf) % inf;
}
bool dfs(long long l1, long long r1, long long l2, long long r2) {
  if (h(0, l1, r1) == h(1, l2, r2)) return 1;
  if ((r1 - l1) & 1) {
    if (dfs(l1, (l1 + r1 - 1) / 2, (l2 + r2) / 2 + 1, r2) &&
        dfs((l1 + r1) / 2 + 1, r1, l2, (l2 + r2 - 1) / 2))
      return 1;
    if (dfs(l1, (l1 + r1 - 1) / 2, l2, (l2 + r2 - 1) / 2) &&
        dfs((l1 + r1) / 2 + 1, r1, (l2 + r2) / 2 + 1, r2))
      return 1;
  }
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long i, j, a, b, ans = 0;
  string s, t;
  cin >> s >> t;
  n = (long long)s.size();
  p[0] = 1;
  in[0] = 1;
  for (i = 0; i < n; i++) {
    p[i + 1] = p[i] * 31 % inf;
    in[i + 1] = inv(p[i + 1]);
    A[0][i + 1] = (A[0][i] + p[i] * (s[i] - 'a' + 1)) % inf;
    A[1][i + 1] = (A[1][i] + p[i] * (t[i] - 'a' + 1)) % inf;
  }
  if (dfs(1, n, 1, n))
    cout << "YES\n";
  else
    cout << "NO\n";
}
