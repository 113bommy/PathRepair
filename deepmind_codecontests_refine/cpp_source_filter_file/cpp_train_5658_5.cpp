#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
const int MAX = 2e5 + 10;
int n, m, k, s, t, h[MAX], dis[MAX], dis2[MAX];
vi e[MAX];
const int INF = 1e6;
int v[MAX];
int src[MAX];
vi e2[MAX];
vector<ii> ar;
vector<ii> ar2;
void dfs(int x) {
  v[x] = 1;
  for (int y : e2[x]) {
    if (v[y] == 0) dfs(y);
  }
}
int intenta(int q) {
  if (dis[t] > q) return 0;
  for (int i = 1; i <= n; i++) {
    v[i] = 0;
    e2[i].clear();
  }
  for (ii p : ar2) {
    if (dis[p.first] + dis[p.second] + 1 <= q) {
      e2[src[p.first]].push_back(src[p.second]);
      e2[src[p.second]].push_back(src[p.first]);
    }
  }
  dfs(s);
  deque<int> D;
  for (int i = 1; i <= n; i++) {
    dis2[i] = INF;
    if (v[i]) {
      dis2[i] = 0;
      D.push_back(i);
    }
  }
  while (!D.empty()) {
    int x = D.front();
    for (int y : e[x]) {
      if (dis2[y] <= dis2[x] + 1) continue;
      dis2[y] = dis2[x] + 1;
      D.push_back(y);
    }
    D.pop_front();
  }
  if (dis2[t] <= 1) return 1;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) {
    int x;
    cin >> x;
    h[x] = 1;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    e[a].push_back(b);
    e[b].push_back(a);
    ar.push_back(ii(a, b));
  }
  deque<int> D;
  for (int i = 1; i <= n; i++) {
    dis[i] = INF;
    if (h[i]) {
      dis[i] = 0;
      src[i] = i;
      D.push_back(i);
    }
  }
  while (!D.empty()) {
    int x = D.front();
    for (int y : e[x]) {
      if (dis[y] <= dis[x] + 1) continue;
      dis[y] = dis[x] + 1;
      src[y] = src[x];
      D.push_back(y);
    }
    D.pop_front();
  }
  for (ii p : ar) {
    if (src[p.first] != src[p.second]) ar2.push_back(p);
  }
  cin >> s >> t;
  int hi = n + 10;
  int lo = 1;
  if (!intenta(hi)) {
    cout << "-1\n";
    return 0;
  }
  while (intenta(hi - 1)) {
    int cen = (hi + lo) / 2;
    if (intenta(cen))
      hi = cen;
    else
      lo = cen;
  }
  cout << hi << "\n";
}
