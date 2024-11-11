#include <bits/stdc++.h>
using namespace std;
void solve() {
  int i, j, k, m, n, ans = 0, cnt = 0;
  cin >> n >> m;
  if (n - m == 0) {
    cout << 0;
  } else if (m == 0) {
    cout << 1;
  } else if (m <= n / 2)
    cout << (m);
  else {
    cout << n - m;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
