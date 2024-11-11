#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long x, y, n;
  cin >> x >> y >> n;
  long long test;
  test = (n / x) * x + y;
  while (test > n) {
    test -= x;
  }
  cout << test << endl;
}
int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    solve();
  }
  return 0;
}
