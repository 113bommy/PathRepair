#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void chkmax(T& x, U y) {
  if (x < y) x = y;
}
template <typename T, typename U>
inline void chkmin(T& x, U y) {
  if (y < x) x = y;
}
const int MAXN = 1e7 + 10;
int p[MAXN], phi[MAXN], cnt[MAXN], prm[MAXN], prn;
int main() {
  int n;
  scanf("%d", &n);
  long long ans = 0;
  for (int i = 2; i <= n; i++) {
    if (!p[i]) {
      p[i] = i;
      phi[i] = i - 1;
      prm[prn++] = i;
    }
    int k = min(n / i, p[i]);
    for (int j = 0; j < prn && prm[j] <= k; j++) {
      p[prm[j] * i] = p[i];
      phi[prm[j] * i] = phi[i] * (prm[j] - (prm[j] < p[i]));
    }
    ans -= 2 * (i - 1 - phi[i]);
  }
  for (int i = 2; i <= n; i++) cnt[p[i]]++;
  for (int i = 2; i <= n; i++) cnt[i] += cnt[i - 1];
  int tot = n - 1;
  for (int i = 2; i <= n; i++)
    if (p[i] * 2 > n) tot--;
  for (int i = 2; i <= n; i++) {
    if (p[i] * 2 > n) continue;
    ans += 3 * (tot - 1) - (cnt[n / p[i]] - (1LL * p[i] * p[i] <= n));
  }
  cout << ans / 2 << endl;
  return 0;
}
