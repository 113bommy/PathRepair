#include <bits/stdc++.h>
using namespace std;
int middle(int a, int b, int c) {
  if ((a <= b && b <= c) || (c <= b && b <= a))
    return b;
  else if ((b <= a && a <= c) || (c <= a && a <= b))
    return a;
  else
    return c;
}
template <typename KeyType, typename ValueType>
std::pair<KeyType, ValueType> get_max(const std::map<KeyType, ValueType> &x) {
  using pairtype = std::pair<KeyType, ValueType>;
  return *std::max_element(x.begin(), x.end(),
                           [](const pairtype &p1, const pairtype &p2) {
                             return p1.second < p2.second;
                           });
}
static inline bool isvowel(char ch) {
  static const std::string vowels("aeiouEAIOU");
  return vowels.end() != std::find(vowels.begin(), vowels.end(), ch);
}
template <typename Map>
bool map_compare(Map const &lhs, Map const &rhs) {
  return lhs.size() == rhs.size() &&
         std::equal(lhs.begin(), lhs.end(), rhs.begin());
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, g, b, a;
    cin >> n >> g >> b;
    if (g >= n) {
      cout << n << endl;
      continue;
    }
    if (n % 2 == 0) {
      a = n / 2;
    } else
      a = n / 2 + 1;
    long long x = a / g, y = a % g;
    long long ans = x * g + (x - 1) * b;
    if (y >= 1) ans += y + b;
    if (ans >= n)
      cout << ans << endl;
    else
      cout << ans + (n - ans) << endl;
  }
  return 0;
}
