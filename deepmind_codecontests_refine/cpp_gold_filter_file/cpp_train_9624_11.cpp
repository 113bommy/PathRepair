#include <bits/stdc++.h>
using namespace std;
long long ans = 0;
int n, m, k;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  if (n - 1 + m - 1 < k) {
    printf("-1");
    return 0;
  }
  int hor_max = ((k) < (n - 1) ? (k) : (n - 1));
  int hor_min = (k < m) ? 0 : (k - m + 1);
  int ver_max = ((k) < (m - 1) ? (k) : (m - 1));
  int ver_min = (k < n) ? 0 : (k - n + 1);
  hor_max = n / (hor_max + 1);
  hor_min = n / (hor_min + 1);
  ver_max = m / (ver_max + 1);
  ver_min = m / (ver_min + 1);
  ans = ((ans) > (1LL * hor_max * ver_min) ? (ans) : (1LL * hor_max * ver_min));
  ans = ((ans) > (1LL * hor_min * ver_max) ? (ans) : (1LL * hor_min * ver_max));
  printf("%I64d", ans);
  return 0;
}
