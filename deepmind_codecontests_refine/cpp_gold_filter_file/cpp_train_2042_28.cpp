#include <bits/stdc++.h>
using namespace std;
const int N = 2000010;
int n, x, y, a[N], num[N];
long long tot[N];
int main() {
  scanf("%d%d%d", &n, &x, &y);
  int t = (x + y - 1) / y;
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]), num[a[i]]++, tot[a[i]] += a[i];
  for (int i = 1; i <= 2000000; i++) num[i] += num[i - 1], tot[i] += tot[i - 1];
  long long ans = 1LL << 60;
  for (int i = 2; i <= 1000000; i++) {
    long long cur = 0;
    for (int j = i; j <= 1000000 + i; j += i) {
      int mid = max(j - i, j - t);
      cur += 1LL * (num[mid] - num[j - i]) * x +
             1LL * (1LL * (num[j] - num[mid]) * j - tot[j] + tot[mid]) * y;
    }
    ans = min(ans, cur);
  }
  printf("%lld\n", ans);
}
