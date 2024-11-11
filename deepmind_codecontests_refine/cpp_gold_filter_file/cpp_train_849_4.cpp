#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, b, all = 0, n_time, nechet = 0, chet = 0, otr = 0, ans = 0;
  cin >> n;
  n_time = n;
  while (n) {
    all += n;
    cin >> b;
    if (otr % 2 == 0) {
      chet++;
    } else {
      nechet++;
    }
    if (b < 0) {
      otr++;
    }
    if (otr % 2 == 0) {
      ans += chet;
    } else {
      ans += nechet;
    }
    n--;
  }
  cout << all - ans << " " << ans;
}
int main() { solve(); }
