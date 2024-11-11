#include <bits/stdc++.h>
using namespace std;
const long long N = 5e4 + 5;
const long long K = 505;
long long dx[4] = {-1, 0, 1, 0};
long long dy[4] = {0, -1, 0, 1};
long long binpow(long long a, long long n) {
  long long i = 1;
  while (n > 0) {
    if (n & 1) i = (i * a);
    a = (a * a);
    n = n >> 1;
  }
  return i;
}
long long isprime(long long n) {
  if (n == 0 || n == 1) return n;
  if (n % 2 == 0) return (long long)2;
  if (n % 3 == 0)
    return (long long)3;
  else {
    for (long long i = 5; i * i <= n; i += 6) {
      if (n % i == 0) return i;
      if (n % (i + 2) == 0) return (i + 2);
    }
    return n;
  }
}
void solve(long long k, long long i) {
  if (k == 0) return;
  cout << i << " " << i + 1 << "\n";
  ;
  solve(k - 1, i + 1);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(NULL));
  ;
  long long l, r, n, k, m, i, j, a, b, c, t, x, y, d;
  cin >> n >> k;
  j = (n - 1) / k;
  y = (n - 1) % k;
  ;
  if (y == 0) {
    cout << 2 * j << "\n";
    ;
  } else if (y == 1) {
    cout << 2 * j + 1 << "\n";
    ;
  } else
    cout << 2 * (j + 1) << "\n";
  ;
  x = 2;
  for (i = 0; i < k; ++i) {
    if (i < y) {
      cout << "1 " << x << "\n";
      solve(j, x);
      x += j;
    } else {
      cout << "1 " << x << "\n";
      solve(j - 1, x);
      x += j;
    }
  }
}
