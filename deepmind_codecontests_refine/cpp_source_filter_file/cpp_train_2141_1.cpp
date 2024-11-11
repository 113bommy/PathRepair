#include <bits/stdc++.h>
using namespace std;
const int N = 212345, LG = 21, mod = 1000000007;
const long double eps = 1e-9, pi = acos(-1.0);
string ans, s;
int n, m;
vector<int> vec, now;
bool poss(char c) {
  vec = {};
  for (int i = 0; i < n; ++i) {
    if (s[i] <= c) {
      vec.push_back(i);
    }
  }
  for (int i = 0; i < n - m + 2; ++i) {
    auto f = lower_bound(vec.begin(), vec.end(), i),
         ss = lower_bound(vec.begin(), vec.end(), i + m);
    if (ss == f) return false;
  }
  vec = {};
  for (int i = 0; i < n; ++i)
    if (s[i] < c) vec.push_back(i);
  now = {};
  for (int i = 0; i <= vec.size(); ++i) {
    int l, r;
    if (i == 0) {
      if (vec.empty()) {
        l = -1, r = n;
      } else
        l = -1, r = vec[0];
    } else if (i == vec.size()) {
      l = vec.back(), r = n;
    } else {
      l = vec[i - 1], r = vec[i];
    }
    while (l + m < r) {
      int p = l + m;
      while (p > l) {
        if (s[p] == c) {
          now.push_back(p);
          break;
        }
        --p;
      }
      l = p;
    }
  }
  for (int p : vec) ans += s[p];
  for (int p : now) ans += s[p];
  sort(ans.begin(), ans.end());
  return true;
}
int main() {
  scanf("%d", &m);
  cin >> s;
  n = s.size();
  for (char ch = 'a'; ch <= 'z'; ++ch) {
    if (poss(ch)) {
      cout << ans << "\n";
      return 0;
    }
  }
  return 0;
}
