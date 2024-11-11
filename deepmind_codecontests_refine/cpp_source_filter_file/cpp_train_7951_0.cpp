#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
int main() {
  int n;
  cin >> n;
  int count = 0;
  for (int s = 1; s * s + (s + 1) * (s + 1) <= n; s++) {
    for (int t = s + 1;; t++) {
      if ((s * s + t * t) > n) {
        break;
      }
      if (gcd(s, t) != 1) {
        continue;
      }
      if (gcd(gcd(s * s + t * t, s * s - t * t), 2 * s * t) != 1) {
        continue;
      }
      count += n / (s * s + t * t);
    }
  }
  cout << count << endl;
}
