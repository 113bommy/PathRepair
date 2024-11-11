#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b != 0) {
    if (1 & b) res *= a;
    b >>= 1;
    a *= a;
  }
  return res;
}
void solve() {
  long long a, b;
  cin >> a >> b;
  if (a == b && a == 0) {
    cout << "0";
  } else if (a == b) {
    cout << "1";
  } else if (abs(a - b) % 2 == 1) {
    cout << "-1";
  } else {
    cout << "2";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tt = 1;
  cin >> tt;
  while (tt--) {
    solve();
    cout << "\n";
  }
  return 0;
}
