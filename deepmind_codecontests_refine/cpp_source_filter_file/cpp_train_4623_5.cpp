#include <bits/stdc++.h>
using namespace std;
const long long M = 1e5 + 5;
long long min(long long x, long long y) { return x < y ? x : y; }
long long max(long long x, long long y) { return x > y ? x : y; }
long long read() {
  long long x = 0, y = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') y = (ch == '-') ? -1 : 1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * y;
}
long long X[M], Y[M], XX[M], YY[M];
void solve() {
  long long n = read(), Ans = 0;
  for (long long i = 1; i <= n; i++)
    X[i] = XX[i] = read(), Y[i] = YY[i] = read();
  sort(XX + 1, XX + n + 1), sort(YY + 1, YY + n + 1);
  if (n & 1) {
    long long mid = (n + 1) / 2;
    for (long long i = 1; i < mid; i++) Ans -= 2ll * XX[i] + 2ll * YY[i];
    for (long long i = mid + 1; i <= n; i++) Ans += 2ll * XX[i] + 2ll * YY[i];
    long long pos = 0, flag1 = 0, flag2 = 0;
    for (long long i = 1; i <= n; i++)
      if (X[i] == XX[i] && Y[i] == YY[i]) pos = i;
    for (long long i = 1; i <= n; i++)
      if (i != pos)
        (X[i] <= XX[mid]) ^ (Y[i] <= YY[mid]) ? flag1 = 1 : flag2 = 1;
    if (!pos && flag1 && flag2)
      Ans -= 2ll * min(min(XX[mid + 1] - XX[mid], XX[mid] - XX[mid - 1]),
                       min(YY[mid + 1] - YY[mid], YY[mid] - YY[mid - 1]));
  } else {
    long long mid = n / 2;
    for (long long i = 1; i <= mid; i++) Ans -= 2ll * XX[i] + 2ll * YY[i];
    for (long long i = mid + 1; i <= n; i++) Ans += 2ll * XX[i] + 2ll * YY[i];
    long long flag1 = 0, flag2 = 0;
    for (long long i = 1; i <= n; i++)
      (X[i] <= XX[mid]) ^ (Y[i] <= YY[mid]) ? flag1 = 1 : flag2 = 1;
    if (flag1 && flag2)
      Ans -= 2ll * min(XX[mid + 1] - XX[mid], YY[mid + 1] - YY[mid]);
  }
  printf("%lld\n", Ans);
}
signed main() { solve(); }
