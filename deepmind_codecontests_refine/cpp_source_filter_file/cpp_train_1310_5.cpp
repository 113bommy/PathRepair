#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e6 + 5;
long long N, M, f[MAXN], deg[MAXN], ans = 0, cnt = 0, bl, root;
bool vis[MAXN];
namespace solution {
long long getf(long long k) {
  if (f[k] == k) return k;
  f[k] = getf(f[k]);
  return f[k];
}
void Prepare() {
  scanf("%lld%lld", &N, &M);
  for (long long i = 1; i <= N; i++) f[i] = i;
  bl = N;
  for (long long i = 1; i <= M; i++) {
    long long x, y;
    scanf("%lld%lld", &x, &y);
    f[getf(x)] = getf(y);
    vis[x] = vis[y] = 1;
    if (x != y) {
      deg[x]++;
      deg[y]++;
    } else
      cnt++;
    root = x;
  }
}
void Solve() {
  for (long long i = 1; i <= N; i++)
    if (vis[i] && getf(i) != root) {
      puts("0");
      return;
    }
  for (long long i = 1; i <= N; i++) {
    if (deg[i] >= 2) ans += deg[i] * (deg[i] - 1) / 2;
  }
  if (cnt >= 2) ans += cnt * (cnt - 1) / 2;
  if (cnt >= 1 && M - cnt >= 1) ans += cnt * (M - cnt);
  cout << ans << endl;
}
}  // namespace solution
int main() {
  using namespace solution;
  Prepare();
  Solve();
  return 0;
}
