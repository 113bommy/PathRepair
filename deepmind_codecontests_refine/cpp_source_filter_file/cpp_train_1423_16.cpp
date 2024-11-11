#include <bits/stdc++.h>
using namespace std;
int n, a[5005], ans[5005], sqr[10005], tot;
bool cnt[200000005];
int main() {
  for (int i = 1; i <= 10000; i++) sqr[i] = i * i;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    for (int j = 2; sqr[j] <= a[i]; j++)
      while (!(a[i] % sqr[j])) a[i] /= sqr[j];
    a[i] += 100000000;
  }
  memset(ans, 0, sizeof ans);
  for (int i = 1; i <= n; i++) {
    tot = 0;
    for (int j = i; j <= n; j++) {
      if (a[j] != 100000000) {
        if (!cnt[a[j]]) tot++;
        cnt[a[j]] = true;
      }
      ans[tot]++;
    }
    for (int j = i; j <= n; j++) cnt[a[j]] = false;
  }
  ans[1] += ans[0];
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  puts("");
  return 0;
}
