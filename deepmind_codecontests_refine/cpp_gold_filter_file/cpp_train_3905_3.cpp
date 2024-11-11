#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 25005;
int fail[N], t[N][10], f[55][N];
char s[N], x[N], y[N];
int n, d, m, sz = 2;
void ins(char s[], int len) {
  int o = 1;
  for (int i = (1); i <= (len - 1); i++) {
    if (!t[o][s[i] - '0']) t[o][s[i] - '0'] = ++sz;
    o = t[o][s[i] - '0'];
  }
  t[o][s[len] - '0'] = 2;
}
void build() {
  static int q[N];
  int l = 0, r = 0;
  fail[1] = 1;
  for (int k = (0); k < (10); k++) {
    if (t[1][k])
      q[r++] = t[1][k], fail[t[1][k]] = 1;
    else
      t[1][k] = 1;
    t[2][k] = 2;
  }
  while (l < r) {
    int u = q[l++];
    for (int k = (0); k < (10); k++)
      if (!t[u][k])
        t[u][k] = t[fail[u]][k];
      else if (t[u][k] != 2) {
        fail[t[u][k]] = t[fail[u]][k];
        q[r++] = t[u][k];
      }
  }
}
inline void add(int &x, int y) { x = (x + y >= mod ? x + y - mod : x + y); }
int solve(char c[]) {
  int now = 1, res = 0;
  for (int i = (1); i <= (d); i++) {
    memset(f[i - 1], 0, sizeof f[i - 1]);
    f[i - 1][now] = 1;
    for (int j = (i); j <= (d); j++) {
      memset(f[j], 0, sizeof f[j]);
      for (int s = (1); s <= (sz); s++)
        if (f[j - 1][s]) {
          int lim = (j == i ? c[j] - '0' - 1 + (i == d) : 9);
          for (int k = (0); k <= (lim); k++) add(f[j][t[s][k]], f[j - 1][s]);
        }
    }
    add(res, f[d][2]);
    now = t[now][c[i] - '0'];
  }
  return res;
}
int main() {
  scanf("%s%s%s", s + 1, x + 1, y + 1);
  n = strlen(s + 1);
  d = strlen(x + 1), m = d / 2;
  for (int i = (0); i <= (n - m); i++) ins(s + i, m);
  build();
  int k = d;
  while (x[k] == '0') x[k--] = '9';
  x[k]--;
  printf("%d\n", (solve(y) - solve(x) + mod) % mod);
  return 0;
}
