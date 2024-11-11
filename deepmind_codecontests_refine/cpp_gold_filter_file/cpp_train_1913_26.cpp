#include <bits/stdc++.h>
using namespace std;
long long n, x, y, c;
bool check(long long T) {
  long long ans = T * T + (T + 1) * (T + 1);
  if (x + T >= n) {
    ans -= (T - (n - 1 - x)) * (T - (n - 1 - x));
  }
  if (x - T < 0) {
    ans -= (T - x) * (T - x);
  }
  if (y + T >= n) {
    ans -= (T - (n - 1 - y)) * (T - (n - 1 - y));
  }
  if (y - T < 0) {
    ans -= (T - y) * (T - y);
  }
  if (n - x + n - y <= T) {
    long long t = T - (n - x + n - y) + 1;
    ans += t * (t + 1) / 2;
  }
  if (n - x + y + 1 <= T) {
    long long t = T - (n - x + y + 1) + 1;
    ans += t * (t + 1) / 2;
  }
  if (x + 1 + n - y <= T) {
    long long t = T - (x + 1 + n - y) + 1;
    ans += t * (t + 1) / 2;
  }
  if (x + 1 + y + 1 <= T) {
    long long t = T - (x + 1 + y + 1) + 1;
    ans += t * (t + 1) / 2;
  }
  return ans >= c;
}
int main() {
  cin >> n >> x >> y >> c;
  --x, --y;
  long long L = -1, R = n * 3;
  while (L + 1 < R) {
    long long M = (L + R) / 2;
    if (check(M))
      R = M;
    else
      L = M;
  }
  cout << R << endl;
  return 0;
}
