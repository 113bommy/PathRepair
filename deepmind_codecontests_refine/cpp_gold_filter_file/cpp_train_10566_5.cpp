#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
vector<std::pair<int, int> > List[100000];
vector<int> List1[100000][10];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < (m); ++i) {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    List[u].push_back({v, c});
    List[v].push_back({u, c});
    List1[u][c].push_back(v);
    List1[v][c].push_back(u);
  }
  vector<int> dist(n, MOD);
  dist[0] = 0;
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()) {
    int v = Q.front();
    Q.pop();
    for (std::pair<int, int> c : List[v]) {
      if (dist[c.first] == MOD) {
        Q.push(c.first);
        dist[c.first] = dist[v] + 1;
      }
    }
  }
  vector<int> rev_dist(n, MOD);
  vector<int> par(n, -1);
  Q.push(n - 1);
  rev_dist[n - 1] = 0;
  while (!Q.empty()) {
    int v = Q.front();
    Q.pop();
    for (std::pair<int, int> c : List[v]) {
      if (rev_dist[c.first] == MOD && c.second == 0) {
        Q.push(c.first);
        rev_dist[c.first] = rev_dist[v] + 1;
        par[c.first] = v;
      }
    }
  }
  int d = MOD;
  for (int i = 0; i < (n); ++i)
    if (rev_dist[i] != MOD) d = min(d, dist[i]);
  vector<std::pair<int, int> > now;
  for (int i = 0; i < (n); ++i) {
    if (rev_dist[i] != MOD && dist[i] == d) {
      now.push_back(make_pair(rev_dist[i], i));
    }
  }
  sort(now.begin(), now.end());
  while (d > 0) {
    d -= 1;
    map<int, int> mp;
    for (int c = 0; c < 10; ++c) {
      for (std::pair<int, int> nd : now) {
        for (int v : List1[nd.second][c]) {
          if (dist[v] == d && mp.find(v) == mp.end()) {
            mp[v] = rev_dist[nd.second] + 1;
            par[v] = nd.second;
            rev_dist[v] = rev_dist[nd.second] + 1;
          }
        }
      }
      if (!mp.empty()) {
        now.clear();
        for (auto it : mp) {
          now.push_back({it.second, it.first});
        }
        sort(now.begin(), now.end());
        break;
      }
    }
  }
  assert(now.size() > 0);
  string cost = "";
  vector<int> ans;
  int cur = 0;
  while (par[cur] != -1) {
    for (std::pair<int, int> p : List[cur])
      if (p.first == par[cur]) {
        cost += (char)('0' + p.second);
        break;
      }
    ans.push_back(cur);
    cur = par[cur];
  }
  ans.push_back(n - 1);
  while (cost.size() > 0 && cost.back() == '0') cost.pop_back();
  if (cost.size() == 0) cost.push_back('0');
  reverse(cost.begin(), cost.end());
  for (char c : cost) putchar(c);
  putchar(10);
  printf("%d\n", (int)ans.size());
  for (int nd : ans) printf("%d ", nd);
  putchar(10);
  return 0;
}
