#include <bits/stdc++.h>
using namespace std;
int n, m, L1[35], L2[35];
vector<int> vec[35];
int f[22][17000][32];
int g[22][17000][32];
int tr[32][32], P[32];
char ans[55][55];
void init() {
  for (int i = (int)(0); i <= (int)((1 << n) - 1); i++) {
    int sum = 0;
    for (int j = (int)(0); j <= (int)(n - 1); j++)
      if ((i & (1 << j)) == (1 << j)) sum++;
    for (int j = (int)(0); j <= (int)(n - 2); j++)
      if ((i & (3 << j)) == (3 << j)) sum--;
    vec[sum].push_back(i);
  }
  P[0] = 1;
  for (int i = (int)(1); i <= (int)(n); i++) P[i] = 1ll * P[i - 1] * 7;
  for (int i = (int)(0); i <= (int)((1 << n) - 1); i++)
    for (int j = (int)(0); j <= (int)((1 << n) - 1); j++)
      for (int k = (int)(0); k <= (int)(n - 1); k++)
        if ((j & (1 << k)) && !(i & (1 << k))) tr[i][j] += P[k];
}
void construct(int p, int s1, int s2, int la) {
  for (int i = (int)(0); i <= (int)(n - 1); i++)
    for (int j = (int)(1); j <= (int)(m); j++) ans[i][j] = '.';
  for (int pp = p, S = s1, st = la; pp; pp--) {
    for (int i = (int)(0); i <= (int)(n - 1); i++)
      if (st & (1 << i)) ans[i][pp] = '*';
    int tmp = f[pp][S][st];
    S -= tr[tmp][st];
    st = tmp;
  }
  for (int pp = p, S = s2, st = la; pp <= m; pp++) {
    for (int i = (int)(0); i <= (int)(n - 1); i++)
      if (st & (1 << i)) ans[i][pp] = '*';
    int tmp = g[pp][S][st];
    S -= tr[tmp][st];
    st = tmp;
  }
  for (int i = (int)(0); i <= (int)(n - 1); i++) printf("%s\n", ans[i] + 1);
  exit(0);
}
int main() {
  scanf("%d%d", &n, &m);
  init();
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%d", &L1[i]);
  for (int i = (int)(1); i <= (int)(m); i++) scanf("%d", &L2[i]);
  int mid = (m + 1) / 2;
  memset(f, -1, sizeof(f));
  memset(g, -1, sizeof(g));
  f[0][0][0] = 0;
  g[m + 1][0][0] = 0;
  for (int i = (int)(1); i <= (int)(mid); i++)
    for (int j = (int)(0); j <= (int)(P[n] - 1); j++)
      for (auto la : vec[L2[i - 1]])
        if (f[i - 1][j][la] != -1)
          for (auto no : vec[L2[i]]) f[i][j + tr[la][no]][no] = la;
  for (int i = (int)(m); i >= (int)(mid); i--)
    for (int j = (int)(0); j <= (int)(P[n] - 1); j++)
      for (auto la : vec[L2[i + 1]])
        if (g[i + 1][j][la] != -1)
          for (auto no : vec[L2[i]]) g[i][j + tr[la][no]][no] = la;
  for (int j = (int)(0); j <= (int)(P[n] - 1); j++)
    for (auto la : vec[L2[mid]])
      if (f[mid][j][la] != -1) {
        int flg = 0, now = 0;
        for (int k = (int)(0); k <= (int)(n - 1); k++) {
          int v = j / P[k] % 7;
          v = L1[k + 1] + ((la >> k) & 1) - v;
          if (v >= 0 && v <= 6)
            now += P[k] * v;
          else
            flg = 1;
        }
        if (flg == 1 || g[mid][now][la] == -1) break;
        construct(mid, j, now, la);
      }
}
