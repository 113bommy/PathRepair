#include <bits/stdc++.h>
using namespace std;
namespace {
void Solve(int64_t) {
  int64_t n;
  cin >> n;
  vector<int64_t> pts(2 * n);
  for (auto &p : pts) cin >> p;
  sort(pts.begin(), pts.end());
  int64_t res = (pts[n - 1] - pts.front()) * (pts.back() - pts[n]);
  for (int64_t i = n, __i = 2 * n - 1; i < __i; ++i) {
    res = min(res, (pts.back() - pts.front()) * (pts[i] - pts[i - n + 1]));
  }
  cout << res << endl;
}
void Init() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}
}  // namespace
int32_t main() {
  Init();
  int64_t tests = 1;
  for (int64_t test = 1, __test = tests + 1; test < __test; ++test) Solve(test);
  return 0;
}
