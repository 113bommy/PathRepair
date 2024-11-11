#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  double c = sqrt(n);
  if (floor(c) == ceil(c)) {
    cout << 1 << " " << c << "\n";
    return;
  }
  int a = c;
  long long p = pow(a + 1, 2);
  if (p - n > a) {
    cout << n - pow(a, 2) << " " << a + 1 << "\n";
    return;
  }
  cout << a + 1 << " " << p - n + 1 << "\n";
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
