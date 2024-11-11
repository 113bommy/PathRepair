#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m, q;
long long ans, in[N], out[N];
vector<int> f[N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x > y) swap(x, y);
    f[x].push_back(y);
    in[y]++, out[x]++;
  }
  for (int i = 1; i <= n; ++i) ans += in[i] * out[i];
  printf("%lld\n", ans);
  scanf("%d", &q);
  while (q--) {
    int x;
    scanf("%d", &x);
    ans -= in[x] * out[x];
    in[x] += out[x], out[x] = 0;
    for (int i = 0; i < f[x].size(); ++i) {
      int y = f[x][i];
      ans -= in[y] * out[y];
      out[y]++, in[y]--;
      ans += in[y] * out[y];
      f[y].push_back(x);
    }
    f[x].clear();
    printf("%lld\n", ans);
  }
  return 0;
}
