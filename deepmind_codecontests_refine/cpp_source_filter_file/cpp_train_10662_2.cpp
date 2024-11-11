#include <bits/stdc++.h>
using namespace std;
const long long int N = 1000010;
long long int a1[N];
vector<long long int> v1[N];
struct lol {
  long long int in, out, on;
};
lol G[N];
long long int t = 1, vc[2][N];
long long int n, q;
void dfs(long long int u, long long int par) {
  G[u].in = t++;
  G[u].on = (par == -1) ? 0 : (1 - G[par].on);
  vector<long long int>::iterator it;
  for (it = v1[u].begin(); it != v1[u].end(); it++) {
    if (*it == par) continue;
    dfs(*it, u);
  }
  G[u].out = t++;
}
void updt(long long int pos, long long int on, long long int val) {
  while (pos <= n) {
    vc[on][pos] += val;
    pos += (pos & -pos);
  }
}
long long int qry(long long int pos, long long int on) {
  long long int res = 0;
  while (pos > 0) {
    res += vc[on][pos];
    pos -= (pos & -pos);
  }
  return res;
}
int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a1[i];
  for (int i = 1; i < n; i++) {
    long long int u, v;
    cin >> u >> v;
    v1[u].push_back(v);
    v1[v].push_back(u);
  }
  dfs(1, -1);
  for (int i = 1; i <= n; i++) {
  }
  while (q--) {
    long long int type;
    cin >> type;
    long long int u;
    cin >> u;
    if (type == 1) {
      long long int val;
      cin >> val;
      updt(G[u].in, G[u].on, val);
      updt(G[u].out, G[u].on, -val);
    } else {
      cout << a1[u] + (qry(G[u].in, G[u].on)) - qry(G[u].in, 1 - G[u].on)
           << "\n";
    }
  }
  return 0;
}
