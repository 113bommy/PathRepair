#include <bits/stdc++.h>
using namespace std;
void getint(int &v) {
  char ch, fu = 0;
  for (ch = '*'; (ch < '0' || ch > '9') && ch != '-'; ch = getchar())
    ;
  if (ch == '-') fu = 1, ch = getchar();
  for (v = 0; ch >= '0' && ch <= '9'; ch = getchar()) v = v * 10 + ch - '0';
  if (fu) v = -v;
}
const int MO = 1e9 + 7;
vector<pair<int, int> > a[200010];
vector<int> M[2][2];
int n, m, k, x, y, top, D, tmp[4], tag, bl, F[200010], g[200010], stk[200010],
    G[200010][2], tp, d[200010], f[200010][2][2];
bool v[200010], flag;
void find(int x) {
  v[x] = 1;
  stk[++top] = x;
  for (int i = 0; i < a[x].size(); ++i) {
    int y = a[x][i].first;
    if (!v[y]) find(y);
  }
}
void chain() {
  for (int i = 1; i <= top; ++i) v[stk[i]] = 0;
  for (int i = 1; i <= top; ++i)
    if (d[stk[i]] == 1 || top == 1) D = stk[i];
  top = 0;
  find(D);
  for (int i = 0; i <= top; ++i)
    for (int j = 0; j <= 1; ++j)
      for (int k = 0; k <= 1; ++k) f[i][j][k] = 0;
  f[1][0][G[stk[1]][0]] = 1;
  f[1][1][G[stk[1]][1]] = 1;
  for (int i = 1; i <= top - 1; ++i)
    for (int j = 0; j <= 1; ++j)
      for (int k = 0; k <= 1; ++k)
        if (f[i][j][k]) {
          int x = stk[i], y = stk[i + 1];
          tmp[0] = tmp[1] = tmp[2] = tmp[3] = 0;
          for (int l = 0; l < a[x].size(); ++l)
            if (a[x][l].first == y) tmp[a[x][l].second] ^= 1;
          for (int l = 0; l <= 1; ++l) {
            int s = 0;
            for (int L = 0; L < M[j][l].size(); ++L) s ^= tmp[M[j][l][L]];
            (f[i + 1][l][k ^ s ^ G[y][l]] += f[i][j][k]) %= MO;
          }
        }
  F[0] = F[1] = 0;
  for (int l = 0; l <= 1; ++l)
    for (int p = 0; p <= 1; ++p) (F[p] += f[top][l][p]) %= MO;
  long long x = g[0], y = g[1];
  g[0] = (x * F[0] + y * F[1]) % MO;
  g[1] = (x * F[1] + y * F[0]) % MO;
}
void circle() {
  for (int i = 0; i <= top; ++i)
    for (int j = 0; j <= 1; ++j)
      for (int k = 0; k <= 1; ++k) f[i][j][k] = 0;
  f[1][0][G[stk[1]][0]] = 1;
  for (int i = 1; i <= top - 1; ++i)
    for (int j = 0; j <= 1; ++j)
      for (int k = 0; k <= 1; ++k)
        if (f[i][j][k]) {
          int x = stk[i], y = stk[i + 1];
          tmp[0] = tmp[1] = tmp[2] = tmp[3] = 0;
          for (int l = 0; l < a[x].size(); ++l)
            if (a[x][l].first == y) tmp[a[x][l].second] ^= 1;
          for (int l = 0; l <= 1; ++l) {
            int s = 0;
            for (int L = 0; L < M[j][l].size(); ++L) s ^= tmp[M[j][l][L]];
            (f[i + 1][l][k ^ s ^ G[y][l]] += f[i][j][k]) %= MO;
          }
        }
  tmp[0] = tmp[1] = tmp[2] = tmp[3] = 0;
  for (int i = 0; i < a[stk[top]].size(); ++i)
    if (a[stk[top]][i].first == stk[1]) {
      tmp[a[stk[top]][i].second] ^= 1;
    }
  F[0] = F[1] = 0;
  for (int l = 0; l <= 1; ++l)
    for (int p = 0; p <= 1; ++p) {
      int s = 0;
      for (int L = 0; L < M[l][0].size(); ++L) s ^= tmp[M[l][0][L]];
      (F[p ^ s] += f[top][l][p]) %= MO;
    }
  for (int i = 0; i <= top; ++i)
    for (int j = 0; j <= 1; ++j)
      for (int k = 0; k <= 1; ++k) f[i][j][k] = 0;
  f[1][1][G[stk[1]][1]] = 1;
  for (int i = 1; i <= top - 1; ++i)
    for (int j = 0; j <= 1; ++j)
      for (int k = 0; k <= 1; ++k)
        if (f[i][j][k]) {
          int x = stk[i], y = stk[i + 1];
          tmp[0] = tmp[1] = tmp[2] = tmp[3] = 0;
          for (int l = 0; l < a[x].size(); ++l)
            if (a[x][l].first == y) tmp[a[x][l].second] ^= 1;
          for (int l = 0; l <= 1; ++l) {
            int s = 0;
            for (int L = 0; L < M[j][l].size(); ++L) s ^= tmp[M[j][l][L]];
            (f[i + 1][l][k ^ s ^ G[y][l]] += f[i][j][k]) %= MO;
          }
        }
  tmp[0] = tmp[1] = tmp[2] = tmp[3] = 0;
  for (int i = 0; i < a[stk[top]].size(); ++i)
    if (a[stk[top]][i].first == stk[1]) {
      tmp[a[stk[top]][i].second] ^= 1;
    }
  for (int l = 0; l <= 1; ++l)
    for (int p = 0; p <= 1; ++p) {
      int s = 0;
      for (int L = 0; L < M[l][1].size(); ++L) s ^= tmp[M[l][1][L]];
      (F[p ^ s] += f[top][l][p]) %= MO;
    }
  long long x = g[0], y = g[1];
  g[0] = (x * F[0] + y * F[1]) % MO;
  g[1] = (x * F[1] + y * F[0]) % MO;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    getint(k);
    if (k == 2) {
      getint(x), getint(y);
      if (abs(x) == abs(y)) {
        if (x == y && x > 0)
          G[x][1] ^= 1;
        else if (x == y && x < 0)
          G[-x][0] ^= 1;
        else
          tag ^= 1;
        continue;
      }
      flag = 0;
      for (int p = 0; p < a[abs(x)].size(); ++p)
        if (a[abs(x)][p].first == abs(y)) flag = 1;
      if (!flag) d[abs(x)]++, d[abs(y)]++;
      if (x < 0 && y < 0)
        tp = 1;
      else if (x < 0 && y > 0)
        tp = 2;
      else if (x > 0 && y < 0)
        tp = 3;
      else
        tp = 0;
      a[abs(x)].push_back(make_pair(abs(y), tp));
      swap(x, y);
      if (x < 0 && y < 0)
        tp = 1;
      else if (x < 0 && y > 0)
        tp = 2;
      else if (x > 0 && y < 0)
        tp = 3;
      else
        tp = 0;
      a[abs(x)].push_back(make_pair(abs(y), tp));
    } else {
      getint(x);
      if (x > 0)
        G[x][1] ^= 1;
      else
        G[x][0] ^= 1;
    }
  }
  M[0][0].push_back(1), M[0][0].push_back(2), M[0][0].push_back(3);
  M[0][1].push_back(2), M[0][1].push_back(1), M[0][1].push_back(0);
  M[1][0].push_back(0), M[1][0].push_back(3), M[1][0].push_back(1);
  M[1][1].push_back(0), M[1][1].push_back(2), M[1][1].push_back(3);
  g[0] = 1;
  for (int i = 1; i <= m; ++i)
    if (!v[i]) {
      top = 0;
      ++bl;
      find(i);
      flag = 0;
      for (int j = 1; j <= top; ++j)
        if (d[stk[j]] == 1) flag = 1;
      if (flag || top < 3)
        chain();
      else
        circle();
    }
  cout << g[1 ^ tag] << endl;
  return 0;
}
