#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n = 0;
  cin >> n;
  std::vector<int> count(64, 0);
  for (int i = 0; i < n; ++i) {
    int64_t t;
    cin >> t;
    int j = 0;
    while (t != 0) {
      t = (t >> 1);
      ++j;
    }
    count[j - 1]++;
  }
  int res = 0;
  for (int i = 0; i < 64; ++i) {
    res += (count[i] * (count[i] - 1) / 2);
  }
  std::cout << res << std::endl;
}
int main() {
  int c = 0;
  std::cin >> c;
  for (int i = 0; i < c; ++i) {
    solve();
  }
}
