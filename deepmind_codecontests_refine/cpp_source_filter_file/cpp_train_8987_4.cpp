#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, B = 1e9 + 7;
int n;
pair<int, long long> fa[N];
long long add(long long x, long long y) {
  x = (x + B) % B;
  y = (y + B) % B;
  x = (x + y) % B;
  return x;
}
pair<int, long long> find(int x) {
  if (fa[x].first == x) return make_pair(fa[x].first, fa[x].second);
  auto p = find(fa[x].first);
  return fa[x] = {p.first, p.second + fa[x].second};
}
int main() {
  scanf("%d", &n);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    int k;
    scanf("%d", &k);
    int v, x;
    fa[i] = {i, 0};
    for (int j = 0; j < k; ++j) {
      scanf("%d%d", &v, &x);
      auto p = find(v);
      int rt = p.first, d = p.second;
      fa[rt] = {i, add(d, x)};
      ans = add(ans, fa[rt].second) % B;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
