#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, m, ans;
  cin >> n >> m;
  ans = m / 2;
  ans *= n;
  if (m & 1) {
    ans += m / 2;
  }
  cout << ans << endl;
}
int main() {
  solve();
  return 0;
}
