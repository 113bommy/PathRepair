#include <bits/stdc++.h>
using namespace std;
const int N = 2e6;
long long a[N], m, w, h, n, H;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  cin >> m;
  for (int i = 1; i <= m; i++) {
    long long w, h;
    scanf("%I64d%I64d", &w, &h);
    long long ans = max(H, a[w]);
    printf("%I64d\n", ans);
    H = ans + h;
  }
  return 0;
}
