#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  long long t, a, b;
  cin >> t >> a >> b;
  long long gd = gcd(a, b);
  long long minn = min(a, b);
  double lcm = a * 1.0 / gd * b;
  long long re;
  if (lcm > t) {
    re = min(minn - 1, t);
  } else {
    re = t / (long long)lcm * minn;
    re += min(t % (long long)lcm, minn - 1);
  }
  cout << re / gcd(re, t) << "/" << t / gcd(re, t) << endl;
}
