#include <bits/stdc++.h>
using namespace std;
int T, n;
int sht1[10001];
int sht2[10001];
int main() {
  scanf("%d", &T);
  while (T--) {
    int sum = 0;
    memset(sht1, 0, sizeof(sht1));
    memset(sht2, 0, sizeof(sht2));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &sht1[i]);
      sum += sht1[i];
      sht2[i] = sht1[i] % i;
    }
    if (sum % n) {
      printf("-1\n");
      continue;
    }
    printf("%d\n", 3 * (n - 1));
    for (int i = 2; i <= n; i++) {
      printf("1 %d %d\n", i, (i - sht2[i]) % i);
      if (sht1[i] % i) {
        sht1[1] -= (i - sht2[i]) % i;
        sht1[i] += (i - sht2[i]) % i;
      }
      printf("%d 1 %d\n", i, sht1[i] / i);
      sht1[1] += sht1[i];
      sht1[i] = 0;
    }
    for (int i = 2; i <= n; i++) {
      printf("1 %d %d\n", i, sum / n);
      sht1[1] -= sum / n;
      sht1[i] = sum / n;
    }
  }
  return 0;
}
