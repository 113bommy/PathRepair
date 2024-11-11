#include <bits/stdc++.h>
using namespace std;
int T, n, k;
void solve() {
  cin >> n >> k;
  if ((n * (n - 1)) / 2 < k) {
    cout << "no solution" << endl;
    return;
  } else {
    cout << "0 0" << endl;
    int d = n - 1, prevy = 0;
    for (long long i = (long long)1; i <= (long long)n - 1; i++) {
      prevy += d;
      cout << 0 << " " << prevy << endl;
      d--;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
