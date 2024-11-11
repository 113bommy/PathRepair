#include <bits/stdc++.h>
using namespace std;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, -1, 0, 1};
unsigned long long GCD(unsigned long long x, unsigned long long y) {
  if (y == 0)
    return x;
  else
    return GCD(y, x % y);
}
unsigned long long LCM(unsigned long long a, unsigned long long b) {
  return (a * b / (GCD(a, b)));
}
bool PRIME(int p) {
  if (p <= 1) return false;
  if (p <= 3) return true;
  if (p % 2 == 0 || p % 3 == 0) return false;
  for (int i = 5; p >= i * i; i = i + 6) {
    if (p % i == 0 || p % (i + 2) == 0) return false;
  }
  return true;
}
int main() {
  long long a, b, c, d, e, t, i, j, k, l, sum = 0, ans = 0, x, y, z, m, n,
                                          mx = -1, mn = 1e9;
  while (cin >> a) {
    sum += (a * ans);
    ans++;
  }
  cout << ans << endl;
  return 0;
}
