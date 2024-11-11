#include <bits/stdc++.h>
const int inf = (1 << 30) - 1;
const double eps = 1e-9;
using namespace std;
int n, a[111111], f[111111], g[111111];
unsigned long long ans = 0;
vector<int> v;
map<int, vector<int> > m;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  f[0] = a[0];
  for (int i = 0; i < n; i++) f[i] = f[i - 1] + a[i];
  g[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) g[i] = g[i + 1] + a[i];
  for (int i = 0; i < n; i++) m[g[i]].push_back(i);
  for (int i = 0; i < n; i++) {
    int s = f[i];
    if (3 * s == f[n - 1]) {
      if (m.find(s) == m.end()) continue;
      int p = lower_bound(m[s].begin(), m[s].end(), i + 2) - m[s].begin();
      ans += m[s].size() - p;
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
