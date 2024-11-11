#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, x[N], y[N], nx, ny, a[N];
bool mp[N];
long long ans;
int s[N];
vector<int> v[N];
void add(int x) {
  for (; x <= nx; x += (x & -x)) s[x]++;
}
int sum(int x) {
  int res = 0;
  for (; x; x -= x & -x) res += s[x];
  return res;
}
void discr(int *x, int &nx) {
  for (int i = 0; i < n; ++i) a[i] = x[i];
  sort(a, a + n);
  nx = unique(a, a + n) - a;
  for (int i = 0; i < n; ++i) x[i] = lower_bound(a, a + nx, x[i]) - a + 1;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d%d", x + i, y + i);
  discr(x, nx);
  discr(y, ny);
  for (int i = 0; i < n; ++i) v[y[i]].push_back(x[i]);
  for (int i = 1; i <= ny; ++i) {
    v[i].push_back(0);
    sort(v[i].begin(), v[i].end());
    for (int j = 1; j < v[i].size(); ++j)
      if (!mp[v[i][j]]) {
        mp[v[i][j]] = 1;
        add(v[i][j]);
      }
    for (int j = 1; j < v[i].size(); ++j) {
      int l = sum(v[i][j]) - sum(v[i][j - 1]);
      int r = sum(nx) - sum(v[i][j] - 1);
      ans += 1ll * l * r;
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
