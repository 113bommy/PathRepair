#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
struct edg {
  int v, u;
  bool r;
};
int n, m, dis[MAXN], dp[MAXN], dpe[MAXN];
bool se[MAXN], mk[MAXN];
vector<int> Mat[MAXN];
queue<int> S;
edg e[MAXN];
bool cmp(int a, int b) { return dis[a] < dis[b]; }
int gett(int ind, int v) {
  if (e[ind].v == v) return e[ind].u;
  return e[ind].v;
}
void addv(int v) {
  for (int i = 0; i < Mat[v].size(); i++) {
    int t = gett(Mat[v][i], v);
    if (!se[t]) {
      dis[t] = dis[v] + 1;
      se[t] = 1;
      S.push(t);
    }
  }
}
void upd(int v) {
  dp[v] = 1e9;
  for (int i = 0; i < Mat[v].size(); i++) {
    int t = gett(Mat[v][i], v);
    if (dis[t] != dis[v] - 1) continue;
    if (dp[v] > dp[t] + !e[Mat[v][i]].r) {
      dp[v] = dp[t] + !e[Mat[v][i]].r;
      dpe[v] = Mat[v][i];
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> e[i].v >> e[i].u >> e[i].r;
    Mat[e[i].v].push_back(i);
    Mat[e[i].u].push_back(i);
  }
  se[n] = 1;
  S.push(n);
  while (!S.empty()) {
    addv(S.front());
    S.pop();
  }
  vector<int> t;
  for (int i = 1; i <= n; i++) t.push_back(i);
  sort(t.begin(), t.end(), cmp);
  for (int i = 1; i < t.size(); i++) upd(i);
  int cur = 1;
  while (cur != n) {
    mk[dpe[cur]] = 1;
    cur = gett(dpe[cur], cur);
  }
  vector<pair<bool, pair<int, int> > > vc;
  for (int i = 0; i < m; i++) {
    if (mk[i] && !e[i].r)
      vc.push_back({1, {e[i].v, e[i].u}});
    else if (!mk[i] && e[i].r)
      vc.push_back({0, {e[i].v, e[i].u}});
  }
  cout << vc.size() << '\n';
  for (int i = 0; i < vc.size(); i++)
    cout << vc[i].second.first << ' ' << vc[i].second.second << ' '
         << vc[i].first << '\n';
}
