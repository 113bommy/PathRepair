#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 55;
vector<pair<int, int> > e[maxn];
vector<int> e2[maxn];
vector<string> res;
int dep[maxn];
int n, m, u, v, k;
string st;
void dfs(int now) {
  if (res.size() >= k) {
    return;
  }
  if (now == n + 1) {
    res.push_back(st);
    return;
  }
  for (auto ep : e2[now]) {
    st[ep] = '1';
    dfs(now + 1);
    st[ep] = '0';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    st += "0";
    cin >> u >> v;
    e[u].push_back(make_pair(v, i));
    e[v].push_back(make_pair(u, i));
  }
  queue<int> Q;
  Q.push(1);
  dep[1] = 1;
  while (!Q.empty()) {
    int now = Q.front();
    Q.pop();
    for (auto ep : e[now]) {
      if (dep[ep.first] == 0) {
        dep[ep.first] = dep[now] + 1;
        Q.push(ep.first);
      }
    }
  }
  for (int i = 2; i <= n; i++) {
    for (auto ep : e[i]) {
      if (dep[i] == dep[ep.first] + 1) {
        e2[i].push_back(ep.second);
      }
    }
  }
  dfs(2);
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++) cout << res[i] << endl;
  return 0;
}
