#include <bits/stdc++.h>
using namespace std;
long long n, row, col, c;
long long over_top_bot(long long over) { return over * over; }
long long over_left_right(long long over) {
  long long base = over * over;
  long long top_bad = (over >= row) ? ((over - row) * (over - row + 1)) / 2 : 0;
  long long bot_bad =
      (over >= n - row + 1)
          ? ((over - (n - row + 1)) * (over - (n - row + 1) + 1)) / 2
          : 0;
  return base - top_bad - bot_bad;
}
long long total_area(long long h) {
  long long quarter = (h * (h + 1)) / 2;
  return 4LL * quarter - 4LL * h + 1;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin >> n >> row >> col >> c;
  long long bot = 0;
  long long top = 2LL * n;
  while (bot + 1 != top) {
    long long mid = (bot + top) / 2LL;
    long long over_top = max(0LL, mid - row);
    long long over_bot = max(0LL, mid - (n - row + 1));
    long long over_left = max(0LL, mid - col);
    long long over_right = max(0LL, mid - (n - col + 1));
    long long all = total_area(mid) - over_top_bot(over_top) -
                    over_top_bot(over_bot) - over_left_right(over_left) -
                    over_left_right(over_right);
    if (all >= c)
      top = mid;
    else
      bot = mid;
  }
  cout << top - 1 << endl;
  return 0;
}
