#include <bits/stdc++.h>
static inline unsigned long long rdtsc() {
  unsigned long long d;
  __asm__ __volatile__("rdtsc" : "=A"(d));
  return d;
}
using namespace std;
const int inf = (int)1e9;
const double eps = 1e-9;
const int maxn = (int)1e5 + 10000;
const int maxm = 15;
const int L = 300;
char s[maxn][maxm];
int n, m;
int N;
int d[maxn][maxm];
void calc(int id) {
  for (int i = 0; (i) < (L); ++i) {
    int x = id * L + i;
    for (int j = 0; (j) < (m); ++j) d[x][j] = -1;
    if (s[x][0] == '<') d[x][0] = m + x;
    if (m > 0 && s[x][m - 1] == '>') d[x][m - 1] = m + n + x;
    for (int j = 0; (j) < (m); ++j)
      if (s[x][j] == '^') {
        if (i == 0)
          d[x][j] = j;
        else
          d[x][j] = d[x - 1][j];
      }
    for (int j = 1; j < m; ++j)
      if (s[x][j] == '<') d[x][j] = d[x][j - 1];
    for (int j = m - 2; j >= 0; --j)
      if (s[x][j] == '>') d[x][j] = d[x][j + 1];
  }
}
void init() {
  N = (n + L - 1) / L;
  for (int i = 0; (i) < (N); ++i) calc(i);
}
int GET(int x, int y) {
  while (x >= 0) {
    int next = d[x][y];
    if (next >= m || ~next) return next;
    int x2 = x - (x % L) - 1;
    int y2 = next;
    x = x2, y = y2;
  }
  return y;
}
pair<int, int> getPair(int x) {
  if (x == -1) return make_pair(-1, -1);
  if (x < m) return make_pair(0, x + 1);
  if (x < m + n) return make_pair(x - m + 1, 0);
  return make_pair(x - m - n + 1, m + 1);
}
int main() {
  memset(s, '^', sizeof s);
  int q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; (i) < (n); ++i) scanf("%s", s[i]);
  init();
  for (int i = 0; (i) < (q); ++i) {
    char t[2];
    scanf("%s", t);
    if (t[0] == 'A') {
      int x, y;
      scanf("%d%d", &x, &y);
      x -= 1, y -= 1;
      int id = GET(x, y);
      pair<int, int> res = getPair(id);
      printf("%d %d\n", res.first, res.second);
    } else if (t[0] == 'C') {
      int x, y;
      scanf("%d%d%s", &x, &y, t);
      x -= 1, y -= 1;
      s[x][y] = t[0];
      calc(x / L);
    }
  }
  return 0;
}
