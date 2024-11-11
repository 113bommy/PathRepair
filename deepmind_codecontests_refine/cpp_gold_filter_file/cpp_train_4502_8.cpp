#include <bits/stdc++.h>
using namespace std;
const int INF = 0X3F3F3F3F;
const int MIN = -(1 << 30);
const long long N = 1e5 + 7;
inline void solve() {
  long long n;
  cin >> n;
  if (n < 3) {
    cout << 0 << endl;
    return;
  }
  if (n & 1)
    cout << n / 2 << endl;
  else
    cout << n / 2 - 1 << endl;
}
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
