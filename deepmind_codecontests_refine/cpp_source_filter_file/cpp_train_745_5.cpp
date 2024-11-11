#include <bits/stdc++.h>
using namespace std;
int ans, n, K, ar[15], l, st;
long long fac[15];
bool vis[15];
inline bool Check(int p) {
  while (p) {
    if ((p % 10 != 4) && (p % 10 != 7)) return false;
    p /= 10;
  }
  return true;
}
int main() {
  int i, j, k, p;
  long long tmp;
  scanf("%d%d", &n, &K);
  if (n < 13) {
    for (tmp = 1, i = 1; i <= n; ++i) tmp *= i;
    if (tmp < K) {
      printf("-1\n");
      exit(0);
    }
    st = 0;
    l = n;
  } else {
    st = n - 12;
    l = 12;
    for (i = 1; i <= 10; ++i)
      for (j = (1 << i) - 1; j >= 0; --j) {
        tmp = 0;
        for (k = i - 1; k >= 0; --k) {
          tmp *= 10;
          if ((j >> k) & 1)
            tmp += 7;
          else
            tmp += 4;
        }
        if (tmp <= st) ++ans;
      }
  }
  fac[1] = 1;
  for (i = 2; i <= l; ++i) fac[i] = fac[i - 1] * i;
  for (--K, i = l; i > 1; --i) {
    p = K / fac[i - 1] + 1;
    K %= fac[i - 1];
    for (j = 1; j <= l; ++j) {
      if (!vis[j]) --p;
      if (!p) break;
    }
    ar[l - i + 1] = j;
    vis[j] = true;
  }
  for (i = 1; i <= l; ++i)
    if (!vis[i]) {
      ar[l] = i;
      break;
    }
  for (i = 1; i <= l; ++i)
    if (Check(st + ar[i]) && Check(st + i)) ++ans;
  printf("%d\n", ans);
  return 0;
}
