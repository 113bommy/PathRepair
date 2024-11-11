#include <bits/stdc++.h>
using namespace std;
long long ex_gcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  int ans = ex_gcd(b, a % b, y, x);
  y -= a / b * x;
  return ans;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long t[1000000 + 5];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  for (int i = 1; i < 1000000 + 5; i++) t[i] = t[i - 1] + i;
  cin >> n;
  long long x, y;
  ex_gcd(2, 3, x, y);
  x = (x % 3 + 3) % 3;
  x *= n;
  x %= 3;
  if (x == 0) x = 3;
  y = (n - 2 * x) / 3;
  int cnt = 0;
  while (y >= t[x - 1] + x) {
    cnt++;
    x += 3;
    y -= 2;
    if (y <= 0) break;
  }
  cout << cnt << endl;
  return 0;
}
