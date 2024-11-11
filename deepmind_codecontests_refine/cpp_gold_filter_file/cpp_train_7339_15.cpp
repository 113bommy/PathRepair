#include <bits/stdc++.h>
using namespace std;
template <typename T>
using V = vector<T>;
const long long mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  V<V<size_t> > p[2];
  p[0].resize(8);
  p[1].resize(8);
  for (__typeof(8) i = (0) - ((0) > (8)); i != (8) - ((0) > (8));
       i += ((0) > (8) ? -1 : 1)) {
    cin >> s;
    for (__typeof(s.size()) j = (0) - ((0) > (s.size()));
         j != (s.size()) - ((0) > (s.size()));
         j += ((0) > (s.size()) ? -1 : 1)) {
      if (s[j] == 'B')
        p[0][j].push_back(i);
      else if (s[j] == 'W')
        p[1][j].push_back(i);
    }
  }
  size_t mnA = INT_MAX, mnB = INT_MAX;
  for (__typeof(8) i = (0) - ((0) > (8)); i != (8) - ((0) > (8));
       i += ((0) > (8) ? -1 : 1)) {
    if (!p[1][i].empty() && (p[0][i].empty() || p[0][i][0] > p[1][i][0])) {
      mnA = min(mnA, p[1][i][0]);
    }
    if (!p[0][i].empty() &&
        (p[1][i].empty() || p[1][i].back() < p[0][i].back())) {
      mnB = min(mnB, 7 - p[0][i].back());
    }
  }
  cout << (mnA <= mnB ? "A" : "B");
  return 0;
}
