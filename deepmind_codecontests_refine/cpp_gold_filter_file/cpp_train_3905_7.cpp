#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
struct AC {
  static const int mxv = 50011, mxc = 10;
  int e[mxv][mxc], f[mxv], sz;
  vector<int> que;
  bool Ky[mxv];
  int NEW() {
    ++sz, f[sz] = 0, Ky[sz] = 0;
    memset(e[sz], 0, sizeof(e[sz]));
    return sz;
  }
  void clear() {
    sz = -1;
    NEW();
    NEW();
    fill(e[0], e[0] + mxc, 1);
  }
  int add(int x, char c) { return e[x][c] ? e[x][c] : e[x][c] = NEW(); }
  void build() {
    que = {1};
    for (int i = 0; i < que.size(); ++i) {
      int x = que[i];
      for (int c = 0; c < mxc; ++c)
        if (e[x][c])
          f[e[x][c]] = e[f[x]][c], que.push_back(e[x][c]);
        else
          e[x][c] = e[f[x]][c];
    }
  }
} T;
int f[2][AC::mxv][2][2][2];
void update(int &x, int y) {
  x += y;
  if (x >= p) x -= p;
}
char s[1011], s1[1011], s2[1011];
int main() {
  scanf("%s%s%s", s, s1, s2);
  int n = strlen(s), m = strlen(s1), md2 = m / 2;
  for (int i = 0; i < m; ++i) s1[i] -= '0', s2[i] -= '0';
  T.clear();
  for (int i = 0; i + md2 - 1 < n; ++i) {
    int now = 1;
    for (int j = 0; j < md2; ++j) now = T.add(now, s[i + j] - '0');
    T.Ky[now] = 1;
  }
  T.build();
  f[0][1][1][1][0] = 1;
  int now = 0, next = 1;
  for (int i = 0; i < m; ++i) {
    memset(f[next], 0, sizeof(f[next]));
    for (int x = 1; x <= T.sz; ++x)
      for (int d0 = 0; d0 <= 1; ++d0)
        for (int d1 = 0; d1 <= 1; ++d1)
          for (int tg = 0; tg <= 1; ++tg) {
            int l = 0, r = 9;
            if (d0) l = s1[i];
            if (d1) r = s2[i];
            for (int d = l; d <= r; ++d) {
              int d0_ = d0 && (d == s1[i]), d1_ = d1 && (d == s2[i]),
                  x_ = T.e[x][d], tg_ = tg || T.Ky[x_];
              update(f[next][x_][d0_][d1_][tg_], f[now][x][d0][d1][tg]);
            }
          }
    swap(now, next);
  }
  int ans = 0;
  for (int x = 1; x <= T.sz; ++x)
    for (int d0 = 0; d0 <= 1; ++d0)
      for (int d1 = 0; d1 <= 1; ++d1) update(ans, f[now][x][d0][d1][1]);
  printf("%d\n", ans);
}
