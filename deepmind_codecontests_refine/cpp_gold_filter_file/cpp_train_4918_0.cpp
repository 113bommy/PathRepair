#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, a, b;
  cin >> n >> a >> b;
  string letter = "abcdefghijklmnopqrstuvwxyz";
  string ans = "";
  int counter = 1;
  while (counter <= n) {
    for (int i = 1; i <= b; i++) {
      ans += letter[i - 1];
      counter++;
      if (counter > n) break;
    }
    if (counter > n) break;
    for (int i = b + 1; i <= a; i++) {
      ans += letter[b - 1];
      counter++;
      if (counter > n) break;
    }
    if (counter > n) break;
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
