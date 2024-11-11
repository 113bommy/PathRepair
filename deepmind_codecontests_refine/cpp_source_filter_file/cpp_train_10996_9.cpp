#include <bits/stdc++.h>
using namespace std;
long long n;
long long v[11] = {0,      9,       99,       999,       9999,      99999,
                   999999, 9999999, 99999999, 999999999, 9999999999};
long long t[11] = {0,      1,       10,       100,       1000,      10000,
                   100000, 1000000, 10000000, 100000000, 1000000000};
long long cac(long long msum) {
  long long L = ((1) > (msum - n) ? (1) : (msum - n));
  long long R = min(n, msum - 1);
  return (((R - L + 1) / 2) > (0) ? ((R - L + 1) / 2) : (0));
}
int main() {
  cin >> n;
  long long msum = n + (n - 1);
  int c = 0;
  while (msum > v[c]) {
    c++;
  }
  if (msum == v[c]) {
    printf("%lld\n", cac(msum));
    return 0;
  }
  long long ans = 0;
  for (int pos = 1; pos <= c; pos++) {
    long long tmp = v[c] - 9LL * t[pos];
    for (int i = 1; i <= 9; i++) {
      if (tmp > msum) break;
      ans += cac(tmp);
      tmp += t[pos];
    }
  }
  printf("%lld\n", ans);
}
