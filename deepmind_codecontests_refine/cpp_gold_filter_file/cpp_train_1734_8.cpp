#include <bits/stdc++.h>
int n, x;
std::vector<int> a;
std::vector<int> solve(std::vector<int> v) {
  std::sort(v.begin(), v.end()),
      v.resize(std::unique(v.begin(), v.end()) - v.begin());
  if (std::binary_search(v.begin(), v.end(), 0))
    v.erase(std::lower_bound(v.begin(), v.end(), 0));
  if (v.size() == 0) return std::vector<int>();
  if (v.size() == 1 && v[0] == 1) return std::vector<int>(1, 1);
  if (v.size() == 1 && v[0] == -1) return std::vector<int>(1, -1);
  int qaq = 0;
  for (auto i : v) qaq |= i;
  int qwq = __builtin_ctz(qaq);
  if (qwq) {
    for (auto &i : v) i >>= qwq;
    std::vector<int> ret = solve(v);
    for (auto &i : ret) i <<= qwq;
    return ret;
  }
  std::vector<int> p = v;
  std::vector<int> L, R;
  for (auto &i : p)
    if (i & 1) ++i;
  L = solve(p), p = v;
  for (auto &i : p)
    if (i & 1) --i;
  R = solve(p);
  if (L.size() > R.size())
    L = R, L.push_back(1);
  else
    L.push_back(-1);
  return L;
}
int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  std::cin >> n;
  for (int i = 0; i < n; ++i) std::cin >> x, a.push_back(x);
  std::vector<int> ret = solve(a);
  std::cout << ret.size() << '\n';
  for (int i : ret) std::cout << i << ' ';
  std::cout << '\n';
  return 0;
}
