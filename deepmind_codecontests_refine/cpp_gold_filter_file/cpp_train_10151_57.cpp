#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  long long x = a;
  long long y = b;
  while (x != 0 && y != 0) {
    x %= y;
    if (x == 0 || y == 0) break;
    y %= x;
  }
  return x + y;
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
double dlcm(long long a, long long b) {
  return ((double)a / gcd(a, b)) * (double)b;
}
long long min(long long a, long long b) {
  if (a < b)
    return a;
  else
    return b;
}
long long max(long long a, long long b) {
  if (a > b)
    return a;
  else
    return b;
}
int main() {
  long long t, w, b;
  cin >> t >> w >> b;
  long long Lcm, num;
  if (dlcm(w, b) > 1e18)
    Lcm = -1;
  else
    Lcm = lcm(w, b);
  if (Lcm != -1) {
    num = (t / Lcm + 1) * min(w, b);
    if (t % Lcm + 1 < min(w, b)) num -= (min(w, b) - t % Lcm - 1);
    num--;
  } else
    num = min(min(w, b) - 1, t);
  long long div = gcd(num, t);
  num /= div;
  t /= div;
  cout << num << "/" << t << endl;
}
