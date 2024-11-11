#include <bits/stdc++.h>
using namespace std;
const int iinf = 1e9 + 7;
const long long linf = 1ll << 60;
const double dinf = 1e10;
template <typename T>
inline void scf(T &x) {
  bool f = 0;
  x = 0;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') {
    f = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  if (f) x = -x;
  return;
}
template <typename T1, typename T2>
void scf(T1 &x, T2 &y) {
  scf(x);
  return scf(y);
}
template <typename T1, typename T2, typename T3>
void scf(T1 &x, T2 &y, T3 &z) {
  scf(x);
  scf(y);
  return scf(z);
}
const int N = 1e5 + 100;
int n, m;
vector<int> g[10][N];
int dst0[N], dst[N], prevv[N];
int q[N], tq[N], rar, trar, totlen = iinf;
deque<int> ans1, ans2;
void bfs() {
  memset(dst0, -1, sizeof(dst0));
  dst0[0] = 0;
  int fnt, rar;
  fnt = rar = 0;
  q[rar++] = 0;
  while (fnt != rar) {
    int u = q[fnt++];
    for (int _ = 0; _ < (10); _++)
      for (auto v : g[_][u])
        if (dst0[v] < 0) dst0[v] = dst0[u] + 1, q[rar++] = v;
  }
  return;
}
void bfs0() {
  memset(dst, -1, sizeof(dst));
  dst[n - 1] = 0;
  int fnt, rar;
  fnt = rar = 0;
  q[rar++] = n - 1;
  while (fnt != rar) {
    int u = q[fnt++];
    for (auto v : g[0][u])
      if (dst[v] < 0) dst[v] = dst[u] + 1, q[rar++] = v, prevv[v] = u;
  }
  return;
}
int main() {
  scf(n, m);
  for (int i = 0; i < (m); i++) {
    int u, v, w;
    scf(u, v, w);
    g[w][u].push_back(v);
    g[w][v].push_back(u);
  }
  bfs();
  bfs0();
  if (dst[0] != -1) {
    puts("0");
    printf("%d\n", dst[0] + 1);
    int u = 0;
    while (u != n - 1) printf("%d ", u), u = prevv[u];
    printf("%d\n", n - 1);
    return 0;
  }
  for (int i = 0; i < (n); i++)
    if (dst[i] != -1) q[rar++] = i;
  for (int i = 0; i < (rar); i++) {
    int u = q[i];
    for (int _ = (1); _ <= (9); _++)
      for (auto v : g[_][u])
        if (dst[v] < 0 && dst0[v] < totlen) totlen = dst0[v];
  }
  int col = 10;
  for (int i = 0; i < (rar); i++) {
    int u = q[i];
    for (int _ = (1); _ <= (9); _++) {
      bool f = 0;
      for (auto v : g[_][u])
        if (dst[v] < 0 && dst0[v] == totlen) {
          f = 1;
          break;
        }
      if (f) {
        if (_ < col) col = _;
        break;
      }
    }
  }
  for (int i = 0; i < (rar); i++) {
    int u = q[i];
    for (auto v : g[col][u])
      if (dst0[v] == totlen) {
        if (dst[v] < 0)
          tq[trar++] = v, dst[v] = dst[u] + 1, prevv[v] = u;
        else if (dst[v] > dst[u] + 1)
          dst[v] = dst[u] + 1, prevv[v] = u;
      }
  }
  rar = trar;
  for (int i = 0; i < (trar); i++) q[i] = tq[i];
  while (totlen) {
    totlen--;
    int col = 10;
    for (int i = 0; i < (rar); i++) {
      int u = q[i];
      for (int _ = 0; _ < (10); _++) {
        bool f = 0;
        for (auto v : g[_][u])
          if (dst[v] < 0 && dst0[v] == totlen) {
            f = 1;
            break;
          }
        if (f) {
          if (_ < col) col = _;
          break;
        }
      }
    }
    trar = 0;
    for (int i = 0; i < (rar); i++) {
      int u = q[i];
      for (auto v : g[col][u])
        if (dst0[v] == totlen) {
          if (dst[v] < 0)
            tq[trar++] = v, dst[v] = dst[u] + 1, prevv[v] = u;
          else if (dst[v] > dst[u] + 1)
            dst[v] = dst[u] + 1, prevv[v] = u;
        }
    }
    rar = trar;
    for (int i = 0; i < (trar); i++) q[i] = tq[i];
  }
  int u = 0;
  while (u != n - 1) {
    bool f = 0;
    for (int _ = 0; _ < (10); _++) {
      for (auto v : g[_][u])
        if (v == prevv[u]) {
          ans1.push_back(_);
          f = 1;
          break;
        }
      if (f) break;
    }
    ans2.push_back(prevv[u]);
    u = prevv[u];
  }
  reverse(ans1.begin(), ans1.end());
  while ((int)ans1.size() && ans1.front() == 0) ans1.pop_front();
  for (auto x : ans1) printf("%d", x);
  printf("\n%d\n0", dst[0] + 1);
  for (auto x : ans2) printf(" %d", x);
  putchar('\n');
  return 0;
}
