#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  if (n < 10) {
    cout << n;
    return;
  }
  long long t = 1;
  int d = 1;
  while (1) {
    if (t * 10 > n) {
      break;
    }
    t *= 10;
    d++;
  }
  long long ans = (n - t + 1) * d;
  while (t) {
    ans += 9 * t / 10 * (d - 1);
    d--;
    t /= 10;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  cout << fixed << setprecision(12);
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
    cout << "\n";
  }
  return 0;
}
