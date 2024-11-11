#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a < b) {
    swap(a, b);
  }
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  long long t, w, b;
  cin >> t >> w >> b;
  if (w < b) swap(w, b);
  long long d = gcd(w, b);
  long long mult = t / w;
  long long lcm = -1;
  if (mult >= b / d) {
    lcm = w * (b / d);
  }
  long long ans = 0;
  if (lcm == -1) {
    ans = min(t, b - 1);
  } else {
    long long cycles = t / lcm;
    ans = cycles * b - 1;
    ans += min((t % lcm) + 1, b);
  }
  d = gcd(t, ans);
  cout << (ans / d) << "/" << (t / d) << endl;
  return 0;
}
