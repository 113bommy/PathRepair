#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > paths[30][30], spath, epath;
pair<int, int> cpos[30];
char grid[400][400];
int n, m;
pair<int, int> sp;
pair<int, int> prv[400][400];
bool vis[400][400];
bool inRange(int a, int b) {
  if (a >= 0 && b >= 0 && a < n && b < m && grid[a][b] != '#') return true;
  return false;
}
void doBFS(int cur) {
  int i, j, k, d1, d2;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) vis[i][j] = false;
  pair<int, int> cp, tmp, ptmp;
  queue<pair<int, int> > Q;
  Q.push(cpos[cur]);
  while (!Q.empty()) {
    cp = Q.front();
    Q.pop();
    for (d1 = -1; d1 <= 1; d1++)
      for (d2 = -1; d2 <= 1; d2++)
        if (!d1 || !d2) {
          tmp.first = cp.first + d1;
          tmp.second = cp.second + d2;
          if (inRange(tmp.first, tmp.second) && !vis[tmp.first][tmp.second]) {
            vis[tmp.first][tmp.second] = true;
            prv[tmp.first][tmp.second] = cp;
            Q.push(tmp);
            char c = grid[tmp.first][tmp.second];
            if (c <= 'z' && c >= 'a' && !(paths[cur][c - 'a'].size())) {
              c -= 'a';
              for (ptmp = tmp; ptmp != cpos[cur];
                   ptmp = prv[ptmp.first][ptmp.second]) {
                paths[cur][c].push_back(ptmp);
                paths[c][cur].push_back(ptmp);
              }
              paths[cur][c].push_back(ptmp);
              paths[c][cur].push_back(ptmp);
              reverse(paths[cur][c].begin(), paths[cur][c].end());
            }
          }
        }
  }
}
char str[10000];
int main() {
  int T, i, j, k, d1, d2;
  pair<int, int> tmp, cp, ptmp, ep;
  T = 1;
  while (T--) {
    cin >> n >> m >> k;
    for (i = 0; i < 30; i++) {
      cpos[i].first = cpos[i].second = -1;
      for (j = 0; j < 30; j++) paths[i][j].clear();
    }
    for (i = 0; i < n; i++) cin >> grid[i];
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++)
        if (grid[i][j] >= 'a' && grid[i][j] <= 'z') {
          cpos[grid[i][j] - 'a'].first = i;
          cpos[grid[i][j] - 'a'].second = j;
        }
    for (i = 0; i < 30; i++)
      if (cpos[i].first >= 0) doBFS(i);
    cin >> sp.first >> sp.second >> str >> ep.first >> ep.second;
    sp.first--;
    sp.second--;
    ep.first--;
    ep.second--;
    queue<pair<int, int> > Q;
    spath.clear();
    Q.push(sp);
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++) vis[i][j] = false;
    bool bl = false;
    while (!Q.empty() && !bl) {
      cp = Q.front();
      Q.pop();
      for (d1 = -1; d1 <= 1 && !bl; d1++)
        for (d2 = -1; d2 <= 1 && !bl; d2++)
          if (!d1 || !d2) {
            tmp.first = cp.first + d1;
            tmp.second = cp.second + d2;
            if (inRange(tmp.first, tmp.second) && !vis[tmp.first][tmp.second]) {
              vis[tmp.first][tmp.second] = true;
              prv[tmp.first][tmp.second] = cp;
              Q.push(tmp);
              char c = grid[tmp.first][tmp.second];
              if (c == str[0]) {
                for (ptmp = tmp; ptmp != sp;
                     ptmp = prv[ptmp.first][ptmp.second])
                  spath.push_back(ptmp);
                spath.push_back(ptmp);
                reverse(spath.begin(), spath.end());
                bl = true;
              }
            }
          }
    }
    while (!Q.empty()) Q.pop();
    epath.clear();
    Q.push(ep);
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++) vis[i][j] = false;
    bl = false;
    int ll = strlen(str);
    while (!Q.empty() && !bl) {
      cp = Q.front();
      Q.pop();
      for (d1 = -1; d1 <= 1 && !bl; d1++)
        for (d2 = -1; d2 <= 1 && !bl; d2++)
          if (!d1 || !d2) {
            tmp.first = cp.first + d1;
            tmp.second = cp.second + d2;
            if (inRange(tmp.first, tmp.second) && !vis[tmp.first][tmp.second]) {
              vis[tmp.first][tmp.second] = true;
              prv[tmp.first][tmp.second] = cp;
              Q.push(tmp);
              char c = grid[tmp.first][tmp.second];
              if (c == str[ll - 1]) {
                for (ptmp = tmp; ptmp != ep;
                     ptmp = prv[ptmp.first][ptmp.second])
                  epath.push_back(ptmp);
                epath.push_back(ptmp);
                bl = true;
              }
            }
          }
    }
    cp = sp;
    int stri = 0, remt = k, curvi = 0;
    while (1) {
      char c = grid[cp.first][cp.second];
      if (!k || (c >= '0' && c <= '9' && k < c - '0')) break;
      if (c >= '0' && c <= '9')
        k -= (c - '0');
      else
        k--;
      if (!stri) {
        cp = spath[++curvi];
        if (curvi == spath.size() - 1) {
          stri++;
          curvi = 0;
        }
      } else if (!str[stri]) {
        if (cp != ep) cp = epath[++curvi];
      } else {
        int ii = str[stri] - 'a', jj = str[stri - 1] - 'a';
        cp = paths[jj][ii][++curvi];
        if (curvi == paths[jj][ii].size() - 1) {
          stri++;
          curvi = 0;
        }
      }
    }
    cout << cp.first + 1 << " " << cp.second + 1 << endl;
  }
}
