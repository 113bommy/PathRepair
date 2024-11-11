#include <bits/stdc++.h>
using namespace std;
void test_case() {
  long long a, b, c;
  cin >> a >> b >> c;
  if (a >= c)
    cout << -1 << " ";
  else
    cout << 1 << " ";
  if (a * b == c)
    cout << -1 << "\n";
  else
    cout << b << "\n";
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    test_case();
  }
  return 0;
}
