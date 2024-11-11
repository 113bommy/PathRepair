#include <bits/stdc++.h>
int main(void) {
  using namespace std;
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int T;
  cin >> T;
  for (int case_num = 1; case_num <= T; ++case_num) {
    int64_t d = 0, n, x, y;
    cin >> n >> x >> y;
    for (int64_t i = 1; i <= y; ++i)
      if ((x % i == y % i) && y - i * (n - 1) <= x) {
        d = i;
        break;
      }
    if (d == 0) d = y - x;
    x = y + d;
    while (n) {
      cout << y << ' ';
      --n;
      if (y <= d) break;
      y -= d;
    }
    while (n) {
      cout << x << ' ';
      --n;
      x += d;
    }
    cout << '\n';
  }
  return 0;
}
