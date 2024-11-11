#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int64_t n;
    cin >> n;
    if (n == 1) {
      cout << 0 << "\n";
      continue;
    }
    int count = 0;
    int first = 1;
    int64_t res = INT_MAX;
    for (int i = 1; i <= 63500; ++i) {
      first += 1;
      count += 1;
      int64_t sum = first;
      res = min(res, (((n - sum) + (first - 1)) / first) + count);
    }
    cout << res << "\n";
  }
}
