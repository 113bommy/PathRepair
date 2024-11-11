#include <bits/stdc++.h>
using namespace std;
const int a1[8] = {-1, -1, -1, 0, 0, 1, 1, 1},
          a2[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int i, j, k, n, m, _, num;
int a[40][40], b[40][40], s[1000], ff[40][40], h[40][40];
pair<int, int> O, g[40 * 40];
vector<pair<int, int> > an, tmp;
map<pair<int, int>, pair<int, int> > fa;
map<pair<int, int>, int> gg;
inline bool ju(int a[40], int b[40]) {
  int i;
  for (i = 1; i <= m; i++)
    if (a[i] != b[i]) return 0;
  return 1;
}
inline void print(int _, int x, int y) {
  if (_) swap(x, y);
  printf("%d %d\n", x, y);
}
inline void work1(int _) {
  for (i = 1; i <= m; i++) {
    for (j = 1; j <= i - 1; j++) {
      int h[40];
      for (k = 1; k <= j - 1; k++) h[k] = a[1][k];
      h[j] = a[1][i];
      for (k = j; k <= i - 1; k++) h[k + 1] = a[1][k];
      for (k = i + 1; k <= m; k++) h[k] = a[1][k];
      if (ju(h, b[1])) {
        printf("%d\n", i - j);
        for (k = i; k >= j; k--) print(_, 1, k);
        exit(0);
      }
    }
    for (j = i + 1; j <= m; j++) {
      int h[40];
      for (k = 1; k <= i - 1; k++) h[k] = a[1][k];
      for (k = i; k <= j - 1; k++) h[k] = a[1][k + 1];
      h[j] = a[1][i];
      for (k = j + 1; k <= m; k++) h[k] = a[1][k];
      if (ju(h, b[1])) {
        printf("%d\n", j - i);
        for (k = i; k <= j; k++) print(_, 1, k);
        exit(0);
      }
    }
  }
  printf("-1\n");
  exit(0);
}
inline void rev() {
  int i, j, c[40][40], d[40][40];
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) c[j][i] = a[i][j], d[j][i] = b[i][j];
  swap(n, m);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) a[i][j] = c[i][j], b[i][j] = d[i][j];
  _ ^= 1;
  swap(O.first, O.second);
}
inline void jin(pair<int, int> O) {
  if (_) swap(O.first, O.second);
  an.push_back(O);
}
inline void print() {
  int i;
  printf("%d\n", an.size() - 1);
  for (i = 0; i < an.size(); i++) printf("%d %d\n", an[i].first, an[i].second);
}
inline void dong(pair<int, int> &u) {
  jin(u);
  swap(O, u);
  swap(a[O.first][O.second], a[u.first][u.second]);
}
void dfs(pair<int, int> O, pair<int, int> now) {
  if (O == now) return;
  dfs(O, fa[now]);
  dong(now);
}
inline void bfs(pair<int, int> O, pair<int, int> goal) {
  int l, r, i;
  g[l = r = 1] = O;
  gg.clear();
  gg[O] = 0;
  for (; l <= r; l++) {
    pair<int, int> A = g[l];
    if (A == goal) {
      dfs(O, goal);
      return;
    }
    for (i = 0; i <= 7; i++) {
      int x = A.first + a1[i], y = A.second + a2[i];
      pair<int, int> u = make_pair(x, y);
      if (x && y && x <= n && y <= m && !ff[x][y])
        if (!gg.count(u)) {
          gg[u] = gg[A] + 1;
          fa[u] = A;
          g[++r] = u;
        }
    }
  }
}
inline void gao(pair<int, int> O, pair<int, int> goal) {
  ++num;
  tmp.clear();
  bfs(O, goal);
}
inline void zou(pair<int, int> u, pair<int, int> goal) {
  for (; u.second < m;) {
    ff[u.first][u.second] = 1;
    gao(O, make_pair(u.first, u.second + 1));
    ff[u.first][u.second] = 0;
    dong(u);
  }
  for (; u.first < n;) {
    ff[u.first][u.second] = 1;
    gao(O, make_pair(u.first + 1, u.second));
    ff[u.first][u.second] = 0;
    dong(u);
  }
  for (; u.second > goal.second;) {
    ff[u.first][u.second] = 1;
    gao(O, make_pair(u.first, u.second - 1));
    ff[u.first][u.second] = 0;
    dong(u);
  }
}
inline void work() {
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (a[i][j] == b[1][1]) {
        O = make_pair(i, j);
        a[i][j] = 0;
        goto yes;
      }
yes:;
  jin(O);
  for (;;) {
    if (n < m) rev();
    if (n == 1) break;
    memset(ff, 0, sizeof(ff));
    for (i = 1; i <= m; i++) {
      pair<int, int> w;
      for (j = 1; j <= n; j++)
        for (k = 1; k <= m; k++)
          if (!ff[j][k] && a[j][k] == b[n][i]) {
            w = make_pair(j, k);
            goto jie;
          }
    jie:;
      zou(w, make_pair(n, i));
      ff[n][i] = 1;
    }
    n--;
  }
  print();
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) scanf("%d", &a[i][j]), s[a[i][j]]++;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) scanf("%d", &b[i][j]), s[b[i][j]]--;
  for (i = 1; i <= 900; i++)
    if (s[i]) {
      printf("-1\n");
      return 0;
    }
  if (n == 1) work1(0);
  if (m == 1) {
    for (i = 1; i <= n; i++) swap(a[i][1], a[1][i]), swap(b[i][1], b[1][i]);
    swap(n, m);
    work1(1);
  }
  work();
  return 0;
}
