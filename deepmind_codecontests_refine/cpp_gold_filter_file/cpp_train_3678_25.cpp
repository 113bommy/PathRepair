#include <bits/stdc++.h>
using namespace std;
long long ffa[200005], siz[200005];
long long getf(long long x) { return ffa[x] == x ? x : ffa[x] = getf(ffa[x]); }
long long n, m, P;
long long cnt, ans = 1;
int main() {
  ios::sync_with_stdio(false);
  long long u, v;
  cin >> n >> m >> P;
  for (long long i = 1; i <= n; i++) ffa[i] = i, siz[i] = 1;
  cnt = n;
  while (m--) {
    cin >> u >> v;
    u = getf(u);
    v = getf(v);
    if (u == v) continue;
    ffa[v] = u;
    siz[u] += siz[v];
    cnt--;
  }
  for (long long i = 1; i <= n; i++)
    if (getf(i) == i) ans = (ans * siz[i]) % P;
  for (long long i = 1; i <= cnt - 2; i++) ans = (ans * n) % P;
  if (cnt == 1) ans = 1;
  cout << ans % P << '\n';
  return 0;
}
