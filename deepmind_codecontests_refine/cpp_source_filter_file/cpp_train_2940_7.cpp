#include <bits/stdc++.h>
using namespace std;
const int MAXN = (1 << 20) + 3;
int t[MAXN];
bool wz[MAXN];
bool zaj[MAXN];
vector<pair<int, int> > v;
int main() {
  int z, n, g, x;
  long long ans;
  scanf("%d", &z);
  while (z--) {
    ans = 0;
    scanf("%d %d", &n, &g);
    n = (1 << n) - 1;
    g = (1 << g) - 1;
    for (int i = 1; i <= g; i++) zaj[i] = false;
    for (int i = g + 1; i <= n; i++) zaj[i] = true;
    for (int i = 1; i <= n; i++) wz[i] = false;
    v.clear();
    for (int i = 1; i <= n; i++) {
      scanf("%d", &t[i]);
      v.emplace_back(t[i], i);
    }
    sort(v.begin(), v.end());
    for (auto it : v) {
      x = it.second;
      while (zaj[x]) x /= 2;
      if (x == 0) continue;
      if (zaj[x * 2] == zaj[x * 2 + 1]) {
        zaj[x] = true;
        ans += (long long)(it.first);
        wz[it.second] = true;
      }
    }
    printf("%lld\n", ans);
    for (int i = 1; i <= n; i++) {
      if (!wz[i]) printf("%d ", i);
    }
    printf("\n");
  }
  return 0;
}
