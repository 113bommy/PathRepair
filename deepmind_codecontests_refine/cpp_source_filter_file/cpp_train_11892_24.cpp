#include <bits/stdc++.h>
using namespace std;
const int modulo = 1000000007;
long long step(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2 == 1)
    return (step(a, b - 1) * a) % modulo;
  else {
    long long ans = step(a, b / 2);
    ans *= ans;
    ans %= modulo;
    return ans;
  }
}
long long c(long long a, long long b) {
  if (a < b) return 0;
  long long f1 = 1;
  long long f2 = 1;
  long long f3 = 1;
  for (long long i = 1; i <= a; i++) f1 = (f1 * i) % modulo;
  for (long long i = 1; i <= b; i++) f2 = (f2 * i) % modulo;
  for (long long i = 1; i <= a - b; i++) f3 = (f3 * i) % modulo;
  f2 = (f2 * f3) % modulo;
  f2 = step(f2, modulo - 2);
  return (f1 * f2) % modulo;
}
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long ans = 1;
  ans *= c(n - 1, 2 * k);
  ans *= c(m - 1, 2 * k);
  cout << ans << endl;
  return 0;
}
