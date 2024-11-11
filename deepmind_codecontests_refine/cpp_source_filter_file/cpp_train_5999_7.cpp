#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long n, r = -1, left, ans = 0;
  bool b[1000001];
  cin >> n;
  left = 25 - n;
  for (long long f = 0; f <= n - 1; ++f) {
    long x;
    cin >> x;
    b[x] = 1;
    r = max(r, x);
  }
  for (long long f = 1; f <= r; ++f) {
    if (b[f] == 0) {
      if (left) {
        left--;
      } else {
        ans++;
      }
    }
  }
  cout << ans;
  return 0;
}
