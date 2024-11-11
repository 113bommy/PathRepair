#include <bits/stdc++.h>
using namespace std;
void fre() {
  freopen("c://test//input.in", "r", stdin);
  freopen("c://test//output.out", "w", stdout);
}
template <class T1, class T2>
inline void gmax(T1 &a, T2 b) {
  if (b > a) a = b;
}
template <class T1, class T2>
inline void gmin(T1 &a, T2 b) {
  if (b < a) a = b;
}
const int N = 50 + 2, M = 50 + 2, S = 1 << 20, Z = 1e9 + 7, ms63 = 1061109567;
int n, m;
long long b[N];
char s[N][M];
long long w[N][M];
int num1[S];
int lst1[S];
long long fix[S];
long long f[S];
double p[S];
void solve() {
  for (int i = 0; i <= 50; ++i) b[i] = 1ll << i;
  for (int pos = 0; pos < m; ++pos) {
    for (int i = 0; i < n; ++i) {
      w[i][pos] = 0;
      for (int j = 0; j < n; ++j)
        if (s[j][pos] == s[i][pos]) w[i][pos] |= b[j];
    }
  }
  int top = 1 << m;
  for (int sta = 0; sta < top; ++sta) {
    num1[sta] = 0;
    lst1[sta] = -1;
    for (int x = sta, p = 0; x; x >>= 1, ++p) {
      num1[sta] += x & 1;
      if ((x & 1) && lst1[sta] == -1) lst1[sta] = p;
    }
  }
  memset(fix, 0, sizeof(fix));
  for (int i = 0; i < n; ++i) {
    f[0] = b[n] - 1;
    for (int sta = 1; sta < top; ++sta) {
      int pos = lst1[sta];
      f[sta] = f[sta ^ b[pos]] & w[i][pos];
      if (f[sta] == b[i]) fix[sta] |= b[i];
    }
  }
  memset(p, 0, sizeof(p));
  p[0] = 1;
  double ans = 0;
  for (int sta = 0; sta < top - 1; ++sta) {
    double prb = p[sta] / (m - num1[sta]);
    for (int i = 0; i < m; ++i)
      if (!(sta & b[i])) {
        int nxt = sta | b[i];
        p[nxt] += prb;
        ans += prb * __builtin_popcountll(fix[nxt] ^ fix[sta]) * num1[nxt];
      }
  }
  if (n == 1) ans = 1;
  printf("%.15f\n", ans / n);
}
int main() {
  while (~scanf("%d", &n)) {
    for (int i = 0; i < n; ++i) scanf("%s", s[i]);
    m = strlen(s[0]);
    solve();
  }
  return 0;
}
