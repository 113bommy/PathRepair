#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int64_t q;
  cin >> q;
  for (; q; --q) {
    vector<int64_t> ans(3);
    int64_t m = 1000000000;
    int64_t a, b, c;
    cin >> a >> b >> c;
    for (int64_t A = 1; A < 2 * a; ++A) {
      for (int64_t B = A; B < 2 * b; B += A) {
        int64_t C = c / B * B;
        if (C + B - c < c - C) C += b;
        if (abs(A - a) + abs(B - b) + abs(C - c) < m) {
          m = abs(A - a) + abs(B - b) + abs(C - c);
          ans[0] = A;
          ans[1] = B;
          ans[2] = C;
        }
      }
    }
    cout << m << '\n';
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
  }
  return 0;
}
