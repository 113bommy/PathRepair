#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b) {
  if (b == 0) return 1;
  long long res = binpow(a, b / 2);
  if (b & 1)
    return res * res % 1000000007 * a % 1000000007;
  else
    return res * res % 1000000007;
}
int x, y, n;
long long sum;
bool check(long long z) {
  while (z) {
    if ((z % 10 != x) && (z % 10 != y)) return 0;
    z /= 10;
  }
  return 1;
}
int main() {
  cin >> x >> y >> n;
  long long a = 1, b = 1;
  if (check(x * n)) sum++;
  for (int i = 1; i <= n; ++i) {
    b = b * i % 1000000007, a = a * (n - i + 1) % 1000000007;
    if (check(i * x + (n - i) * y)) {
      long long x = binpow(b, 1000000007 - 2);
      sum = (sum + a * x % 1000000007) % 1000000007;
    }
  }
  cout << sum << "\n";
  return 0;
}
