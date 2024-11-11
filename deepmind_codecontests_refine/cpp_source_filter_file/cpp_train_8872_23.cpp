#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
template <class T>
T gcd(T a, T b) {
  return ((b == 0) ? a : gcd(b, a % b));
}
void solve() {
  long long n;
  cin >> n;
  if (n % 2 == 0)
    cout << 2 << endl;
  else
    cout << 1 << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
