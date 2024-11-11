#include <bits/stdc++.h>
bool check(const std::vector<long long>& ps, std::vector<int>& ans, int i,
           int num, int val) {
  long long numx = num - ps[i];
  if (numx >= ps[i]) {
    auto it = std::lower_bound(ps.begin() + i, ps.end(), numx);
    while (it != ps.end() && *it == numx && ans[it - ps.begin()] != -1) ++it;
    if (it != ps.end() && *it == numx && ans[it - ps.begin()] == -1) {
      ans[it - ps.begin()] = val;
      ans[i] = val;
      return true;
    }
  }
  return false;
}
int main() {
  int n;
  int a;
  int b;
  std::cin >> n >> a >> b;
  std::vector<long long> p(n, 0);
  for (int i = 0; i < n; ++i) std::cin >> p[i];
  std::vector<int> ans(n, -1);
  std::vector<long long> ps = p;
  std::sort(ps.begin(), ps.end());
  int valA = 0;
  int valB = 1;
  if (a > b) {
    std::swap(a, b);
    std::swap(valA, valB);
  }
  for (int i = 0; i < n; ++i) {
    if (ans[i] != -1) continue;
    if (check(ps, ans, i, b, valB)) continue;
    if (check(ps, ans, i, a, valA)) continue;
    std::cout << "NO";
    return 0;
  }
  std::cout << "YES\n";
  for (int i = 0; i < n; ++i) {
    auto it = std::lower_bound(ps.begin(), ps.end(), p[i]);
    while (it != ps.end() && *it == p[i] && ans[it - ps.begin()] == -2) ++it;
    std::cout << ans[it - ps.begin()] << " ";
    ans[it - ps.begin()] = -2;
  }
  return 0;
}
