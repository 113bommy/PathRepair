#include <bits/stdc++.h>
using namespace std;
const int maxn = (1 << 20);
int N;
long long f[maxn + 11], cnt[maxn + 11], ans[maxn + 11];
int a[22][maxn + 11];
char ch[maxn + 11];
void fwt(long long *a, int opt) {
  for (int mid = 1; mid < N; mid <<= 1)
    for (int R = mid << 1, j = 0; j < N; j += R)
      for (int k = 0; k < mid; k++) {
        int x = a[j + k], y = a[j + k + mid];
        if (opt == 1)
          a[j + k] = x + y, a[j + k + mid] = x - y;
        else
          a[j + k] = (x + y) / 2, a[j + k + mid] = (x - y) / 2;
      }
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", ch + 1);
    for (int j = 1; j <= m; j++) a[i][j] = ch[j] - '0';
  }
  for (int i = 1; i <= m; i++) {
    int x = 0;
    for (int j = 1; j <= n; j++)
      if (a[j][i]) x += (1 << (j - 1));
    cnt[x]++;
  }
  N = (1 << n);
  for (int i = 0; i < N; i++)
    f[i] = min(__builtin_popcount(i), n - __builtin_popcount(i));
  fwt(cnt, 1);
  fwt(f, 1);
  for (int i = 0; i < N; i++) ans[i] = cnt[i] * f[i];
  fwt(ans, -1);
  long long mx = n * m;
  for (int i = 0; i < N; i++) mx = min(mx, ans[i]);
  printf("%lld\n", mx);
}
