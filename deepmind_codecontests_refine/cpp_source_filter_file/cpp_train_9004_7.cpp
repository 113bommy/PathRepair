#include <bits/stdc++.h>
using namespace std;
const long long SIZE = (long long)3e5 + 50;
const long long NUM = 15;
const long long TOT = 5;
const long long SUM = (long long)1e2 + 50;
const long long inf = (long long)1e18 + 50;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return f * x;
}
long long n, ans;
long long num[SIZE], high[SIZE], ls[SIZE], rs[SIZE], cnt[SIZE];
signed main() {
  n = read();
  long long indax = 0;
  for (long long i = 1; i < n; ++i) num[i] = read();
  for (long long i = 1; i < n; ++i)
    if (num[i] > num[indax]) indax = i;
  for (long long i = 0; i <= n; ++i) high[i] = num[(i + indax) % n];
  for (long long i = 1; i <= n; ++i) {
    ls[i] = i - 1;
    while (ls[i] && high[i] >= high[ls[i]]) ls[i] = ls[ls[i]];
  }
  for (long long i = n - 1; i >= 0; --i) {
    rs[i] = i + 1;
    while (rs[i] < n && high[i] > high[rs[i]]) rs[i] = rs[rs[i]];
    if (rs[i] < n && high[i] == high[rs[i]]) {
      cnt[i] = cnt[rs[i]] + 1;
      rs[i] = rs[rs[i]];
    }
  }
  for (long long i = 0; i < n; ++i) {
    ans += cnt[i];
    if (high[i] < high[0]) {
      ans += 2;
      if (!ls[i] && rs[i] == n) ans--;
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
