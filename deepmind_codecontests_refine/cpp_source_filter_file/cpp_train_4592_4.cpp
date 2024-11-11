#include <bits/stdc++.h>
using namespace std;
long long q, a, b, i, s;
void solve() {
  cin >> a >> b;
  if (a - b != 1) {
    cout << "NO" << '\n';
    return;
  }
  for (i = 2; i * i < a + b; i++) {
    if ((a + b) % i == 0) {
      cout << "NO" << '\n';
      return;
    }
  }
  cout << "YES" << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> q;
  while (q--) {
    solve();
  }
  return 0;
}
