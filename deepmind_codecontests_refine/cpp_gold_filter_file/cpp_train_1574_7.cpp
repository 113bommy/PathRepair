#include <bits/stdc++.h>
using namespace std;
int n, m, power;
int p[100];
int loyal[100];
int add[100];
int fin[1 << 10];
double dp[10][1 << 8];
double solve(int dx, int mask) {
  if (dx == n) {
    if (fin[mask] == -1)
      return 1;
    else
      return power / (double)(power + fin[mask]);
  }
  double &ret = dp[dx][mask];
  if (ret > -1e-9) return ret;
  double t = (add[dx] + loyal[dx]);
  t /= 100;
  ret = t * solve(dx + 1, mask);
  ret += (1 - t) * solve(dx + 1, mask | (1 << dx));
  return ret;
}
int main() {
  scanf("%d%d%d", &n, &m, &power);
  for (int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    p[i] = a;
    loyal[i] = b;
  }
  int mx = 1;
  for (int i = 0; i < n; ++i) mx *= 9;
  for (int i = 0; i < (1 << n); ++i) {
    int cnt = 0;
    int sum = 0;
    for (int j = 0; j < n; ++j) {
      if (~i & (1 << j)) continue;
      cnt++;
      sum += p[j];
    }
    int left = n - cnt;
    if (left > (n / 2)) sum = -1;
    fin[i] = sum;
  }
  double sol = 0;
  for (int cm = 0; cm < mx; ++cm) {
    int stoken = 0;
    int mem = cm;
    bool ok = 1;
    for (int i = 0; i < n; ++i) {
      int w = mem % 9;
      mem /= 9;
      stoken += w;
      add[i] = 10 * w;
      if (loyal[i] + add[i] > 100) ok = 0;
      if (stoken > m) ok = 0;
    }
    if (!ok) continue;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < (1 << n); ++j) dp[i][j] = -1;
    sol = max(sol, solve(0, 0));
  }
  printf("%.10lf\n", sol);
  return 0;
}
