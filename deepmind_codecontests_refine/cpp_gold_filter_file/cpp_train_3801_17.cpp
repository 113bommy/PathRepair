#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long N;
  cin >> N;
  long long maxv1 = cbrt(N) * 2 + 1;
  vector<pair<long long, long long> > ret;
  for (long long i = 1; i <= maxv1; ++i) {
    if (i % 2 == 0) {
      if (N * 6 % i != 0) continue;
      long long x1 = N * 6 / i - (i - 1) * (2 * i - 1) + i * (i - 1) * 3;
      long long x2 = (i + 1) * 3;
      if (x1 % x2 == 0) {
        if (x1 / x2 < i) break;
        ret.push_back(make_pair(i, x1 / x2));
      }
    } else {
      if (N * 6 % i != 0) continue;
      long long x1 = N * 6 / i - (i - 1) * (2 * i - 1) + i * (i - 1) * 3;
      long long x2 = (i + 1) * 3;
      if (x1 % x2 == 0) {
        if (x1 / x2 < i) break;
        ret.push_back(make_pair(i, x1 / x2));
      }
    }
  }
  int c1 = 0;
  for (int i = 0; i < ret.size(); ++i)
    if (ret[i].first == ret[i].second) c1 += 1;
  cout << ret.size() * 2 - c1 << "\n";
  for (auto i : ret) cout << i.first << " " << i.second << "\n";
  reverse(ret.begin(), ret.end());
  for (auto i : ret)
    if (i.second != i.first) cout << i.second << " " << i.first << "\n";
  return 0;
}
