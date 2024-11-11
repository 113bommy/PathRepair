#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  long long solve(int n, int m) {
    ++m;
    int h = 0;
    while (1LL << (h + 1) <= max(m, n)) {
      ++h;
    }
    long long mask = 0;
    long long prefix = 0;
    vector<pair<long long, long long>> ranges;
    for (int i = h; i >= 0; --i) {
      mask |= 1LL << i;
      if ((m >> i) & 1) {
        long long P = (n & mask) ^ prefix;
        long long mn = P;
        long long mx = P + (1LL << i) - 1;
        ranges.emplace_back(mn, mx);
        prefix |= 1LL << i;
      }
    }
    sort(ranges.begin(), ranges.end());
    int res = 0;
    for (auto& p : ranges) {
      long long l = p.first;
      long long r = p.second;
      if (l != res) {
        break;
      }
      res = r + 1;
    }
    return res;
  }
};
int main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution sol;
  int t;
  cin >> t;
  while (t-- > 0) {
    int n, m;
    cin >> n >> m;
    cout << sol.solve(n, m) << '\n';
  }
  return 0;
}
