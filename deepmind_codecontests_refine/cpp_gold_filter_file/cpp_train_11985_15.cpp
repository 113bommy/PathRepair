#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
const int MAXN = 3e5 + 5;
using namespace std;
void fileIO(string prob) {
  freopen((prob + ".in").c_str(), "r", stdin);
  freopen((prob + ".out").c_str(), "w", stdout);
}
void fastIO() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
}
class BIT {
 private:
  vector<long long> bit;

 public:
  BIT(int n) { bit.assign(n + 1, 0); }
  long long query(int b) {
    long long ret = 0;
    while (b) {
      ret += bit[b];
      b -= (b & (-b));
    }
    return ret;
  }
  void add(int i, int u) {
    while (i < (int)bit.size()) {
      bit[i] += u;
      i += (i & (-i));
    }
  }
};
int n, m;
vector<int> adj[MAXN];
vector<pair<int, int> > q[MAXN];
BIT bt(MAXN);
long long ans[MAXN];
void dfs(int u, int par, int len) {
  for (auto qr : q[u]) {
    bt.add(len, qr.second);
    bt.add(len + qr.first + 1, -qr.second);
  }
  ans[u] = bt.query(len);
  for (int v : adj[u]) {
    if (v != par) dfs(v, u, len + 1);
  }
  for (auto qr : q[u]) {
    bt.add(len, -qr.second);
    bt.add(len + qr.first + 1, qr.second);
  }
}
int main() {
  fastIO();
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  cin >> m;
  while (m--) {
    int v, d, x;
    cin >> v >> d >> x;
    q[v].push_back({d, x});
  }
  dfs(1, -1, 1);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
}
