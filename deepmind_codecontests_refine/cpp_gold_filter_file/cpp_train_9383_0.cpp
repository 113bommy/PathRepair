#include <bits/stdc++.h>
using lint = int64_t;
using ulint = uint64_t;
using ivec = std::vector<int>;
using lvec = std::vector<lint>;
using ulvec = std::vector<ulint>;
using namespace std;
int main() {
  lint n, k, m;
  cin >> n >> k >> m;
  lvec heroes(n);
  for (auto& h : heroes) {
    cin >> h;
  }
  double s0 = accumulate(begin(heroes), end(heroes), lint{});
  double avg = (s0 + min(m, k * n)) / n;
  lint rest = 0;
  sort(begin(heroes), end(heroes));
  for (int m1 = 1; m1 < min(n, m + 1); ++m1) {
    rest += heroes[m1 - 1];
    lint m2 = min(m - m1, k * (n - m1));
    avg = max(avg, (s0 - rest + m2) / (n - m1));
  }
  cout << fixed << setprecision(20) << avg;
}
