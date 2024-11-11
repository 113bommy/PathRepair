#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int MAXN = 2e3 + 5;
const int INF = 200000000;
const double EPS = 1e-6;
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int t = abs(a + b);
  if (c < t) {
    cout << "No" << endl;
    return;
  } else if (c - t == 0) {
    cout << "Yes" << endl;
    return;
  } else if ((c - t) % 2 == 0) {
    cout << "Yes" << endl;
    return;
  } else if ((c - t) % 2 == 1) {
    cout << "No" << endl;
    return;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) solve();
  return 0;
}
