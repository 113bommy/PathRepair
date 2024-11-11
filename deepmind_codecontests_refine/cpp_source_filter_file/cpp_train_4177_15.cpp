#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10, L = 22;
long long a[N], sb[N], odd_pref[N], even_pref[N];
int n, b[N], mx[N][L];
void build() {
  for (int i = 1; i <= n; i++) mx[i][0] = b[i];
  for (int k = 1; (1 << k) <= n; k++)
    for (int i = 1; (1 << k) + i - 1 <= n; i++)
      mx[i][k] = max(mx[i][k - 1], mx[i + (1 << (k - 1))][k - 1]);
}
int get_max(int a, int b) {
  int k = (int)log2(b - a + 1);
  return max(mx[a][k], mx[b - (1 << k) + 1][k]);
}
int cbits(long long x) {
  int cnt = 0;
  while (x) {
    cnt += (x & 1);
    x >>= 1;
  }
  return cnt;
}
int main() {
  scanf("%d", &n);
  sb[0] = 0LL;
  for (int i = 1; i <= n; i++)
    scanf("%lld", a + i), b[i] = cbits(a[i]),
                          sb[i] = (long long)sb[i - 1] + b[i];
  odd_pref[n + 1] = even_pref[n + 1] = 0LL;
  for (int i = n; i >= 1; i--) {
    odd_pref[i] = odd_pref[i + 1] + (sb[i] % 2);
    even_pref[i] = even_pref[i + 1] + (sb[i] % 2 == 0);
  }
  build();
  long long ans = 0LL;
  for (int i = 1; i <= n; i++) {
    int j = i;
    for (j = i; j <= n && (sb[j] - sb[i - 1]) < 120; j++)
      if (sb[j] - sb[i - 1] >= 2LL * get_max(i, j) &&
          (sb[j] - sb[i - 1]) % 2 == 0)
        ans++;
    ans += (sb[i - 1] % 2 ? odd_pref[j + 1] : even_pref[j + 1]);
  }
  printf("%lld\n", ans);
}
