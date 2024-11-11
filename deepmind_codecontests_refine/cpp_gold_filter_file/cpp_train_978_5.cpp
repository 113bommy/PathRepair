#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
const int inf = 0x3f3f3f3f;
const double PI = acos(-1.0);
int T, n;
long long a[maxn], ans;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long factor[maxn], tot, cnt[maxn];
void solve() {
  long long x = a[(1LL * rand() * 1314 + rand()) % n + 1];
  tot = 0;
  for (long long i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      factor[++tot] = i;
      if (i * i != x) factor[++tot] = x / i;
    }
  }
  sort(factor + 1, factor + tot + 1);
  for (int i = 1; i <= tot; i++) cnt[i] = 0;
  for (int i = 1; i <= n; i++)
    cnt[lower_bound(factor + 1, factor + tot + 1, gcd(x, a[i])) - factor]++;
  for (int i = 1; i <= tot; i++)
    for (int j = i + 1; j <= tot; j++)
      if (factor[j] % factor[i] == 0) cnt[i] += cnt[j];
  for (int i = 1; i <= tot; i++)
    if (cnt[i] * 2 >= n) ans = max(ans, factor[i]);
}
int main() {
  srand(time(NULL));
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= 10; i++) solve();
  printf("%lld\n", ans);
  return 0;
}
