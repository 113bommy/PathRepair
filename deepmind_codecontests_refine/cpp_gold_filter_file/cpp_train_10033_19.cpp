#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  if (n <= 5) {
    cout << "0" << endl;
    return;
  }
  int ans = 0;
  for (int i = 6; i <= n; i++) {
    int c = 0;
    int t = i;
    for (long long j = 2; j * j <= t; j++) {
      if ((t % j) == 0) {
        c++;
        while ((t % j) == 0) {
          t /= j;
        }
      }
    }
    if (t > 1) {
      c++;
    }
    if (c == 2) {
      ans++;
    }
  }
  cout << ans << endl;
}
int main() {
  solve();
  return 0;
}
