#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int n = 0;
  char c;
  for (c = getchar(); c < '0' || c > '9'; c = getchar())
    ;
  for (; c >= '0' && c <= '9'; c = getchar())
    n = (n << 1) + (n << 3) + (c & 15);
  return n;
}
void pint(int x) {
  if (x >= 10) pint(x / 10);
  putchar(x % 10 + 48);
}
const int N = 2e5 + 5;
int i, j, n, idx, t, id[N], L, R;
int in[2][N], ou[2][N], u[2][N], v[2][N];
vector<int> g[2][N];
vector<int> t1[2][N << 2], t2[2][N << 2];
int num, an[N], cnt, ans[N];
bool bz[2][N];
void dfs(int t, int x, int fa) {
  in[t][x] = ++num;
  for (int i = 0; i < g[t][x].size(); i++) {
    int y = g[t][x][i];
    if (y != fa) dfs(t, y, x);
  }
  ou[t][x] = num;
}
bool cmp1(int x, int y) { return in[t ^ 1][v[t][x]] < in[t ^ 1][v[t][y]]; }
bool cmp2(int x, int y) { return in[t ^ 1][u[t][x]] > in[t ^ 1][u[t][y]]; }
void ins1(int k, int l, int r, int x, int id) {
  t1[t][k].push_back(id);
  if (l == r) return;
  int m = (l + r) >> 1, lk = k << 1, rk = lk + 1;
  if (x <= m)
    ins1(lk, l, m, x, id);
  else
    ins1(rk, m + 1, r, x, id);
}
void ins2(int k, int l, int r, int x, int id) {
  t2[t][k].push_back(id);
  if (l == r) return;
  int m = (l + r) >> 1, lk = k << 1, rk = lk + 1;
  if (x <= m)
    ins2(lk, l, m, x, id);
  else
    ins2(rk, m + 1, r, x, id);
}
void add(int t, int x) {
  if (!bz[t][x]) bz[t][x] = 1, ans[++cnt] = x;
}
void find1(int k, int l, int r) {
  if (L <= l && r <= R) {
    for (; !t1[t ^ 1][k].empty();) {
      int now = t1[t ^ 1][k].back();
      if (in[t][v[t ^ 1][now]] > R)
        add(t ^ 1, now), t1[t ^ 1][k].pop_back();
      else
        break;
    }
    return;
  }
  int m = (l + r) >> 1, lk = k << 1, rk = lk + 1;
  if (L <= m) find1(lk, l, m);
  if (R > m) find1(rk, m + 1, r);
}
void find2(int k, int l, int r) {
  if (L <= l && r <= R) {
    for (; !t2[t ^ 1][k].empty();) {
      int now = t2[t ^ 1][k].back();
      if (in[t][u[t ^ 1][now]] < L)
        add(t ^ 1, now), t2[t ^ 1][k].pop_back();
      else
        break;
    }
    return;
  }
  int m = (l + r) >> 1, lk = k << 1, rk = lk + 1;
  if (L <= m) find2(lk, l, m);
  if (R > m) find2(rk, m + 1, r);
}
int main() {
  n = read();
  for (t = 0; t <= 1; t++)
    for (i = 2; i <= n; i++) {
      j = read(), g[t][i].push_back(j), g[t][j].push_back(i);
      id[i - 1] = i - 1, u[t][i - 1] = i, v[t][i - 1] = j;
    }
  dfs(0, 1, 0);
  num = 0, dfs(1, 1, 0);
  for (t = 0; t <= 1; t++) {
    for (i = 1; i <= n - 1; i++)
      if (in[t ^ 1][u[t][i]] > in[t ^ 1][v[t][i]]) swap(u[t][i], v[t][i]);
    sort(id + 1, id + n, cmp1);
    for (j = 1; j <= n - 1; j++) {
      i = id[j];
      ins1(1, 1, n, in[t ^ 1][u[t][i]], i);
    }
    sort(id + 1, id + n, cmp2);
    for (j = 1; j <= n - 1; j++) {
      i = id[j];
      ins2(1, 1, n, in[t ^ 1][v[t][i]], i);
    }
  }
  idx = read();
  bz[0][idx] = 1, an[num = 1] = idx;
  for (t = 0; num; t ^= 1) {
    cnt = 0;
    if (!t)
      puts("Blue");
    else
      puts("Red");
    for (j = 1; j <= num; j++) {
      i = an[j];
      pint(i), putchar(j < num ? ' ' : '\n');
      int x = u[t][i], y = v[t][i];
      if (in[t][x] < in[t][y]) swap(x, y);
      L = in[t][x], R = ou[t][x];
      find1(1, 1, n), find2(1, 1, n);
    }
    num = cnt, cnt = 0;
    for (i = 1; i <= num; i++) an[i] = ans[i];
    sort(an + 1, an + 1 + num);
  }
}
