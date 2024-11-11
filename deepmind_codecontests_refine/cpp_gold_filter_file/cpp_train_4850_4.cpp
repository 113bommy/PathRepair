#include <bits/stdc++.h>
namespace std {
size_t hash_combine(size_t lhs, size_t rhs) {
  lhs ^= rhs + 0x9e3779b9 + (lhs << 6) + (lhs >> 2);
  return lhs;
}
template <typename T1, typename T2>
struct hash<std::pair<T1, T2>> {
  std::size_t operator()(std::pair<T1, T2> const &p) const {
    return hash_combine(std::hash<T1>()(p.first), std::hash<T2>()(p.second));
  }
};
}  // namespace std
using namespace std;
char str[200000];
vector<int> vec;
int n, k;
bool check(int t, int k) {
  int used = 0;
  int curr_row = 0;
  int prev_good = -1;
  for (int i = (1); i < (n - 1); i++) {
    if (str[i] == '0') prev_good = i;
    curr_row += 1;
    if (curr_row > t && prev_good >= 0) {
      curr_row = i - prev_good;
      prev_good = -1;
      used++;
    }
    if (curr_row > t) return false;
  }
  return used <= k;
}
int main() {
  scanf("%d %d", &n, &k);
  scanf("%s", str);
  k -= 2;
  int left = 0, right = n;
  int ans = n;
  while (left <= right) {
    int m = (left + right) / 2;
    if (check(m, k)) {
      ans = min(m, ans);
      right = m - 1;
    } else {
      left = m + 1;
    }
  }
  printf("%d", ans);
  return 0;
}
