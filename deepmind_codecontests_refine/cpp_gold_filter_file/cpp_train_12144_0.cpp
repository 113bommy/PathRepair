#include <bits/stdc++.h>
using namespace std;
using namespace std;
struct KeyHasher {
  std::size_t operator()(const pair<char, int>& k) const {
    return 301 * k.first + k.second;
  }
};
int main() {
  std::cout.unsetf(std::ios::floatfield);
  std::cout.precision(8);
  string s;
  cin >> s;
  auto l = s.size();
  unordered_map<char, int> bst;
  for (int i = 0; i < l; ++i) {
    if (bst.find(s[i]) == bst.end()) {
      bst[s[i]] = 0;
    }
    bst[s[i]] += 1;
  }
  unordered_map<pair<char, int>, vector<int>, KeyHasher> h;
  for (auto i = 0; i < l; ++i) {
    for (auto j = 0; j < l; ++j) {
      char fl = s[i];
      char sl = s[(i + j) % l];
      auto p = make_pair(fl, j);
      if (h.find(p) == h.end()) {
        h[p] = vector<int>(26, 0);
      }
      h[p][sl - 'a'] += 1;
    }
  }
  unordered_map<char, double> st;
  for (auto it = h.begin(); it != h.end(); ++it) {
    auto ch = it->first.first;
    if (st.find(ch) == st.end()) {
      st[ch] = 0.0;
    }
    int sm = 0;
    int ones = 0;
    for (auto jt : it->second) {
      if (jt == 1) {
        ones += 1;
      }
      sm += jt;
    }
    st[ch] = max(st[ch], double(ones) / sm);
  }
  double ans;
  for (auto it : st) {
    ans += it.second * bst[it.first];
  }
  cout << ans / s.size();
}
