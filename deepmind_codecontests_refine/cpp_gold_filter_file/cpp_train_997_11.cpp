#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int N = 1e5 + 5;
vector<LL> sum[4];
LL check(int two, int three, int rem) {
  LL rv = 0;
  if (two > 0) rv += sum[2][two - 1];
  if (three > 0) rv += sum[3][three - 1];
  int one = rem - two * 2 - three * 3;
  assert(one >= 0);
  one = min(one, (int)sum[1].size());
  if (one > 0) rv += sum[1][one - 1];
  return rv;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int w, c;
    cin >> w >> c;
    sum[w].push_back(c);
  }
  for (int i = 1; i <= 3; i++) sort(sum[i].rbegin(), sum[i].rend());
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j < sum[i].size(); j++) {
      sum[i][j] += sum[i][j - 1];
    }
  }
  LL best = 0;
  for (int three = 0; three <= sum[3].size(); three++) {
    if (three * 3 > m) break;
    int cnt1 = min((int)sum[2].size(), (m - three * 3) / 2);
    int two = -1;
    for (int b = cnt1; b >= 1; b /= 2) {
      while (two + b + 1 <= cnt1 &&
             check(two + b, three, m) < check(two + b + 1, three, m)) {
        two += b;
      }
    }
    LL cur = check(two + 1, three, m);
    best = max(best, cur);
  }
  cout << best << "\n";
}
