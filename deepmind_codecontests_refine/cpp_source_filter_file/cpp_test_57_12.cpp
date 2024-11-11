#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, s, k;
  cin >> s >> n >> k;
  if (s == k)
    cout << "YES" << endl;
  else if (s < k) {
    cout << "NO" << endl;
  } else {
    auto d = s / (2 * k);
    auto y = s % (2 * k);
    auto p = k * d + min(y, k);
    if (n >= p) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}
