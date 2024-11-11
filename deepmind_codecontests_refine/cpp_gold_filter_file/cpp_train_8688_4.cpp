#include <bits/stdc++.h>
using namespace std;
const int MAXV = 400 * 400 + 10, MAXN = 300;
vector<int> Mat[MAXV], Matr[MAXV], Topo;
int n, m, h, t, R, dis[MAXV];
pair<int, int> H[MAXN], T[MAXN];
bool se[MAXV], D, inv[MAXV];
queue<int> B;
void dfs(int v) {
  se[v] = 1;
  inv[v] = 1;
  for (int i = 0; i < Mat[v].size(); i++)
    if (!se[Mat[v][i]])
      dfs(Mat[v][i]);
    else if (inv[Mat[v][i]])
      D = 1;
  inv[v] = 0;
}
void BFS(int v) {
  for (int i = 0; i < Mat[v].size(); i++)
    if (!se[Mat[v][i]]) {
      se[Mat[v][i]] = 1;
      dis[Mat[v][i]] = dis[v] + 1;
      B.push(Mat[v][i]);
    }
}
void topo(int v) {
  se[v] = 1;
  for (int i = 0; i < Mat[v].size(); i++)
    if (!se[Mat[v][i]]) topo(Mat[v][i]);
  Topo.push_back(v);
}
int main() {
  cin >> h >> t >> R;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> H[i].first >> H[i].second;
  cin >> m;
  for (int i = 1; i <= m; i++) cin >> T[i].first >> T[i].second;
  for (int i = 0; i < MAXV; i++) {
    int ch = i / MAXN, ct = i % MAXN;
    if (ch + ct > R) continue;
    for (int j = 1; j <= min(n, ch); j++) {
      int nh = ch - j + H[j].first;
      int nt = ct + H[j].second;
      if (nt + nh > R) continue;
      Mat[i].push_back(nh * MAXN + nt);
      Matr[nh * MAXN + nt].push_back(i);
    }
    for (int j = 1; j <= min(m, ct); j++) {
      int nh = ch + T[j].first;
      int nt = ct - j + T[j].second;
      if (nh + nt > R) continue;
      Mat[i].push_back(nh * MAXN + nt);
      Matr[nh * MAXN + nt].push_back(i);
    }
  }
  dfs(h * MAXN + t);
  fill_n(dis, MAXV, -1);
  if (se[0]) {
    fill_n(se, MAXV, 0);
    B.push(h * MAXN + t);
    se[h * MAXN + t] = 1;
    dis[h * MAXN + t] = 0;
    while (!B.empty()) BFS(B.front()), B.pop();
    cout << "Ivan" << '\n' << dis[0];
  } else if (D)
    cout << "Draw";
  else {
    fill_n(se, MAXV, 0);
    topo(h * MAXN + t);
    reverse(Topo.begin(), Topo.end());
    dis[Topo[0]] = 0;
    int ans = 0;
    for (int i = 1; i < Topo.size(); i++) {
      vector<int> &t = Matr[Topo[i]];
      for (int j = 0; j < t.size(); j++)
        dis[Topo[i]] = max(dis[t[j]] + 1, dis[Topo[i]]);
      ans = max(ans, dis[Topo[i]]);
    }
    cout << "Zmey" << '\n' << ans + 1;
  }
}
