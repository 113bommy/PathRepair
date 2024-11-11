#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:134217728")
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
int n;
int m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
string s[5001];
vector<int> t[5001];
string ss[5001];
vector<pair<int, int> > root[4][5001];
vector<pair<int, int> > next239[4][5001];
int good(int x, int y) { return x >= 0 && y >= 0 && x < n && y < m; }
int ans[10000];
pair<int, int> get_root(int t, pair<int, int> o) {
  if (root[t][o.first][o.second] == o) return o;
  return root[t][o.first][o.second] = get_root(t, root[t][o.first][o.second]);
}
void merge(int t, pair<int, int> a, pair<int, int> b) {
  a = get_root(t, a);
  root[t][a.first][a.second] = get_root(t, b);
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < (n); i++) cin >> s[i];
  for (int i = 0; i < (n); i++)
    for (int j = 0; j < (m); j++)
      if (s[i][j] != '.') {
        int c = s[i][j];
        if (c == 'U') t[i].push_back(3);
        if (c == 'D') t[i].push_back(1);
        if (c == 'L') t[i].push_back(2);
        if (c == 'R') t[i].push_back(0);
      } else
        t[i].push_back(-1);
  for (int o = 0; o < (4); o++) {
    for (int i = 0; i < (n); i++)
      for (int j = 0; j < (m); j++) {
        int cx = i + dx[o];
        int cy = j + dy[o];
        while (good(cx, cy) && s[cx][cy] == '.') {
          cx += dx[o];
          cy += dy[o];
        }
        if (good(cx, cy))
          next239[o][i].push_back(make_pair(cx, cy));
        else
          next239[o][i].push_back(make_pair(n, m));
      }
  }
  for (int o = 0; o < (4); o++)
    for (int i = 0; i < (n + 1); i++) root[o][i].resize(m + 1);
  for (int x = 0; x < (n); x++)
    for (int y = 0; y < (m); y++)
      if (s[x][y] != '.') {
        for (int i = 0; i < (n + 1); i++)
          for (int j = 0; j < (m + 1); j++)
            for (int o = 0; o < (4); o++) root[o][i][j] = make_pair(i, j);
        int cx = x, cy = y;
        int col = 1;
        while (good(cx, cy)) {
          pair<int, int> tmp = get_root(t[cx][cy], next239[t[cx][cy]][cx][cy]);
          if (!good(tmp.first, tmp.second)) break;
          for (int o = 0; o < (4); o++) {
            merge(o, make_pair(cx, cy), next239[o][cx][cy]);
          }
          cx = tmp.first;
          cy = tmp.second;
          col++;
        }
        ans[col]++;
      }
  int o = n * m;
  while (ans[o] == 0) o--;
  cout << o << ' ' << ans[o] << endl;
  return 0;
}
