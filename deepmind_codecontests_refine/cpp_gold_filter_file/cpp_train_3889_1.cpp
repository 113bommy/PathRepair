#include <bits/stdc++.h>
using namespace std;
int n, m, ansx, ansy;
long long ans1 = -1, ans2 = -1;
long long a[1010][1010], b[1010], c[1010];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%I64d", &a[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) b[j] += a[i][j], c[i] += a[i][j];
  for (long long i = 0; i <= n; i++) {
    long long sum = 0;
    for (long long j = 1; j <= n; j++)
      sum += c[j] * (j * 4 - 2 - i * 4) * (j * 4 - 2 - i * 4);
    if (sum < ans1 || ans1 == -1) {
      ans1 = sum;
      ansx = i;
    }
  }
  for (long long i = 0; i <= m; i++) {
    long long sum = 0;
    for (long long j = 1; j <= m; j++)
      sum += b[j] * (j * 4 - 2 - i * 4) * (j * 4 - 2 - i * 4);
    if (sum < ans2 || ans2 == -1) {
      ans2 = sum;
      ansy = i;
    }
  }
  printf("%I64d\n%d %d\n", ans1 + ans2, ansx, ansy);
  return 0;
}
