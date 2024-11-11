#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
long long n, m, bl;
long long w[maxn], nexp[maxn], num[maxn];
inline long long block(long long x) { return (x - 1) / bl + 1; }
int main() {
  scanf("%lld %lld", &n, &m);
  for (long long i = 1; i <= n; i++) scanf("%lld", &w[i]);
  bl = sqrt(n);
  for (long long i = n; i >= 1; i--) {
    if (i + w[i] > n)
      nexp[i] = -1, num[i] = 1;
    else {
      if (block(i) < block(i + w[i]))
        nexp[i] = i + w[i], num[i] = 1;
      else
        nexp[i] = nexp[i + w[i]], num[i] = num[i + w[i]] + 1;
    }
  }
  while (m--) {
    long long op;
    scanf("%lld", &op);
    if (op == 0) {
      long long a, b;
      scanf("%lld %lld", &a, &b);
      w[a] = b;
      for (long long i = a; i >= (block(a) - 1) * bl + 1; i--) {
        if (i + w[i] > n)
          nexp[i] = -1, num[i] = 1;
        else {
          if (block(i) < block(i + w[i]))
            nexp[i] = i + w[i], num[i] = 1;
          else
            nexp[i] = nexp[i + w[i]], num[i] = num[i + w[i]] + 1;
        }
      }
    } else {
      long long a;
      scanf("%d", &a);
      long long ans = 0;
      long long lastp;
      for (long long i = a; i != -1; i = nexp[i]) {
        ans += num[i];
        lastp = i;
        if (nexp[i] == -1 && num[i] > 1) {
          for (long long j = i; j <= n; j += w[j]) lastp = j;
        }
      }
      printf("%lld %lld\n", lastp, ans);
    }
  }
  return 0;
}
