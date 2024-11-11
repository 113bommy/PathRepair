#include <bits/stdc++.h>
using namespace std;
int gg[66], cnt[66], tot, a[100010][66], tmp, cntn[66];
int n, k;
long long ans = 0;
void get(int k) {
  for (int i = 2; i * i <= k; i++) {
    if (k % i == 0) {
      gg[++tot] = i;
      while (k % i == 0) cnt[tot]++, k /= i;
    }
  }
  if (k != 1) gg[++tot] = k, cnt[tot] = 1;
}
int check() {
  for (int i = 1; i <= tot; i++) {
    if (cntn[i] < cnt[i]) return 0;
  }
  return 1;
}
int main() {
  scanf("%d%d", &n, &k);
  if (k == 1) {
    printf("%lld\n", n * (n + 1) / 2);
    return 0;
  }
  get(k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &tmp);
    for (int j = 1; j <= tot; j++) {
      while (tmp % gg[j] == 0) a[i][j]++, tmp /= gg[j];
    }
  }
  int l = 0, r = 0;
  for (l = 1; l <= n; l++) {
    while (!check() && r < n) {
      r++;
      for (int i = 1; i <= tot; i++) {
        cntn[i] += a[r][i];
      }
    }
    if (check()) ans += n - r + 1;
    for (int i = 1; i <= tot; i++) {
      cntn[i] -= a[l][i];
    }
  }
  printf("%lld\n", ans);
}
