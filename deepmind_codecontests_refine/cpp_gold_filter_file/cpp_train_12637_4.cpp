#include <bits/stdc++.h>
using namespace std;
int n, m, p, a[100001], v[100001];
long long f[100001], g[100001], sum[100001], A[100001], B[100001];
int Left, cnt;
int main() {
  scanf("%d%d%d", &n, &m, &p);
  a[1] = 0;
  for (int i = 2; i <= n; i++) {
    int x;
    scanf("%d", &x);
    a[i] = a[i - 1] + x;
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    v[i] = y - a[x];
  }
  sort(v + 1, v + m + 1);
  sum[0] = 0;
  for (int i = 1; i <= m; i++) sum[i] = sum[i - 1] + v[i];
  memset(f, 127, sizeof(f));
  f[0] = 0;
  for (int i = 1; i <= p; i++) {
    cnt = Left = 1;
    A[1] = f[0] + v[0];
    B[1] = 0;
    for (int j = 1; j <= m; j++) {
      for (; Left < cnt && 1.0 * A[Left + 1] + B[Left + 1] * v[j] <=
                               1.0 * A[Left] + B[Left] * v[j];
           ++Left)
        ;
      g[j] = A[Left] + B[Left] * v[j] + 1LL * v[j] * j - sum[j];
      long long Ai = f[j] + sum[j], Bi = -j;
      for (; cnt > Left && 1.0 * (A[cnt] - Ai) * (B[cnt - 1] - B[cnt]) >=
                               1.0 * (A[cnt] - A[cnt - 1]) * (Bi - B[cnt]);
           --cnt)
        ;
      A[++cnt] = Ai;
      B[cnt] = Bi;
    }
    memcpy(f, g, sizeof(f));
  }
  printf("%I64d\n", f[m]);
}
