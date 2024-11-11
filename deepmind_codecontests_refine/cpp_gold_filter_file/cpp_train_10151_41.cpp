#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  while (a) {
    b %= a;
    swap(a, b);
  }
  return b;
}
bool bad(long long t, long long a, long long b) {
  return t / a < b || (t / a == b && t % a == 0);
}
void print(long long x, long long y) {
  long long g = gcd(x, y);
  cout << x / g << '/' << y / g << endl;
}
int main() {
  long long t, w, b;
  cin >> t >> w >> b;
  if (w == b) {
    cout << "1/1\n";
    return 0;
  }
  long long g = gcd(w, b);
  if (bad(t, w / g, b)) {
    print(min(min(w, b) - (t / (w / g) == b && t % (w / g) == 0 ? 0 : 1), t),
          t);
    return 0;
  }
  long long lcm = w / g * b;
  long long res = (t - 1) / lcm * min(w, b) - (t % lcm == 0 ? 0 : 1);
  res += max(0ll, min(t - (t - 1) / lcm * lcm + 1, min(w, b)));
  print(res, t);
}
