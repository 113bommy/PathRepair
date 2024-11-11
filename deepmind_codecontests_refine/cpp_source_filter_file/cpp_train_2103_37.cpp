#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  int ans1 = 0, ans2;
  if (a % c != 0) {
    ans1 += a / c + 2;
  } else {
    ans1 += a / c;
  }
  if (b % d != 0) {
    ans2 += b / d + 1;
  } else {
    ans2 = b / d;
  }
  if (ans1 + ans2 <= e) {
    cout << ans1 << " " << ans2;
  } else {
    cout << -1;
  }
  cout << endl;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) solve();
  return 0;
}
