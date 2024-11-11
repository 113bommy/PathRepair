#include <bits/stdc++.h>
long long mpow(long long a, long long n, long long mod) {
  long long ret = 1;
  long long b = a;
  while (n) {
    if (n & 1) ret = (ret * b) % mod;
    b = (b * b) % mod;
    n >>= 1;
  }
  return (long long)ret;
}
using namespace std;
using namespace std;
int disg[(int)3e3 + 5][(int)3e3 + 5], disrg[(int)3e3 + 5][(int)3e3 + 5];
vector<int> G[(int)3e3 + 5], RG[(int)3e3 + 5], from[(int)3e3 + 5],
    to[(int)3e3 + 5];
void bfsg(int x) {
  disg[x][x] = 0;
  queue<int> q;
  q.push(x);
  while (!q.empty()) {
    int st = q.front();
    q.pop();
    for (int j = 0; j < G[st].size(); j++) {
      int ed = G[st][j];
      if (disg[x][ed] > disg[x][st] + 1) {
        disg[x][ed] = disg[x][st] + 1;
        q.push(ed);
      }
    }
  }
}
void bfsrg(int x) {
  disrg[x][x] = 0;
  queue<int> q;
  q.push(x);
  while (!q.empty()) {
    int st = q.front();
    q.pop();
    for (int j = 0; j < RG[st].size(); j++) {
      int ed = RG[st][j];
      if (disrg[x][ed] > disrg[x][st] + 1) {
        disrg[x][ed] = disrg[x][st] + 1;
        q.push(ed);
      }
    }
  }
}
void solve() {
  int n, m;
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);
    G[x].push_back(y);
    RG[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      disg[i][j] = 1e6;
      disrg[i][j] = 1e6;
    }
  }
  for (int i = 1; i <= n; i++) bfsg(i);
  for (int i = 1; i <= n; i++) {
    bfsrg(i);
  }
  for (int i = 1; i <= n; i++) {
    vector<pair<int, int> > v;
    for (int j = 1; j <= n; j++) {
      if (disg[i][j] != 1e6) {
        v.push_back(make_pair(disg[i][j], j));
      }
    }
    sort(v.rbegin(), v.rend());
    for (int j = 0; j < min((int)v.size(), 4); j++) {
      from[i].push_back(v[j].second);
    }
  }
  for (int i = 1; i <= n; i++) {
    vector<pair<int, int> > v;
    for (int j = 1; j <= n; j++) {
      if (disrg[i][j] != 1e6) {
        v.push_back(make_pair(disrg[i][j], j));
      }
    }
    sort(v.rbegin(), v.rend());
    for (int j = 0; j < min((int)v.size(), 4); j++) {
      to[i].push_back(v[j].second);
    }
  }
  int maxans = 0;
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      if (disg[i][j] == 1e6) continue;
      int fd = 0;
      for (int r = 0; r < to[i].size(); r++) {
        if (to[i][r] == i || to[i][r] == j) continue;
        for (int c = 0; c < from[j].size(); c++) {
          if (to[i][r] == from[j][c]) continue;
          if (from[j][c] == i || from[j][c] == j) continue;
          if (maxans < disrg[i][to[i][r]] + disg[i][j] + disg[j][from[j][c]]) {
            maxans = disrg[i][to[i][r]] + disg[i][j] + disg[j][from[j][c]];
            ans.clear();
            ans.push_back(to[i][r]);
            ans.push_back(i);
            ans.push_back(j);
            ans.push_back(from[j][c]);
          }
          fd = 1;
          break;
        }
        if (fd) break;
      }
      fd = 0;
      for (int c = 0; c < from[j].size(); c++) {
        if (from[j][c] == i || from[j][c] == j) continue;
        for (int r = 0; r < to[i].size(); r++) {
          if (to[i][r] == from[j][c]) continue;
          if (to[i][r] == i || from[i][r] == j) continue;
          if (maxans < disrg[i][to[i][r]] + disg[i][j] + disg[j][from[j][c]]) {
            maxans = disrg[i][to[i][r]] + disg[i][j] + disg[j][from[j][c]];
            ans.clear();
            ans.push_back(to[i][r]);
            ans.push_back(i);
            ans.push_back(j);
            ans.push_back(from[j][c]);
          }
          fd = 1;
          break;
        }
        if (fd) break;
      }
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
}
int main() {
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
