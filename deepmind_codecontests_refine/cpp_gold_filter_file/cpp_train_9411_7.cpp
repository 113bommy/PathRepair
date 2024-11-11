#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, m, x, y, i, j, ans = 0, c = 0, sum = 0;
  long long int a, b;
  cin >> a >> b >> c;
  if ((a + b + c) % 2 != 0) {
    cout << "Impossible\n";
    return;
  }
  for (i = 0; i < min(a, b) + 1; i++) {
    if (((a - i) + (b - i)) == c) {
      cout << i << " " << b - i << " " << a - i << "\n";
      return;
    }
  }
  cout << "Impossible"
       << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
