#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
  int n;
  cin >> n;
  vector<int> m(n), r(n);
  unsigned long long lcm = 1;
  for (int i = 0; i < n; ++i) {
    cin >> m[i];
    lcm *= m[i] / gcd(m[i], lcm);
  }
  for (int i = 0; i < n; ++i) cin >> r[i];
  long long ans;
  for (int d = 0; d < lcm; ++d) {
    for (int i = 0; i < n; ++i)
      if (d % m[i] == r[i]) {
        ++ans;
        break;
      }
  }
  cout.setf(ios::fixed | ios::showpoint);
  cout.precision(6);
  cout << 1.0 * ans / lcm;
}
