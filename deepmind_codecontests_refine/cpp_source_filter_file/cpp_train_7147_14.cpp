#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n, k, a[MAXN], t[MAXN], pre[MAXN], preAll[MAXN];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    preAll[i] = preAll[i - 1] + a[i];
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", t + i);
    pre[i] = pre[i - 1] + t[i] * a[i];
  }
  int ans = 0;
  for (int i = 1; i <= n - k + 1; ++i) {
    int sum = preAll[i + k - 1] - preAll[i - 1];
    sum += pre[i - 1];
    sum += pre[n] - pre[i + k - 2];
    ans = max(ans, sum);
  }
  printf("%d\n", ans);
  return 0;
}
