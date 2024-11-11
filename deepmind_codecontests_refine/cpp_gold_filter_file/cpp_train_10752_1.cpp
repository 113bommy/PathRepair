#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int a[maxn];
int cnt[maxn];
int pre[maxn * 3];
int id = 0;
int n;
int res = 0;
vector<int> g[maxn];
int pre1[maxn];
int link[maxn];
int prog[maxn];
void solve1(int x) {
  int sum = maxn;
  vector<int> v;
  pre[sum] = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == id)
      sum++;
    else if (a[i] == x)
      sum--;
    if (pre[sum] == -1)
      pre[sum] = i;
    else
      res = max(res, i - pre[sum]);
    v.push_back(sum);
  }
  for (auto to : v) pre[to] = -1;
}
void solve2(int x) {
  int sum = maxn;
  vector<int> v;
  pre[sum] = 0;
  for (int i = 0; i < g[x].size(); i++) {
    int y = link[g[x][i]];
    for (int j = 0; j <= g[x].size(); j++) y = link[y];
    int k = 0;
    for (int j = 0; j <= g[x].size() * 2 + 5; j++) {
      while (k < g[x].size() && g[x][k] < y) {
        sum--;
        if (pre[sum] == -1)
          pre[sum] = g[x][k];
        else
          res = max(res, g[x][k] - pre[sum]);
        v.push_back(sum);
        k++;
      }
      sum = maxn + pre1[y] - k;
      if (pre[sum] == -1)
        pre[sum] = y;
      else
        res = max(res, min(y, n) - pre[sum]);
      v.push_back(sum);
      if (y == n + 1) break;
      y = prog[y];
    }
  }
  for (auto to : v) pre[to] = -1;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int mmax = 0;
  for (int i = 1; i <= n; i++) {
    if (++cnt[a[i]] > mmax) {
      mmax = cnt[a[i]];
      id = a[i];
    } else if (cnt[a[i]] == mmax)
      id = -1;
  }
  if (id == -1) {
    cout << n << endl;
    return 0;
  }
  int line = sqrt(n);
  int wd = 0;
  for (int i = 1; i <= n; i++) {
    if (cnt[a[i]] < line) g[a[i]].push_back(i);
    pre1[i] = pre1[i - 1] + (a[i] == id);
    link[i] = wd;
    if (a[i] == id) wd = i;
  }
  pre1[n + 1] = pre1[n];
  wd = n + 1;
  prog[n + 1] = n + 1;
  for (int i = n; i >= 0; i--) {
    prog[i] = wd;
    if (a[i] == id) wd = i;
  }
  memset(pre, -1, sizeof(pre));
  for (int i = 1; i <= 100; i++) {
    if (i == id) continue;
    solve1(i);
  }
  cout << res << endl;
  return 0;
}
