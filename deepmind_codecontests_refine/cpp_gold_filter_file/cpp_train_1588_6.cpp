#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  cout << fixed << setprecision(9) << 1 / tan(3.14159265359 / (2 * n)) << endl;
  return;
}
int main() {
  long long t;
  cin >> t;
  for (int k = 1; k <= t; k++) {
    solve();
  }
  return 0;
}
