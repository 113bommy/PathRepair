#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7, N = 1e5 + 5;
const long long inf = 1e18;
namespace uchiha {
long long ceil(long long a, long long b) { return (a + b - 1) / b; }
double clk;
}  // namespace uchiha
using namespace uchiha;
void init();
vector<vector<long long> > adj;
vector<long long> parent, deg;
vector<bool> vis;
map<long long, long long> fre;
bool cmp(vector<long long> x, vector<long long> y) {
  long long a = x[0], b = y[0];
  if (fre[a] ^ fre[b]) return fre[a] > fre[b];
  return a > b;
}
void dfs(long long u = 1, long long par = 0) {
  vis[u] = 1;
  for (auto v : adj[u]) {
    if (vis[v] || v == par) {
      continue;
    }
    parent[v] = u;
    dfs(v, u);
  }
}
void solve() {
  long long n;
  cin >> n;
  vector<vector<long long> > inp;
  adj.assign(n + 1, vector<long long>());
  deg.assign(n + 1, 0);
  for (long long i = 0; i < (long long)n - 1; i++) {
    long long x, y;
    cin >> x >> y;
    inp.push_back({x, y});
    deg[x]++;
    deg[y]++;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  long long idx =
      max_element(deg.begin() + 1, deg.begin() + n + 1) - deg.begin();
  parent.assign(n + 1, 0);
  vis.assign(n + 1, 0);
  dfs(idx);
  vector<vector<long long> > seq;
  for (long long i = 1; i < (long long)n + 1; i++) {
    if (deg[i] == 1) {
      seq.push_back({parent[i], i});
      fre[parent[i]]++;
    }
  }
  sort(seq.begin() + 0, seq.begin() + (long long)((seq).size()), cmp);
  long long cur = 1;
  map<pair<long long, long long>, long long> done;
  for (auto x : seq) {
    pair<long long, long long> p = {x[0], x[1]};
    pair<long long, long long> q = {x[1], x[0]};
    done[p] = cur;
    done[q] = cur;
    cur++;
  }
  vector<long long> ans;
  for (auto x : inp) {
    pair<long long, long long> p = {x[0], x[1]};
    if (done[p]) {
      ans.push_back(done[p]);
    } else {
      ans.push_back(++cur);
    }
  }
  for (auto it = ans.begin(); it != ans.end(); it++) {
    cout << (*it) - 1 << "\n";
  }
}
int32_t main() {
  init();
  long long T = 1;
  for (long long i = 1; i <= T; i++) {
    solve();
  }
  cerr << fixed << "Time " << ((clock() - clk) / 1e6);
}
void init() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  srand(time(NULL));
  clk = clock();
}
