#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int)s.length();
  int z = 0, cur = 0;
  for (auto& c : s) {
    if (c == '1') {
      cur++;
    } else {
      cur--;
    }
    z = max(z, cur);
  }
  auto f = [&](const int& m) {
    vector<int> v;
    v.push_back(0);
    string t = s;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        v.push_back(v.back() + 1);
      } else {
        if (s[i] == '?') {
          t[i] = '0';
        }
        v.push_back(v.back() - 1);
      }
    }
    for (int i = n - 3; i >= 0; i--) {
      v[i] = max(v[i], v[i + 1]);
    }
    int add = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '?') {
        if (v[i + 1] + add + 2 <= m) {
          add += 2;
          t[i] = '1';
        }
      }
    }
    v.clear();
    v.push_back(0);
    for (auto& c : t) {
      if (c == '1') {
        v.push_back(v.back() + 1);
      } else {
        v.push_back(v.back() - 1);
      }
    }
    return *min_element(v.begin(), v.end());
  };
  cout << min(z - f(z), (z + 1) - f(z + 1)) << '\n';
  return 0;
}
