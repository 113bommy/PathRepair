#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}
int main() {
  long long t, w, b;
  cin >> t >> w >> b;
  long long lcm = (w / gcd(w, b));
  long long ans = 0;
  ans += min(w - 1, b - 1);
  if (ans > t)
    cout << "1/1";
  else if (t / lcm < b) {
    long long div = gcd(ans, t);
    cout << ans / div << "/" << t / div;
  } else {
    lcm *= b;
    ans += (t / lcm - 1) * min(w, b);
    ans += min(t + 1 - (t / lcm) * lcm, min(w, b));
    long long div = gcd(ans, t);
    cout << ans / div << "/" << t / div;
  }
  return 0;
}
