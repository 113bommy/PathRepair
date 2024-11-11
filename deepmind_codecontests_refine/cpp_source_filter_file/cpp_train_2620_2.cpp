#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
inline char smax(A &a, const B &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename A, typename B>
inline char smin(A &a, const B &b) {
  return b < a ? a = b, 1 : 0;
}
template <typename I>
inline void read(I &x) {
  int f = 0, c;
  while (!isdigit(c = getchar())) c == '-' ? f = 1 : 0;
  x = c & 15;
  while (isdigit(c = getchar())) x = (x << 1) + (x << 3) + (c & 15);
  f ? x = -x : 0;
}
const int N = 1e5 + 7;
int n;
struct Matrix {
  int x1, y1, x2, y2;
} a[N];
struct Int {
  int l, r, id;
} b[N][4];
inline bool operator<(const Int &a, const Int &b) {
  return a.l < b.l || (a.l == b.l && a.id < b.id);
}
inline bool dfs(set<Int> s[4]) {
  if (s[0].size() <= 1) return 1;
  set<Int>::iterator it[4];
  int mx[4], len = s[0].size();
  for (int i = 0; i < 4; ++i) it[i] = s[i].begin(), mx[i] = -2e9;
  for (int i = 0; i < len; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (i && it[j]->l >= mx[j]) {
        set<Int> t[4];
        for (auto p = s[j].begin(); p != it[j];) {
          int id = (p++)->id;
          for (int k = 0; k < 4; ++k)
            s[k].erase(b[id][k]), t[k].insert(b[id][k]);
        }
        return dfs(t) && dfs(s);
      } else
        smax(mx[j], (it[j]++)->r);
    }
  }
  return 0;
}
inline void work() {
  set<Int> s[4];
  for (int i = 1; i <= n; ++i)
    b[i][0] = (Int){a[i].x1, a[i].x2, i},
    b[i][1] = (Int){-a[i].x2, -a[i].x1, i},
    b[i][2] = (Int){a[i].y1, a[i].y2, i},
    b[i][3] = (Int){-a[i].y2, -a[i].x1, i}, s[0].insert(b[i][0]),
    s[1].insert(b[i][1]), s[2].insert(b[i][2]), s[3].insert(b[i][3]);
  if (dfs(s))
    puts("Yes");
  else
    puts("No");
}
inline void init() {
  read(n);
  for (int i = 1; i <= n; ++i)
    read(a[i].x1), read(a[i].y1), read(a[i].x2), read(a[i].y2);
}
int main() {
  init();
  work();
  fclose(stdin), fclose(stdout);
  return 0;
}
