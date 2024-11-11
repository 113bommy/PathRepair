#include <bits/stdc++.h>
using namespace std;
void fastIO() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
template <typename T, typename U>
inline void mnze(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void mxze(T &x, U y) {
  if (x < y) x = y;
}
void _scan(int &x) { scanf("%d", &x); }
void _scan(long long &x) { scanf("%lld", &x); }
void _scan(double &x) { scanf("%lf", &x); }
void _scan(char &x) { scanf(" %c", &x); }
void _scan(char *x) { scanf("%s", x); }
void scan() {}
template <typename T, typename... U>
void scan(T &head, U &...tail) {
  _scan(head);
  scan(tail...);
}
template <typename T>
void _dbg(const char *sdbg, T h) {
  cerr << sdbg << "=" << h << "\n";
}
template <typename T, typename... U>
void _dbg(const char *sdbg, T h, U... t) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << "=" << h << ",";
  _dbg(sdbg + 1, t...);
}
const int MAXN = 1e6 + 6;
int t, a[MAXN], cnt[MAXN];
int X = -1, Y = -1, N = -1, M = -1;
int MD;
int cnt2[MAXN];
void check(int x, int y, int n, int m) {
  if (X != -1) return;
  for (int i = 0; i < (int)MD + 1; i++) cnt2[i] = cnt[i];
  for (int r = 1; r < (int)m + 1; r++)
    for (int c = 1; c < (int)n + 1; c++) {
      int d = abs(r - y) + abs(c - x);
      if (cnt2[d] == 0) return;
      if (d > MD) return;
      cnt2[d]--;
    }
  X = x;
  Y = y;
  N = n;
  M = m;
}
int main() {
  scan(t);
  for (int i = 0; i < (int)t; i++) scan(a[i]), cnt[a[i]]++, mxze(MD, a[i]);
  if (cnt[0] != 1) {
    printf("-1\n");
    return 0;
  }
  int x = 1;
  while (cnt[x] == x * 4) x++;
  for (int n = x; n * n <= t; n++) {
    if (t % n == 0) {
      int m = t / n;
      int y = n - x + m - MD;
      if (y < 1) continue;
      if (y > m) continue;
      check(x, y, n, m);
    }
  }
  if (X == -1) {
    printf("-1\n");
  } else {
    printf("%d %d\n%d %d\n", N, M, X, Y);
  }
}
