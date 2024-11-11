#include <bits/stdc++.h>
using namespace std;
int n, tot;
long long A, B, a[1000005], ans = 1ll << 60, f[1000005][3];
void Cal(long long x) {
  long long sum, w;
  for (int i = 1; i <= n; i++) {
    if (a[i] % x == 0)
      w = 0;
    else if (a[i] % x == 1 || a[i] % x == x - 1)
      w = B;
    else
      w = 1ll << 35;
    f[i][0] = f[i - 1][0] + w;
    f[i][1] = min(f[i - 1][0], f[i - 1][1]) + A;
    f[i][2] = min(f[i - 1][1], f[i - 1][2]) + w;
  }
  sum = min(f[n][0], min(f[n][1], f[n][2]));
  ans = min(sum, ans);
}
void Push(long long x) {
  if (x <= 1) return;
  long long t = x;
  for (long long i = 2; i * i <= x; i++) {
    if (t % i == 0) {
      Cal(i);
      while (t % i == 0) t /= i;
    }
    if (t == 1) break;
  }
  if (t != 1) Cal(t);
}
int main() {
  scanf("%d%I64d%I64d", &n, &A, &B);
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  Push(a[1]);
  Push(a[1] - 1);
  Push(a[1] + 1);
  Push(a[n]);
  Push(a[n] - 1);
  Push(a[n] + 1);
  printf("%I64d", ans);
  return 0;
}
