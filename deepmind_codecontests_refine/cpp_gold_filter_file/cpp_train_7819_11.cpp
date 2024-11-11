#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m;
int siz[N];
int mx[N];
int main() {
  scanf("%d", &n);
  int mxx = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &m);
    siz[i] = m;
    int x;
    for (int j = 1; j <= m; j++) {
      scanf("%d", &x);
      mx[i] = max(mx[i], x);
    }
    mxx = max(mxx, mx[i]);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += 1ll * (mxx - mx[i]) * (siz[i]);
  }
  printf("%lld\n", ans);
}
