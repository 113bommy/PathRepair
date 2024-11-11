#include <bits/stdc++.h>
using namespace std;
long long n, k, deno, nume;
long long expo(long long a, long long b) {
  long long ret = 1;
  for (int i = 62; i >= 0; i--) {
    ret *= ret;
    ret %= 1000003;
    if ((1ll << i) & b) {
      ret *= a;
      ret %= 1000003;
    }
  }
  return ret;
}
int main() {
  cin >> n >> k;
  if (n <= 62 && (1ll << n) < k) {
    cout << "1 1";
    return 0;
  }
  long long all = 1;
  long long st = expo(2, n);
  if (k >= 1000003)
    all = 0;
  else {
    for (long long i = 0; i < k; i++) {
      all *= (st + 1000003 - i);
      all %= 1000003;
    }
    all *= expo(expo(500002, n), k);
  }
  deno = expo(expo(2, n), k);
  long long cnt = n;
  long long b = 2;
  while (b < k) {
    cnt += (k - 1) / b;
    b *= 2;
  }
  deno *= expo(500002, cnt);
  deno %= 1000003;
  nume = deno * all;
  nume %= 1000003;
  nume = (deno - nume + 1000003) % 1000003;
  cout << nume << ' ' << deno;
}
