#include <bits/stdc++.h>
using namespace std;
long long bin[40], f[40];
int gao(int n, long long k) {
  for (int i = 0; i <= n; i++) {
    long long l = 0, r = 0;
    for (int j = 1; j <= n - i; j++) l += bin[j] - 1;
    r = (bin[n - i] - 1) * (bin[n - i] - 1) * f[i] + f[n - i];
    if (k > r || k < l) continue;
    return i;
  }
  return -1;
}
int main() {
  int t;
  scanf("%d", &t);
  bin[0] = f[1] = 1;
  bin[1] = 2;
  for (int i = 2; i <= 35; i++)
    bin[i] = bin[i - 1] * 2ll, f[i] = f[i - 1] * 4ll - 1;
  while (t--) {
    int n;
    long long k;
    scanf("%d%I64d", &n, &k);
    if (n > 31) {
      printf("YES %d\n", n - 1);
      continue;
    }
    int ans = gao(n, k);
    if (ans == -1)
      printf("NO\n");
    else
      printf("YES %d\n", ans);
  }
  return 0;
}
