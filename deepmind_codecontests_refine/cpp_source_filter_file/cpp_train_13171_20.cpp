#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
vector<int> g[maxn + 1];
int father[maxn + 1], a[maxn + 1];
int f[maxn + 1], fup[maxn + 1];
int n, K;
int result;
int ge[maxn + 1], upge[maxn + 1];
int MIN;
void init() {
  int i, x, y;
  scanf("%d%d", &n, &K);
  for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (i = 1; i < n; ++i) {
    scanf("%d%d", &x, &y);
    g[x].push_back(y);
    g[y].push_back(x);
  }
}
void calc_ge(int p, int fa) {
  int i, j;
  father[p] = fa;
  ge[p] = 1;
  for (i = 0; i < g[p].size(); ++i) {
    j = g[p][i];
    if (j != fa) {
      calc_ge(j, p);
      ge[p] += ge[j];
    }
  }
}
void calc_f(int p) {
  int i, j, zd = 0, sum = 0;
  if ((g[p].size() == 1) && (father[p] == g[p][0])) {
    if (a[p] >= MIN)
      f[p] = 1;
    else
      f[p] = 0;
    return;
  }
  if (a[p] < MIN) {
    f[p] = 0;
    for (i = 0; i < g[p].size(); ++i) {
      j = g[p][i];
      if (j != father[p]) calc_f(j);
    }
    return;
  }
  for (i = 0; i < g[p].size(); ++i) {
    j = g[p][i];
    if (j != father[p]) {
      calc_f(j);
      if (f[j] == ge[j])
        sum += f[j];
      else {
        if (f[j] > zd) zd = f[j];
      }
    }
  }
  f[p] = 1 + sum + zd;
}
void calc_fup(int p) {
  int i, j, zd = 0, zd2 = 0, sum = 0;
  if ((g[p].size() == 1) && (father[p] == g[p][0])) return;
  if (a[p] < MIN) {
    for (i = 0; i < g[p].size(); ++i) {
      j = g[p][i];
      if (j != father[p]) {
        fup[j] = 0;
        calc_fup(j);
      }
    }
    return;
  }
  if (fup[p] == upge[p])
    sum = fup[p];
  else
    zd = fup[p];
  for (i = 0; i < g[p].size(); ++i) {
    j = g[p][i];
    if (j != father[p]) {
      if (f[j] == ge[j])
        sum += f[j];
      else {
        if (f[j] > zd) {
          zd2 = zd;
          zd = f[j];
        } else if (f[j] > zd2)
          zd2 = f[j];
      }
    }
  }
  for (i = 0; i < g[p].size(); ++i) {
    j = g[p][i];
    if (j != father[p]) {
      if (f[j] == ge[j])
        fup[j] = 1 + sum - f[j] + zd;
      else if (f[j] == zd)
        fup[j] = 1 + sum + zd2;
      else
        fup[j] = 1 + sum + zd;
    }
  }
  for (i = 0; i < g[p].size(); ++i) {
    j = g[p][i];
    if (j != father[p]) calc_fup(j);
  }
}
bool ky(int now) {
  int p, i, j, sum, zd;
  MIN = now;
  calc_f(1);
  fup[1] = 0;
  calc_fup(1);
  for (p = 1; p <= n; ++p) {
    sum = zd = 0;
    if (fup[p] == upge[p])
      sum = fup[p];
    else
      zd = fup[p];
    if (a[p] < MIN) continue;
    for (i = 0; i < g[p].size(); ++i) {
      j = g[p][i];
      if (j != father[p]) {
        if (f[j] == ge[j])
          sum += f[j];
        else {
          if (f[j] > zd) zd = f[j];
        }
      }
    }
    if (sum + zd >= K) return true;
  }
  return false;
}
void work() {
  int i, start, stop, mid;
  father[1] = 0;
  calc_ge(1, 0);
  for (i = 1; i <= n; ++i) upge[i] = n - ge[i];
  start = 1;
  stop = 1000010;
  while (start <= stop) {
    mid = (start + stop) / 2;
    if (ky(mid)) {
      result = mid;
      start = mid + 1;
    } else
      stop = mid - 1;
  }
}
void output() { printf("%d\n", result); }
int main() {
  init();
  work();
  output();
  return 0;
}
