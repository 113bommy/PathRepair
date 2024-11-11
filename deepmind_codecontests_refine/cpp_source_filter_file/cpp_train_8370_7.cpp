#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7, inf = 1e18;
const long long M = 1e6;
long long a[M];
long long f(long long x) {
  if (x % 2 == 1) return x * (x - 1) / 2;
  return x * (x - 1) / 2 + x / 2;
}
long long n, m;
int main() {
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    long long x;
    cin >> x >> a[i];
  }
  sort(a, a + m);
  long long cnt = 0;
  for (long long i = 1; i < m + 1; i++) {
    if (f(i) <= n) {
      cnt += a[m - i];
    } else {
      cout << cnt;
      return 0;
    }
  }
  cout << cnt;
}
