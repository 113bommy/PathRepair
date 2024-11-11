#include <bits/stdc++.h>
const long long INF = 1000000000;
using namespace std;
int a[5002], f[1000002], ff[1000002];
int main() {
  int n, k;
  while (scanf("%d%d", &n, &k) != EOF) {
    int i;
    int mm = 0;
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      if (a[i] > mm) mm = a[i];
    }
    if (k >= n - 1) {
      printf("1\n");
      continue;
    }
    int j;
    memset(f, 0, sizeof(f));
    for (i = 0; i < n; i++) {
      for (j = i + 1; j < n; j++) {
        f[abs(a[i] - a[j])] += 1;
      }
    }
    mm++;
    for (i = 2; i <= mm; i++) {
      int sum = 0;
      for (j = i; j <= mm; j += i) {
        sum += f[j];
        if (sum > k * (k + 1) / 2) break;
      }
      if (sum > k * (k + 1) / 2) continue;
      memset(ff, 0, sizeof(ff));
      sum = 0;
      for (j = 0; j < n; j++) {
        if (f[a[j] % i]) sum++;
        ff[a[j] % i] = 1;
        if (sum > k) break;
      }
      if (sum <= k) break;
    }
    printf("%d\n", i);
  }
  return 0;
}
