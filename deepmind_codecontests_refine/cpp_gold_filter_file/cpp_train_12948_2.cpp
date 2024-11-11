#include <bits/stdc++.h>
using namespace std;
long long n, x, y, a[111111], p[111111], m[111111];
vector<long long> v[100010];
void dfs(long long pr, long long x) {
  long long mi = 0, pl = 0, ans;
  for (int i = 0; i < v[x].size(); i++) {
    long long to = v[x][i];
    if (to != pr) {
      dfs(x, to);
      pl = max(pl, p[to]);
      mi = max(mi, m[to]);
    }
  }
  ans = pl - mi;
  a[x] += ans;
  if (a[x] > 0)
    mi += a[x];
  else
    pl -= a[x];
  p[x] = pl;
  m[x] = mi;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n - 1; i++)
    cin >> x >> y, v[x].push_back(y), v[y].push_back(x);
  for (int i = 1; i <= n; i++) cin >> a[i];
  dfs(0, 1);
  cout << p[1] + m[1];
}
