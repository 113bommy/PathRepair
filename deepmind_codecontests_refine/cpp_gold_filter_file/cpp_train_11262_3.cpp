#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> mp[N];
int in[N], out[N];
int main() {
  int n, m, x, y;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    if (x > y) swap(x, y);
    mp[x].push_back(y), in[x]++, out[y]++;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans += 1ll * in[i] * out[i];
  printf("%lld\n", ans);
  int q;
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &x);
    ans -= 1ll * in[x] * out[x];
    for (auto i : mp[x]) {
      mp[i].push_back(x);
      ans += 1ll * (in[i] + 1) * (out[i] - 1) - 1ll * in[i] * out[i];
      in[x]--, out[x]++, in[i]++, out[i]--;
    }
    mp[x].clear();
    printf("%lld\n", ans);
  }
  return 0;
}
