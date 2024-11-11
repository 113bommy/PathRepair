#include <bits/stdc++.h>
bool a[100001];
class op {
 public:
  int first, delta;
  inline op(int first, int delta) : first(first), delta(delta) {
    a[first] ^= 1, a[first + delta] ^= 1, a[first + (delta << 1)] ^= 1;
  }
};
std::vector<op> ans;
int main() {
  std::ios_base::sync_with_stdio(0), std::cin.tie(0);
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  for (int i = 1; i + 2 <= n; ++i)
    if (a[i])
      ans.emplace_back(i, i + 10 < n ? a[i + 1] ? a[i + 2]   ? 1
                                                  : a[i + 3] ? 3 + a[i + 4]
                                                             : 4 | !a[i + 4]
                                                : 2 | !a[i + 2]
                                     : 1);
  if (a[n - 1])
    if (n >= 8)
      ans.emplace_back(n - 5, 1), ans.emplace_back(n - 7, 2),
          ans.emplace_back(n - 7, 3);
    else
      do {
        std::cout << "NO\n";
        return 0;
      } while (0);
  if (a[n])
    if (n >= 7)
      ans.emplace_back(n - 4, 1), ans.emplace_back(n - 6, 2),
          ans.emplace_back(n - 6, 3);
    else
      do {
        std::cout << "NO\n";
        return 0;
      } while (0);
  std::cout << "YES\n" << ans.size() << '\n';
  for (const op& i : ans)
    std::cout << i.first << ' ' << i.first + i.delta << ' '
              << i.first + (i.delta << 1) << '\n';
}
