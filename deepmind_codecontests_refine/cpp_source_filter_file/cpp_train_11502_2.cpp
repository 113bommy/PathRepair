#include <bits/stdc++.h>
using namespace std;
int count(vector<int> const &p) {
  int ans = 0;
  for (auto it = p.begin(); it != p.end(); ++it) {
    for (auto jt = it; jt != p.end(); ++jt) {
      ans += *max_element(it, jt + 1);
    }
  }
  return ans;
}
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  for (int i = 0; i != n; ++i) {
    p[i] = i + 1;
  }
  vector<vector<int>> g;
  int ans = 0;
  do {
    auto curr = count(p);
    if (curr == ans) {
      g.push_back(p);
    } else if (curr > ans) {
      ans = curr;
      g = vector<vector<int>>(1, p);
    }
  } while (next_permutation(p.begin(), p.end()));
  for (auto &e : g[k - 1]) {
    std::cout << e << ' ';
  }
  return 0;
}
