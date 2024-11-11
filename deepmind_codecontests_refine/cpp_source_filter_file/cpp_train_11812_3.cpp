#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const int MAXN = 666666;
const int MOD = 1e9 + 7;
const int INF = (1 << 30);
const long long INFl = 1e18;
int n, m;
long long a[MAXN];
long long ans = 0;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  sort(a, a + n + 1);
  for (int i = 1; i <= n; i++) a[i] += a[i - 1];
  int sum = a[n];
  for (int i = 1; i < n; i++) {
    ans += sum - a[i - 1];
  }
  printf("%I64d", ans + sum);
  return 0;
}
