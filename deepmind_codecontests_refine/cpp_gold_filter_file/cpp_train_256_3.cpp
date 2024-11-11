#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const int maxk = 5000 + 5;
int n, k;
int a[maxn];
long long d[maxk][maxk];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  a[0] = a[1];
  int num1 = n % k, len1 = n / k + 1;
  int num2 = k - num1, len2 = n / k;
  for (int i = 0; i <= num1; i++)
    for (int j = 0; j <= num2; j++) {
      if (i) {
        int k = (i - 1) * len1 + j * len2;
        d[i][j] = max(d[i][j], d[i - 1][j] + a[k + 1] - a[k]);
      }
      if (j) {
        int k = i * len1 + (j - 1) * len2;
        d[i][j] = max(d[i][j], d[i][j - 1] + a[k + 1] - a[k]);
      }
    }
  printf("%I64d\n", a[n] - a[1] - d[num1][num2]);
  return 0;
}
