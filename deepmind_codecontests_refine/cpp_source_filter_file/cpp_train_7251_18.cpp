#include <bits/stdc++.h>
using namespace std;
void Run() {
  int n, s;
  cin >> n >> s;
  vector<int> ok;
  vector<bool> in(1440);
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    ok.push_back(60 * x + y);
    in[ok.back()] = true;
  }
  for (int t = 0; t <= 2 * 1440; ++t) {
    if (in[t]) continue;
    auto it = upper_bound(ok.begin(), ok.end(), t);
    bool ss = true;
    if (it != ok.end() && *it - (t + 1) < s) {
      ss = false;
    }
    if (it != ok.begin() && t - *(it - 1) - 1 < s) {
      ss = false;
    }
    if (ss) {
      cout << t / 60 << ' ' << t % 60 << '\n';
      return;
    }
  }
}
int main() {
  srand(time(0));
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  Run();
  return 0;
}
