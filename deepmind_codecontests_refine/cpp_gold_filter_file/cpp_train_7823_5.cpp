#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500050;
int n;
long long ans;
long long f[MAXN];
vector<int> v[MAXN];
long long siz[MAXN];
void dfs(int k, int fa) {
  siz[k] = 1;
  for (__typeof(v[k].begin()) p = v[k].begin(); p < v[k].end(); ++p)
    if (*p != fa) {
      dfs(*p, k);
      siz[k] += siz[*p];
    }
  f[k] = (long long)siz[k] * siz[k];
  for (__typeof(v[k].begin()) p = v[k].begin(); p < v[k].end(); ++p)
    if (*p != fa) {
      long long tmp = siz[k] - siz[*p];
      f[k] = min(f[k], f[*p] + tmp * tmp);
    }
  vector<pair<int, int>> idx;
  for (__typeof(v[k].begin()) p = v[k].begin(); p < v[k].end(); ++p)
    if (*p != fa) idx.push_back(make_pair(n - siz[*p], *p));
  sort(idx.begin(), idx.end());
  vector<long long> xs;
  vector<long long> ys;
  for (auto pa : idx) {
    int p = pa.second;
    int l = 0, r = xs.size() - 1;
    while (r - l + 1 >= 3) {
      int m = (l + r) / 2;
      long long k = 2 * siz[p];
      if ((ys[m] - ys[m - 1]) >= k * (xs[m] - xs[m - 1])) r = m - 1;
      if ((ys[m] - ys[m + 1]) <= k * (xs[m] - xs[m + 1])) l = m + 1;
    }
    for (int i = l; i <= r; ++i)
      ans = min(ans, ys[i] + f[p] + siz[p] * siz[p] - (2 * siz[p]) * xs[i]);
    long long x = n - siz[p];
    long long y = f[p] + x * x;
    if (xs.size() > 0 && xs.back() == x)
      if (ys.back() >= y) {
        xs.resize(xs.size() - 1);
        ys.resize(ys.size() - 1);
      } else {
        continue;
      }
    while (xs.size() > 1) {
      int k = xs.size();
      if ((ys[k - 1] - y) * (xs[k - 1] - xs[k - 2]) <=
          (ys[k - 1] - ys[k - 2]) * (xs[k - 1] - x)) {
        xs.resize(xs.size() - 1);
        ys.resize(ys.size() - 1);
      } else
        break;
    }
    xs.push_back(x);
    ys.push_back(y);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  ans = (long long)n * n;
  dfs(1, 0);
  ans = min(ans, f[1]);
  ans = ((long long)n * n - ans) / 2;
  ans += (long long)n * (n - 1) / 2;
  cout << ans << endl;
  return 0;
}
