#include <bits/stdc++.h>
using namespace std;
ostream& operator<<(ostream& out, map<long long, long long>& lst) {
  for (auto a : lst) out << a.first << ' ' << a.second << '\n';
  out << '\n';
  return out;
}
const long long mod = 1e9;
struct Int {
  long long x;
  Int(long long x = 0) : x(x){};
  Int operator+(Int y) { return (x + y.x) % mod; }
  Int operator-(Int y) { return (x + mod - y.x) % mod; }
  Int operator*(Int y) { return (x * y.x) % mod; }
};
pair<long long, long long> ed(long long i, long long j) {
  return make_pair(min(i, j), max(i, j));
}
Int deg(long long k) {
  if (k == 0) return 1;
  Int res = 2;
  long long st = 1;
  while (st * 2 <= k) {
    res = res * res;
    st *= 2;
  }
  return res * deg(k - st);
}
const long long N = 5e5 + 5;
long long tp[N];
map<long long, set<long long> > lst;
vector<long long> gr[N];
map<long long, long long> clr;
set<long long> used[N];
void dfs(long long v, long long pr = -1) {
  if (pr != -1) used[v].insert(pr);
  for (auto u : gr[v]) {
    long long x = tp[v] ^ tp[u];
    if (pr != -1 && x != pr) continue;
    if (used[u].find(x) != used[u].end()) continue;
    if (pr != -1) used[v].insert(x);
    dfs(u, x);
    if (pr == -1) clr[x]++;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  for (long long i = 0; i < n; i++) {
    cin >> tp[i];
  }
  for (long long i = 0; i < m; i++) {
    long long v, u, x;
    cin >> v >> u;
    v--, u--;
    x = (tp[u] ^ tp[v]);
    lst[x].insert(u);
    lst[x].insert(v);
    gr[v].push_back(u);
    gr[u].push_back(v);
  }
  Int ans(0);
  for (long long i = 0; i < n; i++) dfs(i);
  for (auto k : lst) {
    long long x = k.first;
    auto st = k.second;
    long long sz = (n - st.size());
    ans = ans + deg(sz + clr[x]);
  }
  ans = ans + deg(n) * (deg(k) - Int(lst.size()));
  cout << ans.x;
  return 0;
}
