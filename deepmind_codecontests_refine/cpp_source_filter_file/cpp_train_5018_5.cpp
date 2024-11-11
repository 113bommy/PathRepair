#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
}
void solve() {
  int a, b;
  int ans = 0;
  cin >> a >> b;
  b = abs(b - a);
  int temp;
  if (b > 5) {
    ans += b / 5;
    b %= 5;
  }
  if (b > 2) {
    ans += b / 2;
    b %= 2;
  }
  if (b != 0) {
    ++ans;
  }
  cout << ans;
}
