#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], top;
pair<int, int> stk[N];
int main() {
  int n, k, m;
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) {
    if (!top || stk[top].first != a[i])
      stk[++top] = {a[i], 1};
    else
      ++stk[top].second;
    if (stk[top].second == m) --top;
  }
  int rec1 = 0, rec2 = 0;
  for (int i = 1; i <= top; ++i) rec1 += stk[i].second;
  int l = 1, r = top;
  while (l < r && stk[l].first == stk[r].first &&
         (stk[l].second + stk[r].second) % k == 0) {
    rec2 += stk[l].second + stk[r].second;
    ++l;
    --r;
  }
  if (l == r) {
    long long ans = 1ll * m * rec1 - 1ll * (m - 1) * rec2 -
                    (stk[l].second * 1ll * m / k * k);
    if (stk[l].second * m % k == 0) ans -= rec2;
    printf("%lld\n", ans);
  } else {
    if (stk[l].first == stk[r].first)
      rec2 += (stk[l].second + stk[r].second) / k * k;
    long long ans = 1ll * m * rec1 - 1ll * (m - 1) * rec2;
    printf("%lld\n", ans);
  }
  return 0;
}
