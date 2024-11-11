#include <bits/stdc++.h>
#pragma GCC optimize "trapv"
using namespace std;
const int N = 1e6 + 10;
const long long MOD = (long long)(1e9) + (long long)(7);
void solve() {
  long long a, b;
  cin >> a >> b;
  if (a == 0 && b == 0) {
    cout << 0 << '\n';
    return;
  }
  if (a < b) swap(a, b);
  if (a == b) {
    cout << 1 << '\n';
  } else if ((a + b) & 1) {
    cout << -1 << '\n';
  } else {
    cout << 2 << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
