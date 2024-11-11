#include <bits/stdc++.h>
using namespace std;
struct less_key {
  bool operator()(const pair<double, int32_t>& p1,
                  const pair<double, int32_t>& p2) {
    return p1.first < p2.first ||
           (p1.first == p2.first && p1.second > p2.second);
  }
};
struct pair_hash {
  std::size_t operator()(const pair<int32_t, int32_t>& k) const {
    return static_cast<size_t>(k.first ^ k.second);
  }
};
int64_t x, y, xo, yo;
string s;
bool a[501][501];
int32_t r[100005];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> x >> y;
  cin >> xo >> yo;
  cin >> s;
  a[xo][yo] = 1;
  r[0] = 1;
  for (int32_t i = 0; i < s.size(); i++) {
    switch (s[i]) {
      case 'L':
        if (yo > 1) {
          yo--;
        }
        break;
      case 'R':
        if (yo < y) {
          yo++;
        }
        break;
      case 'U':
        if (xo > 1) {
          xo--;
        }
        break;
      case 'D':
        if (xo < x) {
          xo++;
        }
        break;
      default:
        break;
    }
    if (!a[xo][yo]) {
      r[i + 1] = 1;
    }
    a[xo][yo] = 1;
  }
  int32_t S = 0;
  for (int32_t i = 0; i < s.size(); i++) {
    S += r[i];
  }
  r[s.size()] = x * y - S;
  for (int32_t i = 0; i <= s.size(); i++) {
    cout << r[i] << " ";
  }
  return 0;
}
