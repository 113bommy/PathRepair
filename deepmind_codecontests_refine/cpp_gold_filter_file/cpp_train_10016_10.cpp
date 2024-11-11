#include <bits/stdc++.h>
using namespace std;
const int maxn = 112345;
int n, m;
int a[maxn], b[maxn], pos[maxn];
void solve() {
  scanf("%d%d", &n, &m);
  for (int(i) = (1); (i) <= (n); (i)++) scanf("%d", a + i);
  for (int(i) = (1); (i) <= (m); (i)++) scanf("%d", b + i);
  for (int(i) = (1); (i) <= (n); (i)++) pos[a[i]] = i;
  long long ans = 0;
  int mx = 0;
  for (int(i) = (1); (i) <= (m); (i)++) {
    int dep = pos[b[i]];
    if (dep < mx) {
      ans++;
      continue;
    }
    ans += 2 * (dep - i + 1) - 1;
    mx = dep;
  }
  printf("%lld\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}
