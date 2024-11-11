#include <bits/stdc++.h>
using namespace std;
namespace {
void Solve(int) {
  int n;
  cin >> n;
  const int hort = (n + 1) / 2, vert = n - hort + 1;
  for (int i = 0, __i = hort; i < __i; ++i)
    cout << "0 " << (i - hort / 2) << endl;
  for (int j = 0, __j = vert; j < __j; ++j)
    if (j != vert / 2) cout << (j - vert / 2) << " 0" << endl;
}
void Init() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}
}  // namespace
int32_t main() {
  Init();
  int tests = 1;
  for (int test = 1, __test = tests + 1; test < __test; ++test) Solve(test);
  return 0;
}
