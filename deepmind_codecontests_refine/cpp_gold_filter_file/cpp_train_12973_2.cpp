#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  int ans = INT_MAX;
  for (int i = 1; i <= 1010; ++i) {
    for (int j = 1; j <= 1010; ++j) {
      if (i * j >= n) ans = min(ans, 2 * (i + j));
    }
  }
  cout << ans << '\n';
}
