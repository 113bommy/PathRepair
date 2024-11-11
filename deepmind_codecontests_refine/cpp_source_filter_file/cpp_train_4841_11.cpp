#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > p1[300100];
vector<int> p[300100];
vector<pair<int, int> > gr[300100];
map<pair<int, int>, int> pos;
int n, m;
bool ok[300300];
int res[300303];
bool v[300200];
void dfs(int x, int pp = -1) {
  if (v[x]) return;
  v[x] = 1;
  for (int i = 0; i < gr[x].size(); i++) {
    dfs(gr[x][i].first, gr[x][i].second);
  }
  if (ok[x]) return;
  for (int i = 0; i < gr[x].size(); i++) {
    if (!res[gr[x][i].second] && gr[x][i].second != pp) {
      res[gr[x][i].second] = pos[make_pair(x, gr[x][i].second)];
      ok[x] = 1;
      return;
    }
  }
  for (int i = 0; i < gr[x].size(); i++) {
    if (!res[gr[x][i].second]) {
      res[gr[x][i].second] = pos[make_pair(x, gr[x][i].second)];
      ok[x] = 1;
      return;
    }
  }
}
int main() {
  cin >> n >> m;
  int k;
  int x;
  bool corr = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      scanf("%d", &x);
      p1[abs(x)].push_back(make_pair(i, x));
      p[i].push_back(x);
      if (x > 0) {
        if (pos.count(make_pair(i, x)) && pos[make_pair(i, x)] != 2) {
          corr = 0;
        }
        pos[make_pair(i, x)] = 2;
      } else {
        if (pos.count(make_pair(i, -x)) && pos[make_pair(i, -x)] != 1) {
          corr = 0;
        }
        pos[make_pair(i, -x)] = 1;
      }
    }
  }
  if (!corr) {
    cout << "NO\n";
    return 0;
  }
  queue<int> q;
  for (int i = 1; i <= m; i++) {
    if (p1[i].size() == 1) {
      if (!ok[p1[i][0].first]) {
        ok[p1[i][0].first] = 1;
        q.push(p1[i][0].first);
        if (p1[i][0].second > 0)
          res[i] = 2;
        else
          res[i] = 1;
      }
    } else if (p1[i].size() == 2) {
      if (p1[i][0].second != p1[i][1].second) continue;
      if (!ok[p1[i][0].first]) {
        ok[p1[i][0].first] = 1;
        q.push(p1[i][0].first);
        if (p1[i][0].second > 0)
          res[i] = 2;
        else
          res[i] = 1;
      }
      if (!ok[p1[i][1].first]) {
        ok[p1[i][1].first] = 1;
        q.push(p1[i][1].first);
        if (p1[i][1].second > 0)
          res[i] = 2;
        else
          res[i] = 1;
      }
    }
  }
  while (!q.empty()) {
    int t = q.front();
    q.pop();
    for (int i = 0; i < p[t].size(); i++) {
      int in = p[t][i];
      for (int j = 0; j < p1[in].size(); j++) {
        if (!ok[p1[in][j].first]) {
          ok[p1[in][j].first] = 1;
          q.push(p1[in][j].first);
          if (p1[in][j].second > 0)
            res[in] = 2;
          else
            res[in] = 1;
        }
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    if (res[i]) continue;
    if (p1[i].size() == 2 && !ok[p1[i][0].first] && !ok[p1[i][1].first] &&
        p1[i][0].second != p1[i][1].second) {
      gr[p1[i][0].first].push_back(make_pair(p1[i][1].first, i));
      gr[p1[i][1].first].push_back(make_pair(p1[i][0].first, i));
    }
  }
  for (int i = 1; i <= n; i++) {
    if (ok[i]) continue;
    if (v[i]) continue;
    dfs(i);
  }
  for (int i = 1; i <= n; i++) {
    if (!ok[i]) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  for (int i = 1; i <= m; i++) {
    res[i] = max(res[i], 1);
    printf("%d", res[i] - 1);
  }
  cout << endl;
  return 0;
}
