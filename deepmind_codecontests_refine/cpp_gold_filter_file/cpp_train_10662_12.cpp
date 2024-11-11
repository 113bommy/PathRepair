#include <bits/stdc++.h>
using namespace std;
long long max(long long x, long long y) { return x > y ? x : y; }
long long min(long long x, long long y) { return x < y ? x : y; }
void _(long long& a, long long b) {
  a = (a % 1000000007 + b % 1000000007) % 1000000007;
  a = (a + 1000000007) % 1000000007;
}
long long cl(long long a, long long b) { return (a / b) + (!(!(a % b))); }
long long t = 0;
long long n, m;
vector<long long> e[200010];
long long a[200010];
long long l[200010];
long long fen[200010];
long long st[200010];
long long en[200010];
void dfs(long long i, long long p, long long lev) {
  st[i] = ++t;
  l[i] = lev;
  for (auto j : e[i]) {
    if (j != p) dfs(j, i, lev + 1);
  }
  en[i] = t;
}
void upd(long long i, long long val) {
  while (i <= n) {
    fen[i] += val;
    i += i & -i;
  }
}
long long sum(long long i) {
  long long ans = 0;
  while (i) {
    ans += fen[i];
    i -= i & -i;
  }
  return ans;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (long long i = 0; i < n - 1; ++i) {
    long long u, v;
    cin >> u >> v;
    u--;
    v--;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(0, -1, 0);
  for (long long i = 0; i < m; ++i) {
    long long t;
    cin >> t;
    if (t == 1) {
      long long x, val;
      cin >> x >> val;
      x--;
      if (l[x] & 1) val = -val;
      upd(st[x], val);
      upd(en[x] + 1, -val);
    } else {
      long long x;
      cin >> x;
      x--;
      if (l[x] & 1)
        cout << a[x] - sum(st[x]) << "\n";
      else
        cout << a[x] + sum(st[x]) << "\n";
    }
  }
}
