#include <bits/stdc++.h>
using namespace std;
vector<int> ed[100100];
int deg[100100];
int flag[100100];
int n, m, h, t;
void out(int a, int b) {
  cout << "YES" << endl;
  cout << a + 1 << " " << b + 1 << endl;
  for (int i = 0; i < deg[b]; i++) {
    flag[ed[b][i]] = b + 1;
  }
  int c = 0;
  for (int i = 0; i < deg[a]; i++) {
    if (flag[ed[a][i]] != b + 1 && ed[a][i] != b) {
      cout << ed[a][i] + 1 << " ";
      c++;
      if (c == h) break;
      flag[ed[a][i]] = -1;
    }
  }
  for (int i = 0; i < deg[a]; i++) {
    if (flag[ed[b][i]] != -1 && ed[a][i] != b) {
      if (c == h) break;
      cout << ed[a][i] + 1 << " ";
      c++;
      flag[ed[a][i]] = -1;
    }
  }
  cout << endl;
  c = 0;
  for (int i = 0; i < deg[b]; i++) {
    if (flag[ed[b][i]] != -1 && ed[b][i] != a) {
      cout << ed[b][i] + 1 << " ";
      c++;
      if (c == t) break;
    }
  }
}
int main() {
  cin >> n >> m >> h >> t;
  int fr, to;
  for (int i = 0; i < m; i++) {
    cin >> fr >> to;
    fr--, to--;
    ed[fr].push_back(to);
    ed[to].push_back(fr);
    deg[fr]++;
    deg[to]++;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < deg[i]; j++) flag[ed[i][j]] = i + 1;
    for (int j = 0; j < deg[i]; j++) {
      int to = ed[i][j];
      if (deg[i] < h + 1 || deg[to] < t + 1) continue;
      if (deg[i] > h + t || deg[to] > h + t) {
        out(i, to);
        return 0;
      }
      int tt = 0;
      for (int k = 0; k < deg[to]; k++)
        if (flag[ed[to][k]] == i + 1) tt++;
      if (deg[i] + deg[to] - tt >= h + t + 2) {
        out(i, to);
        return 0;
      }
    }
  }
  cout << "NO";
  return 0;
}
