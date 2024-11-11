#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int pre[N], rpre[N], rsuf[N], A[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &A[i]);
    pre[i] = pre[i - 1] + A[i];
    rpre[i] = rpre[i - 1] - A[i];
  }
  for (int i = n; i >= 1; i--) rsuf[i] = rsuf[i + 1] - A[i];
  int ans = -1e9, maxx = 0;
  for (int i = 1; i <= n + 1; i++) {
    ans = max(ans, rsuf[i] + pre[i - 1] + maxx);
    maxx = max(maxx, rpre[i] - pre[i]);
  }
  printf("%d\n", ans);
}
