#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e15;
const int N = 500100;
const int M = 1000100;
int isp[M], prime[M], ptop = 0;
int a[M];
long long p[M];
long long s[M];
long long range(long long s[], int l, int r) {
  return l <= r ? s[r] - s[l - 1] : 0;
}
int main() {
  memset(isp, true, sizeof(isp));
  for (int i = 2; i < M; i++)
    if (isp[i]) {
      prime[ptop++] = i;
      for (long long j = (long long)i * i; j < M; j += i) isp[j] = false;
    }
  memset(a, 0, sizeof(a));
  long long n, x, y;
  scanf("%lld %lld %lld", &n, &x, &y);
  for (int i = 0; i < n; i++) {
    int tmp;
    scanf("%d", &tmp);
    a[tmp]++;
  }
  p[0] = s[0] = 0;
  for (long long i = 1; i < M; i++) {
    p[i] = p[i - 1] + i * a[i];
    s[i] = s[i - 1] + a[i];
  }
  long long ans = INF;
  for (int i = 0; i < ptop; i++) {
    long long cost = 0;
    for (int j = prime[i]; j < M; j += prime[i]) {
      int tmp = (int)max(j - x / y, (long long)j - prime[i] + 1);
      cost += range(s, j - prime[i] + 1, j - x / y - 1) * x +
              (j * range(s, tmp, j) - range(p, tmp, j)) * y;
    }
    ans = min(ans, cost);
  }
  printf("%lld\n", ans);
  return 0;
}
