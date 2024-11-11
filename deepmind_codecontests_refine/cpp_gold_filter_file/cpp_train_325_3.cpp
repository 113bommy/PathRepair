#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  string second;
  cin >> second;
  int brojac = 0;
  for (int i = n - x; i < n; i++) {
    if (i == n - y - 1)
      brojac += (second[i] == '0');
    else
      brojac += (second[i] == '1');
  }
  cout << brojac;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tt = 1;
  while (tt--) solve();
  return 0;
}
