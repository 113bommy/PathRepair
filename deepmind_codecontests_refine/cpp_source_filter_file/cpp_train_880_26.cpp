#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T& x) {
  char c;
  bool fu = 0;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') fu = 1, c = getchar();
  for (x = 0; c > 32; c = getchar()) x = x * 10 + c - '0';
  if (fu) x *= -1;
}
template <class T>
inline void read(T& x, T& y) {
  read(x);
  read(y);
}
template <class T>
inline void read(T& x, T& y, T& z) {
  read(x, y);
  read(z);
}
const int INF = 1 << 30;
const int N = 1222222;
int T[N], len;
void modify(int x, int v) {
  T[x + len] = v;
  for (int i = (x + len) >> 1; i; i >>= 1) T[i] = max(T[i << 1], T[i << 1 | 1]);
}
int ask(int l, int r) {
  int an = 0;
  for (l = l + len - 1, r = r + len + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
    if (~l & 1) an = max(an, T[l ^ 1]);
    if (r & 1) an = max(an, T[r ^ 1]);
  }
  return an;
}
vector<int> q1[N], q2[N], p2[N], p1[N];
int col[N], row[N], lx[N], rx[N], ly[N], ry[N], ans[N];
int R, C, n, m;
int main() {
  read(R, C);
  read(n, m);
  for (int _tmp = n, i = 1; i <= _tmp; ++i) {
    int x, y;
    read(x, y);
    col[y] = row[x] = 1;
    p1[x].push_back(y);
    p2[y].push_back(x);
  }
  for (int _tmp = R, i = 1; i <= _tmp; ++i) row[i] += row[i - 1];
  for (int _tmp = C, i = 1; i <= _tmp; ++i) col[i] += col[i - 1];
  for (int _tmp = m, i = 1; i <= _tmp; ++i) {
    read(lx[i], ly[i]);
    read(rx[i], ry[i]);
    q1[lx[i]].push_back(i);
    q2[ly[i]].push_back(i);
  }
  for (len = 1; len - 5 < C; len <<= 1)
    ;
  fill(T + 1, T + len + len + 1, INF);
  for (int _tmp = 1, i = R; i >= _tmp; --i) {
    for (__typeof p1[i].begin() x = p1[i].begin(); x != p1[i].end(); ++x)
      modify(*x, i);
    for (__typeof q1[i].begin() x = q1[i].begin(); x != q1[i].end(); ++x)
      if (ask(ly[*x], ry[*x]) <= rx[*x]) ans[*x] = 1;
  }
  for (len = 1; len - 5 < R; len <<= 1)
    ;
  fill(T + 1, T + len + len + 1, INF);
  for (int _tmp = 1, i = C; i >= _tmp; --i) {
    for (__typeof p2[i].begin() x = p2[i].begin(); x != p2[i].end(); ++x)
      modify(*x, i);
    for (__typeof q2[i].begin() x = q2[i].begin(); x != q2[i].end(); ++x)
      if (ask(ly[*x], ry[*x]) <= rx[*x]) ans[*x] = 1;
  }
  for (int _tmp = m, i = 1; i <= _tmp; ++i) (ans[i]) ? puts("YES") : puts("NO");
  return 0;
}
