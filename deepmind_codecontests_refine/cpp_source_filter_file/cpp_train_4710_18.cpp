#include <bits/stdc++.h>
using namespace std;
long long f(long long p, long long n, long long k) {
  if (k == 0) return p + n;
  if (k == 1) {
    for (int i = 0; i < 60; i += 2) {
      if ((n & (1ll << i)) != 0 and (n & (1ll << (i + 1))) != 0) {
        n -= (1ll << (i + 1));
      } else if ((n & (1ll << i)) != 0 and (n & (1ll << (i + 1))) == 0) {
        n += (1ll << (i + 1));
        n -= (1ll << i);
      } else if ((n & (1ll << i)) == 0 and (n & (1ll << (i + 1))) != 0) {
        n += (1ll << i);
      }
    }
    return 2 * p + n;
  }
  for (int i = 0; i < 60; i += 2) {
    if ((n & (1ll << i)) != 0 and (n & (1ll << (i + 1))) != 0) {
      n -= (1ll << i);
    } else if ((n & (1ll << i)) != 0 and (n & (1ll << (i + 1))) == 0) {
      n += (1ll << (i + 1));
    } else if ((n & (1ll << i)) == 0 and (n & (1ll << (i + 1))) != 0) {
      n += (1ll << i);
      n -= (1ll << (i + 1));
    }
  }
  return 3 * p + n;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, n, p, k, sum, i = 1;
  cin >> t;
  while (t--) {
    n = i++;
    n--;
    p = 1;
    k = n % 3;
    n = n / 3;
    sum = 0;
    while (sum + p <= n) {
      sum += p;
      p = p * 4;
    }
    cout << f(p, n - sum, k) << "\n";
  }
  return 0;
}
