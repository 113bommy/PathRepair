#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  return (b == 0 ? a : gcd(b, a % b));
}
long long int lcm(int a, int b) { return (a * (b / gcd(a, b))); }
long long int max(long long int a, long long int b, long long int c) {
  return max(a, max(b, c));
}
long long int power(long long int x, long long int y) {
  long long int ans = 1;
  while (y > 0) {
    if (y & 1) ans = (ans * x) % 1000000007;
    x = (x * x) % 1000000007;
    y /= 2;
  }
  return ans;
}
int main() {
  long long int t, n, h1, h2, a, b;
  cin >> h1 >> h2 >> a >> b;
  n = h2 - h1;
  if (8 * a >= n)
    cout << "0" << endl;
  else if (20 * a < (12 * b + n))
    cout << "-1" << endl;
  else if ((12 * b + n) <= 20 * a)
    cout << "1" << endl;
  else {
    long long int day = 1;
    n = n - 8 * a + 12 * b - 12 * a;
    while (n > 0) {
      n += 12 * b;
      n -= 12 * a;
      day++;
    }
    cout << day << endl;
  }
}
