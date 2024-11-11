#include <bits/stdc++.h>
char cc;
int C;
template <class T>
void read(T &x) {
  x = 0;
  C = 1;
  cc = getchar();
  while (!('0' <= cc && cc <= '9')) {
    if (cc == '-') C = -1;
    cc = getchar();
  }
  while (('0' <= cc && cc <= '9')) {
    x = x * 10 + cc - 48;
    cc = getchar();
  }
  x *= C;
}
using namespace std;
int e[100010 << 1], nxt[100010 << 1], fst[100010], e_tot;
void add_e(int x, int y) {
  static int &i = e_tot;
  e[i] = y;
  nxt[i] = fst[x];
  fst[x] = i++;
}
int siz[100010], n;
double dp[100010];
void dfs(int x, int f) {
  siz[x]++;
  for (int i = fst[x]; ~i; i = nxt[i]) {
    dfs(e[i], x);
    siz[x] += siz[e[i]];
  }
}
void solve(int x, int f) {
  dp[x] = dp[f] + 1 + (siz[f] - siz[x] - 1) * 1.0 / 2;
  for (int i = fst[x]; ~i; i = nxt[i]) solve(e[i], x);
}
void init() {
  memset(fst, -1, sizeof(fst));
  int fa;
  read(n);
  for (int i = 2; i <= n; ++i) {
    read(fa);
    add_e(fa, i);
  }
}
int main() {
  init();
  dfs(1, 0);
  siz[0] = siz[1] + 1;
  solve(1, 0);
  for (int i = 1; i <= n; ++i) printf("%.2f ", dp[i]);
  return 0;
}
