#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  if (a == 0) return b;
  return gcd(b, a % b);
}
int main() {
  long long t, w, b;
  cin >> t >> w >> b;
  long long g = gcd(w, b);
  long long mn = min(w, b);
  long long lcm;
  if (log(w / g) + log(b) > 63. * log(2) + 1e-9)
    lcm = -1;
  else
    lcm = w / g * b;
  if (lcm * g != w * b) lcm = -1;
  long long ans1 = 0;
  if (t >= lcm && lcm != -1) {
    ans1 = (t / lcm) * mn - 1;
    long long tmp = lcm * (t / lcm);
    long long tt = t - tmp + 1;
    ans1 += min(tt, mn);
  } else {
    ans1 = min(t, mn - 1);
  }
  long long ans2 = t;
  g = gcd(ans1, ans2);
  ans1 /= g;
  ans2 /= g;
  cout << (long long)ans1 << "/" << (long long)ans2 << endl;
  return 0;
}
