#include <bits/stdc++.h>
int main() {
  int N;
  std::cin >> N;
  std::vector<int> p(N, 0);
  std::vector<int> s(N, 0);
  std::vector<int> pr(N, 0);
  std::vector<int> sr(N, 0);
  for (int i = 0; i < N; ++i) {
    int t;
    std::cin >> t;
    --t;
    p[i] = t;
    pr[t] = i;
  }
  for (int i = 0; i < N; ++i) {
    int t;
    std::cin >> t;
    --t;
    s[i] = t;
    sr[t] = i;
  }
  std::vector<std::pair<int, int> > res;
  int cost = 0;
  for (int el = N - 1; el >= 0; --el) {
    int k = -1;
    for (int i = 0; i < N; ++i) {
      if (p[i] == s[el]) {
        k = i;
        break;
      }
    }
    while (p[el] != s[el]) {
      for (int j = k + 1; j < N; ++j) {
        if (sr[p[j]] <= k) {
          std::swap(p[j], p[k]);
          res.push_back(std::make_pair(j, k));
          cost += (j - k);
          k = j;
          break;
        }
      }
    }
  }
  std::cout << cost << "\n";
  std::cout << res.size() << "\n";
  for (const auto x : res) {
    std::cout << x.first + 1 << " " << x.second + 1 << "\n";
  }
  return 0;
}
