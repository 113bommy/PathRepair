#include <bits/stdc++.h>
using namespace std;
int n, k;
int num[1000100];
int a[5500];
bool flag[1000100];
int max(int a, int b) { return a > b ? a : b; }
int main() {
  int Max;
  int cnt, mark, mod;
  int i, j, m;
  while (scanf("%d%d", &n, &k) != EOF) {
    Max = -1;
    memset(num, 0, sizeof(num));
    memset(flag, 0, sizeof(flag));
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      Max = max(a[i], Max);
    }
    for (i = 1; i < n; i++) {
      int k;
      for (j = 0; j < i; j++) {
        k = abs(a[i] - a[j]);
        num[k]++;
      }
    }
    int sum;
    for (m = n - k; m <= Max + 1; m++) {
      sum = 0;
      for (i = m; i <= Max; i += m) {
        sum += num[i];
        if (sum > (k * (k + 1) / 2)) break;
      }
      if (sum > (k * (k + 1) / 2)) continue;
      cnt = mark = 0;
      for (j = 0; j < n && (!mark); j++) {
        mod = a[j] % m;
        if (!flag[mod])
          flag[mod] = 1;
        else {
          cnt++;
          if (cnt > k) mark = 1;
        }
      }
      memset(flag, 0, sizeof(flag));
      if (!mark) {
        mark = m;
        break;
      }
    }
    printf("%d\n", mark);
  }
  return 0;
}
