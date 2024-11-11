#include <bits/stdc++.h>
using namespace std;
long long int inf = 1e18;
long long int p = 1e9 + 7;
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int pwr(long long int x, long long int y) {
  long long int res = 1;
  x = x;
  while (y > 0) {
    if (y & 1) res = (res * x);
    y = y >> 1;
    x = (x * x);
  }
  return res;
}
long long int modInverse(long long int n, long long int p) {
  return power(n, p - 2, p);
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int i, j, y, x, z, w, g, key, k, n, h, m, t, a, b, c;
  long long int t2, t3, t4, t1, t5, t6;
  string s;
  cin >> t;
  long long int N = 1e6;
  vector<long long int> prime(N + 1, 1), ans(N + 1, 0);
  ans[1] = 1;
  for (i = 2; i <= N; i++) {
    if (prime[i]) {
      for (j = i * i; j <= N; j += i) prime[j] = 0;
      ans[i] += 1;
      if (i * i + 1 <= N) {
        ans[i * i + 1] -= 1;
      }
    }
  }
  for (i = 2; i <= N; i++) {
    ans[i] = ans[i] + ans[i - 1];
  }
  while (t--) {
    cin >> n;
    cout << ans[n] << "\n";
  }
  return 0;
}
