#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, ans = 0;
  cin >> n;
  for (long long h = 1; 3 * h * (h + 1) / 2 <= n + h; ++h) {
    if ((n + h) % 3 == 0) {
      ++ans;
    }
  }
  cout << ans << endl;
}
int main() {
  { ios::sync_with_stdio(false), cout << fixed << setprecision(10); }
  solve();
  return 0;
}
