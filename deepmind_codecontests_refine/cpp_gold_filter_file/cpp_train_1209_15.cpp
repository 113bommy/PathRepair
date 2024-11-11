#include <bits/stdc++.h>
using namespace std;
namespace Acc {
const int N = 2e5 + 10, M = 1e6 + 10;
int a[N], cnt[M], l, r, n, m, i, B;
long long ans[N], res;
struct T {
  int x, y, z;
  bool operator<(const T& _) const {
    return x / B == _.x / B ? y < _.y : x < _.x;
  }
} q[N];
void add(int x) { res += x * (cnt[x] * 2ll + 1), ++cnt[x]; }
void del(int x) { res += x * (-2ll * cnt[x] + 1), --cnt[x]; }
void work() {
  for (cin >> n >> m, i = 1; i <= n; ++i) cin >> a[i];
  for (i = 1; i <= m; ++i) cin >> l >> r, q[i] = {l, r, i};
  B = max(1., n / sqrt(m)), sort(q + 1, q + m + 1);
  for (l = i = 1, r = 0; i <= m; ++i) {
    auto [x, y, z] = q[i];
    while (l > x) add(a[--l]);
    while (r < y) add(a[++r]);
    while (l < x) del(a[l++]);
    while (r > y) del(a[r--]);
    ans[z] = res;
  }
  for (i = 1; i <= m; ++i) cout << ans[i] << '\n';
}
}  // namespace Acc
int main() { return Acc::work(), 0; }
