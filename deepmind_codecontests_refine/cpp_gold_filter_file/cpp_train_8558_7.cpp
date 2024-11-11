#include <bits/stdc++.h>
using namespace std;
vector<int> adj[200100];
int par[200100];
int d1, d2;
pair<int, int> dfs(int srr, int p, int dis) {
  pair<int, int> res = make_pair(dis, srr);
  for (auto o : adj[srr])
    if (o != p) {
      res = max(res, dfs(o, srr, dis + 1));
      par[o] = srr;
    }
  return res;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  pair<int, int> p = dfs(1, 0, 0);
  pair<int, int> p2 = dfs(p.second, -2, 0);
  int srr = p2.second, sr2 = p.second;
  vector<int> vec;
  vec.push_back(srr);
  while (srr != sr2) {
    vec.push_back(par[srr]);
    srr = par[srr];
  }
  if (vec.size() == n) {
    cout << n - 1 << endl;
    cout << vec.front() << " " << vec[1] << " " << vec.back() << endl;
    return 0;
  } else {
    queue<int> q;
    vector<int> v(n + 1, -1);
    for (auto o : vec) {
      q.push(o);
      v[o] = 0;
    }
    int MX = 0, ver;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto o : adj[u])
        if (v[o] == -1) {
          q.push(o);
          v[o] = v[u] + 1;
          if (v[o] > MX) MX = v[o], ver = o;
        }
    }
    cout << MX + (vec.size() - 1) << endl;
    cout << vec.front() << " " << ver << " " << vec.back() << endl;
  }
}
