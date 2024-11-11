#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
const int N = 1000;
using namespace std;
long long t, w, b;
long long gcd(long long x, long long y) {
  long long t;
  while (y) {
    t = x % y;
    x = y;
    y = t;
  }
  return x;
}
int main() {
  while (cin >> t >> w >> b) {
    if (w > b) swap(w, b);
    long long ans;
    if (t / w * gcd(w, b) / b > 0) {
      long long lcm = w / gcd(w, b) * b;
      ans = t / lcm * w;
      ans += ((t % lcm + 1) < (w) ? (t % lcm + 1) : (w));
    } else
      ans = ((t + 1) < (w) ? (t + 1) : (w));
    ans--;
    int d = gcd(ans, t);
    cout << ans / d << "/" << t / d << endl;
  }
  return 0;
}
