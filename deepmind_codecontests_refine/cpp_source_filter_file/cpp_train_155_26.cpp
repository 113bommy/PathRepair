#include <bits/stdc++.h>
using std::abs;
using std::array;
using std::cerr;
using std::cin;
using std::cout;
using std::make_pair;
using std::map;
using std::max;
using std::min;
using std::pair;
using std::set;
using std::string;
using std::vector;
template <typename T>
T input() {
  T res;
  cin >> res;
  return res;
}
int main() {
  std::iostream::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  uint32_t n, k, a, b, c, d;
  cin >> n >> k >> a >> b >> c >> d;
  if (k == n - 1)
    cout << "-1\n";
  else {
    vector<uint32_t> list;
    for (uint32_t i = 1; i <= n; ++i)
      if (i != a and i != b and i != c and i != d) list.push_back(i);
    assert(list.size() == n - 4);
    cout << a << " " << c << " ";
    for (auto v : list) cout << v << " ";
    cout << d << " " << b << "\n";
    cout << c << " " << a << " ";
    for (auto v : list) cout << v << " ";
    cout << b << " " << d << "\n";
  }
  return 0;
}
