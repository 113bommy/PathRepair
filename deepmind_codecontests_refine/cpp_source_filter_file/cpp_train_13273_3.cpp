#include <bits/stdc++.h>
using namespace std;
int n, m;
int v[50101], u[50101];
int c[50101], t[50101];
vector<pair<int, int>> sgr[301010][2];
map<int, int> gr[50101];
int pred[50101];
int vis[301010][2];
int ind;
int ord[301010];
int chk[301010];
const int INF = 1010101010;
int dfs(int x, int sty, int ti, int tmp = 1) {
  if (vis[x][sty]) return 1;
  vis[x][sty] = tmp;
  if (sty) {
    if (vis[(x + 3 * m) % (6 * m)][sty] == tmp) return 0;
    if (x < 3 * m)
      chk[x % (3 * m)] = 1;
    else
      chk[x % (3 * m)] = 2;
  }
  for (auto y : sgr[x][sty]) {
    if (y.second > ti) {
      if (!dfs(y.first, sty, ti, tmp)) {
        return 0;
      }
    }
  }
  if (!sty) ord[ind++] = x;
  return 1;
}
int check(int ti) {
  for (int i = 0; i < 6 * m; i++) {
    chk[i] = 0;
    for (int j = 0; j < 2; j++) vis[i][j] = 0;
  }
  ind = 0;
  for (int i = 6 * m - 1; i >= 0; i--) dfs(i, 0, ti);
  for (int i = 6 * m - 1; i >= 0; i--) {
    if (!dfs(ord[i], 1, ti, i + 1)) return 0;
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  int fail = 0;
  for (int i = 0; i < m; i++) {
    cin >> v[i] >> u[i] >> c[i] >> t[i];
    if (gr[v[i]].count(c[i]))
      gr[v[i]][c[i]]++;
    else
      gr[v[i]][c[i]] = 1;
    if (gr[u[i]].count(c[i]))
      gr[u[i]][c[i]]++;
    else
      gr[u[i]][c[i]] = 1;
    if (max(gr[v[i]][c[i]], gr[u[i]][c[i]]) > 2) fail = 1;
  }
  if (fail) {
    cout << "No\n";
    return 0;
  }
  for (int i = 1; i <= n; i++) gr[i].clear();
  for (int i = 0; i < m; i++) {
    if (gr[v[i]].count(c[i])) {
      int j = gr[v[i]][c[i]];
      sgr[i + 3 * m][0].push_back(make_pair(j, INF));
      sgr[j + 3 * m][0].push_back(make_pair(i, INF));
      sgr[i][1].push_back(make_pair(j + 3 * m, INF));
      sgr[j][1].push_back(make_pair(i + 3 * m, INF));
    } else
      gr[v[i]][c[i]] = i;
    if (gr[u[i]].count(c[i])) {
      int j = gr[u[i]][c[i]];
      sgr[i + 3 * m][0].push_back(make_pair(j, INF));
      sgr[j + 3 * m][0].push_back(make_pair(i, INF));
      sgr[i][1].push_back(make_pair(j + 3 * m, INF));
      sgr[j][1].push_back(make_pair(i + 3 * m, INF));
    } else
      gr[u[i]][c[i]] = i;
  }
  for (int i = 0; i < m; i++) {
    sgr[i][0].push_back(make_pair(i + 3 * m, t[i]));
    sgr[i + 3 * m][1].push_back(make_pair(i, t[i]));
    int hlp = m + 2 * i;
    sgr[i][0].push_back(make_pair(hlp, INF));
    sgr[hlp + 3 * m][0].push_back(make_pair(i + 3 * m, INF));
    sgr[hlp][1].push_back(make_pair(i, INF));
    sgr[i + 3 * m][1].push_back(make_pair(hlp + 3 * m, INF));
    if (pred[v[i]]) {
      int j = pred[v[i]];
      sgr[j][0].push_back(make_pair(hlp, INF));
      sgr[hlp + 3 * m][0].push_back(make_pair(j + 3 * m, INF));
      sgr[hlp][1].push_back(make_pair(j, INF));
      sgr[j + 3 * m][1].push_back(make_pair(hlp + 3 * m, INF));
      sgr[i][0].push_back(make_pair(j + 3 * m, INF));
      sgr[j][0].push_back(make_pair(i + 3 * m, INF));
      sgr[j + 3 * m][1].push_back(make_pair(i, INF));
      sgr[i + 3 * m][1].push_back(make_pair(j, INF));
    }
    pred[v[i]] = hlp;
    hlp++;
    sgr[i][0].push_back(make_pair(hlp, INF));
    sgr[hlp + 3 * m][0].push_back(make_pair(i + 3 * m, INF));
    sgr[hlp][1].push_back(make_pair(i, INF));
    sgr[i + 3 * m][1].push_back(make_pair(hlp + 3 * m, INF));
    if (pred[u[i]]) {
      int j = pred[u[i]];
      sgr[j][0].push_back(make_pair(hlp, INF));
      sgr[hlp + 3 * m][0].push_back(make_pair(j + 3 * m, INF));
      sgr[hlp][1].push_back(make_pair(j, INF));
      sgr[j + 3 * m][1].push_back(make_pair(hlp + 3 * m, INF));
      sgr[i][0].push_back(make_pair(j + 3 * m, INF));
      sgr[j][0].push_back(make_pair(i + 3 * m, INF));
      sgr[j + 3 * m][1].push_back(make_pair(i, INF));
      sgr[i + 3 * m][1].push_back(make_pair(j, INF));
    }
    pred[u[i]] = hlp;
  }
  int ala = 0;
  int yla = 10;
  while (ala < yla) {
    int mid = (ala + yla) / 2;
    if (check(mid))
      yla = mid;
    else
      ala = mid + 1;
  }
  if (!check(yla) || yla >= INF) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
    cout << yla << " ";
    int cntr = 0;
    for (int i = 0; i < m; i++) {
      if (chk[i] == 1) cntr++;
    }
    cout << cntr << "\n";
    for (int i = 0; i < m; i++) {
      if (chk[i] == 1) cout << i + 1 << " ";
    }
    cout << "\n";
  }
}
