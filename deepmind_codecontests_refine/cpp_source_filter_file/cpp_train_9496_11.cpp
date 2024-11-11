#include <bits/stdc++.h>
std::vector<std::string> query(int l, int r) {
  std::cout << "? " << l << " " << r << std::endl;
  std::vector<std::string> ret;
  int w = r - l + 1;
  for (int i = 0; i < w * (w + 1) / 2; ++i) {
    std::string s;
    std::cin >> s;
    std::sort(s.begin(), s.end());
    ret.emplace_back(std::move(s));
  }
  return ret;
}
int main() {
  int n;
  std::cin >> n;
  if (n == 1) {
    auto vec = query(1, 1);
    std::cout << "! " << vec[0] << std::endl;
    return 0;
  }
  if (n == 2) {
    auto vec0 = query(1, 1);
    auto vec1 = query(2, 2);
    std::cout << "! " << vec0[0] << vec1[0] << std::endl;
    return 0;
  }
  int half = n / 2;
  auto q0 = query(1, half);
  auto q1 = query(2, half);
  std::multiset<std::string> set(q0.begin(), q0.end());
  for (const auto& s : q1) set.erase(set.find(s));
  std::vector<std::string> vec(set.begin(), set.end());
  std::sort(vec.begin(), vec.end(),
            [](const std::string& a, const std::string& b) {
              return a.length() < b.length();
            });
  std::string result(n, '$');
  for (int i = 0; i < vec.size(); ++i) {
    for (int j = 0; j < i; ++j)
      vec[i].erase(std::find(vec[i].begin(), vec[i].end(), result[j]));
    result[i] = vec[i][0];
  }
  auto q = query(1, n);
  std::vector<std::vector<std::string>> strings(n + 1);
  for (const auto& s : q) strings[s.length()].emplace_back(s);
  for (int r = n - 1; r >= half; --r) {
    std::vector<int> cnt(26);
    for (const auto& s : strings[r])
      for (char c : s) cnt[c - 'a']++;
    for (int i = 0; i < n; ++i)
      if (result[i] != '$') {
        cnt[result[i] - 'a'] -=
            std::min(i + r - 1, n - 1) - r + 1 - std::max(0, i - r + 1) + 1;
      }
    for (int i = 0; i < 26; ++i)
      if (cnt[i] % (n - r + 1)) {
        result[r] = 'a' + i;
        break;
      }
  }
  std::cout << "! " << result << std::endl;
}
