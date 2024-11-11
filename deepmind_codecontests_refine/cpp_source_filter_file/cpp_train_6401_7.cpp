#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long sum = 0, ff = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') ff = -1;
    ch = getchar();
  }
  while (isdigit(ch)) sum = sum * 10 + (ch ^ 48), ch = getchar();
  return sum * ff;
}
const long long N = 3e5 + 5;
const long long M = 1e6 + 5;
long long n, m, a[N], sum[N], ans, L[N], R[N];
long long stak[N], top;
vector<long long> P[M];
inline long long query(long long k, long long l, long long r) {
  return upper_bound(P[k].begin(), P[k].end(), r) -
         lower_bound(P[k].begin(), P[k].end(), l);
}
signed main() {
  n = read();
  m = read();
  P[0].push_back(0);
  for (long long i = 1; i <= n; i++) {
    a[i] = read();
    sum[i] = (sum[i - 1] + a[i]) % m;
    P[sum[i]].push_back(i);
  }
  a[n + 1] = 1e9;
  stak[top = 1] = 0;
  for (long long i = 1; i <= n; i++) {
    while (top && a[stak[top]] < a[i]) top--;
    L[i] = stak[top];
    stak[++top] = i;
  }
  stak[top = 1] = n + 1;
  for (long long i = n; i >= 1; i--) {
    while (top && a[stak[top]] <= a[i]) top--;
    R[i] = stak[top];
    stak[++top] = i;
  }
  for (long long i = 1; i <= n; i++) a[i] %= m;
  for (long long i = 1; i <= n; i++) {
    if (i - L[i] < R[i] - i)
      for (long long j = L[i] + 1; j <= i; j++)
        ans = (ans + query((sum[j - 1] + a[i]) % m, i, R[i] - 1));
    else
      for (long long j = i; j < R[i]; j++)
        ans = (ans + query((sum[j] - a[i] + m) % m, L[i], i - 1));
  }
  printf("%lld\n", max(0ll, ans - n));
  return 0;
}
