#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vl = vector<long>;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vvi = vector<vector<int> >;
using ii = pair<int, int>;
using vii = vector<ii>;
using vs = vector<string>;
using msi = map<string, int>;
using iss = istringstream;
vvi adj;
vi depth;
vi par;
ii findcycle(int v, int p = -1, int d = 0) {
  depth[v] = d;
  par[v] = p;
  ii res(-1, -1);
  for (int nxt : adj[v]) {
    if (depth[nxt] >= 0 && nxt != par[v]) {
      int cf = nxt, cl = v;
      int len = depth[cl] - depth[cf] + 1;
      if (res.first < 0 || depth[res.second] - depth[res.first] + 1 > len) {
        res.first = cf, res.second = cl;
      }
    }
  }
  for (int nxt : adj[v]) {
    if (depth[nxt] < 0) {
      ii sub_res = findcycle(nxt, v, d + 1);
      int len = depth[sub_res.second] - depth[sub_res.first] + 1;
      if (res.first < 0 || depth[res.second] - depth[res.first] + 1 > len) {
        res = sub_res;
      }
    }
  }
  return res;
}
bool printIndSet(int v, int &cnt, int d = 0) {
  depth[v] = d;
  int childcnt = 0;
  bool deleted = false;
  for (int nxt : adj[v]) {
    if (depth[nxt] < 0) {
      deleted |= printIndSet(nxt, cnt, d + 1);
      childcnt++;
    }
  }
  if (cnt == 0) return true;
  if (childcnt == 0) {
    cnt--;
    cout << v + 1 << ' ';
    return true;
  } else {
    if (deleted)
      return false;
    else {
      cnt--;
      cout << v + 1 << ' ';
      return true;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  adj.assign(n, vi());
  depth.assign(n, -1);
  par.assign(n, -1);
  while (m--) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  ii result = findcycle(0);
  vi cycle;
  if (result.first < 0) goto indset;
  cycle.push_back(result.second);
  while (par[cycle.back()] != result.first) cycle.push_back(par[cycle.back()]);
  cycle.push_back(result.first);
  if (cycle.size() <= k) {
    cout << 2 << '\n';
    cout << cycle.size() << '\n';
    for (int x : cycle) cout << x + 1 << ' ';
    cout << '\n';
    return 0;
  }
indset:
  cout << 1 << '\n';
  int cnt = k / 2 + (k % 2 == 1);
  if (cycle.size() > 0) {
    for (int i = 0; i < cycle.size(); i += 2) {
      cout << cycle[i] << ' ';
      cnt--;
      if (cnt == 0) break;
    }
    cout << '\n';
    return 0;
  }
  depth.assign(n, -1);
  printIndSet(0, cnt);
  cout << '\n';
  return 0;
}
