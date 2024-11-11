#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v[200020];
int n;
int w[200020];
int erased[200020];
int down[200020];
void dfs(int x, int fa) {
  down[x] = 1;
  for (auto it : v[x]) {
    if (erased[it.second] == 0 && it.second != fa) {
      dfs(it.second, x);
      down[x] += down[it.second];
    }
  }
}
int fm(int x) {
  int half = (down[x] - 1) >> 1;
  while (1) {
    int nxt = -1;
    for (auto it : v[x]) {
      if (erased[it.second] == 0 && down[it.second] < down[x] &&
          down[it.second] > half) {
        nxt = it.second;
        break;
      }
    }
    if (nxt == -1) break;
    x = nxt;
  }
  return x;
}
double get1(int x, int fa, int len) {
  double res = w[x] * sqrt(len);
  for (auto it : v[x]) {
    if (it.second != fa) res += get1(it.second, x, len + it.first);
  }
  return res;
}
double get2(int x, int fa, int len) {
  double res = w[x] * sqrt(len) * len;
  for (auto it : v[x]) {
    if (it.second != fa) res += get2(it.second, x, len + it.first);
  }
  return res;
}
int ans;
double res = 2e25;
void solve(int x) {
  dfs(x, -1);
  x = fm(x);
  double rx = get2(x, -1, 0);
  if (res > rx) res = rx, ans = x;
  double mx = 0, sum = 0;
  int mxv = -1;
  for (auto it : v[x]) {
    if (erased[it.second] == 0) {
      double sub = get1(it.second, x, it.first);
      if (mx < sub) mx = sub, mxv = it.second;
      sum += sub;
    }
  }
  if (mxv == -1 || mx + mx < sum * (1 + 1e-12))
    ;
  else {
    erased[x] = 1;
    solve(mxv);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", w + i);
  if (n == 1) {
    printf("0 0");
    return 0;
  }
  for (int i = 1; i < n; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    v[x].push_back(pair<int, int>(z, y));
    v[y].push_back(pair<int, int>(z, x));
  }
  solve(1);
  printf("%d %.15f", ans, res);
  return 0;
}
