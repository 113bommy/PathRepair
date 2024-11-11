#include <bits/stdc++.h>
using namespace std;
const int N = 111;
int sum[N];
int main() {
  int n, i, j, a, maxx;
  while (scanf("%d", &n) != EOF) {
    sum[0] = 0;
    for (i = 1; i <= n; i++) {
      scanf("%d", &a);
      sum[i] = sum[i - 1] + a;
    }
    maxx = 0;
    for (i = 1; i <= n; i++) {
      for (j = i; j <= n; j++) {
        maxx = max(maxx, sum[n] + j - i + 1 - 2 * (sum[j] - sum[i - 1]));
      }
    }
    printf("%d\n", maxx);
  }
}
