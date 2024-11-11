#include <bits/stdc++.h>
using namespace std;
const long double pai = acos(-1.0L);
const long double eps = 1e-10;
const long long mod = 1e9 + 7;
const int MXN = 1e6 + 5;
vector<char> a[MXN], ans[MXN], t[MXN];
char f[4] = {'A', 'G', 'C', 'T'};
int g[MXN], mi = INT_MAX, u, ss1, ss2;
int n, m;
void work(int s1, int s2, int uu) {
  int ss[2][2] = {s1, s2, -1, -1};
  for (int i = 0; i < 4; i++) {
    if (ss[0][0] != i && ss[0][1] != i && ss[1][0] == -1)
      ss[1][0] = i;
    else {
      if (ss[0][0] != i && ss[0][1] != i && ss[1][1] == -1) ss[1][1] = i;
    }
  }
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) ss[i][j] = f[ss[i][j]];
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    int c = 0, cc = 0;
    for (int j = 1; j <= m; j++) c = c + (ss[i % 2][j % 2] != a[i][j]);
    swap(ss[0][0], ss[0][1]);
    swap(ss[1][1], ss[1][0]);
    for (int j = 1; j <= m; j++) cc = cc + (ss[i % 2][j % 2] != a[i][j]);
    swap(ss[0][0], ss[0][1]);
    swap(ss[1][1], ss[1][0]);
    cnt += min(c, cc);
  }
  if (cnt < mi) {
    mi = cnt;
    u = uu;
    ss1 = s1, ss2 = s2;
  }
}
int main() {
  g['A'] = 0;
  g['G'] = 1;
  g['C'] = 2;
  g['T'] = 3;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    a[i].push_back('*');
    for (int j = 1; j <= m; j++) {
      char x;
      cin >> x;
      a[i].push_back(x);
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++)
      if (i != j) work(i, j, 0);
  }
  for (int i = 1; i <= m; i++) {
    t[i].push_back('*');
    for (int j = 1; j <= n; j++) {
      t[i].push_back(a[j][i]);
    }
  }
  for (int i = 1; i <= n; i++)
    while ((int)a[i].size()) a[i].pop_back();
  for (int i = 1; i <= m; i++) {
    a[i].push_back('*');
    for (int j = 1; j <= n; j++) {
      a[i].push_back(t[i][j]);
    }
  }
  swap(n, m);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++)
      if (i != j) work(i, j, 1);
  }
  swap(n, m);
  int ss[2][2] = {ss1, ss2, -1, -1};
  for (int i = 0; i < 4; i++) {
    if (ss[0][0] != i && ss[0][1] != i && ss[1][0] == -1)
      ss[1][0] = i;
    else {
      if (ss[0][0] != i && ss[0][1] != i && ss[1][1] == -1) ss[1][1] = i;
    }
  }
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) ss[i][j] = f[ss[i][j]];
  if (u == 0) {
    for (int i = 1; i <= n; i++) {
      int c = 0, cc = 0;
      for (int j = 1; j <= m; j++) c = c + (ss[i % 2][j % 2] != a[i][j]);
      swap(ss[0][0], ss[0][1]);
      swap(ss[1][1], ss[1][0]);
      for (int j = 1; j <= m; j++) cc = cc + (ss[i % 2][j % 2] != a[i][j]);
      swap(ss[0][0], ss[0][1]);
      swap(ss[1][1], ss[1][0]);
      if (c < cc) {
        for (int j = 1; j <= m; j++) cout << (char)ss[i % 2][j % 2];
      } else {
        swap(ss[0][0], ss[0][1]);
        swap(ss[1][1], ss[1][0]);
        for (int j = 1; j <= m; j++) cout << (char)ss[i % 2][j % 2];
        swap(ss[0][0], ss[0][1]);
        swap(ss[1][1], ss[1][0]);
      }
      puts("");
    }
  } else {
    for (int i = 1; i <= m; i++) {
      int c = 0, cc = 0;
      for (int j = 1; j <= n; j++) c = c + (ss[i % 2][j % 2] != a[j][i]);
      swap(ss[0][0], ss[0][1]);
      swap(ss[1][1], ss[1][0]);
      for (int j = 1; j <= n; j++) cc = cc + (ss[i % 2][j % 2] != a[j][i]);
      swap(ss[0][0], ss[0][1]);
      swap(ss[1][1], ss[1][0]);
      if (c < cc) {
        for (int j = 1; j <= n; j++) ans[j].push_back(ss[i % 2][j % 2]);
      } else {
        swap(ss[0][0], ss[0][1]);
        swap(ss[1][1], ss[1][0]);
        for (int j = 1; j <= n; j++) ans[j].push_back(ss[i % 2][j % 2]);
        swap(ss[0][0], ss[0][1]);
        swap(ss[1][1], ss[1][0]);
      }
    }
    for (int i = 1; i <= n; i++) {
      for (auto j : ans[i]) cout << j;
      puts("");
    }
  }
  return 0;
}
