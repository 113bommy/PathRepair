#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m = 1e9 + 1, p, r, ans = 1e5;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> r;
    if (m > r)
      m = r, p = i, ans = 1e5;
    else if (m == r)
      ans = min(ans, i - p), p = i;
  }
  cout << ans;
}
