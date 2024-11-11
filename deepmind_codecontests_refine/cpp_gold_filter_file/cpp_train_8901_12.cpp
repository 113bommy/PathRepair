#include <bits/stdc++.h>
using namespace std;
int arr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
void solve() {
  int d, x;
  int a, b;
  cin >> a >> b;
  int ans = 0;
  for (int i = a; i <= b; i++) {
    x = i;
    while (x) {
      d = x % 10;
      x = x / 10;
      ans += arr[d];
    }
  }
  cout << ans << endl;
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
