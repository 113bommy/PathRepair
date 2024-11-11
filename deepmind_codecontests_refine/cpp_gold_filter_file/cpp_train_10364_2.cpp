#include <bits/stdc++.h>
using namespace std;
using vi_ = vector<int>;
using vs_ = vector<size_t>;
using vb_ = vector<bool>;
using vd_ = vector<long double>;
using vvi_ = vector<vi_>;
using vvs_ = vector<vs_>;
using vvb_ = vector<vb_>;
using vvd_ = vector<vd_>;
template <typename T_Type>
vector<T_Type> InputVector(int len = -1, istream &input = cin) noexcept {
  if (len == -1) {
    input >> len;
  }
  vector<T_Type> arr;
  arr.reserve(static_cast<size_t>(len));
  {
    T_Type element;
    for (int i = 0; i < len; ++i) {
      input >> element;
      arr.push_back(move(element));
    }
  }
  return arr;
}
template <typename Container_Type>
void OutputContainer(const Container_Type &container, bool show_len = false,
                     bool with_newline = false, ostream &output = cout) {
  if (show_len) {
    output << container.size() << "\n";
  }
  for (const auto &element : container) {
    output << element;
    output << (with_newline ? "\n" : " ");
  }
}
void solve();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
  int test_num = 1;
  while (test_num--) {
    solve();
  }
  return 0;
}
void solve() {
  size_t n, k;
  long double l, v1, v2;
  std::cin >> n >> l >> v1 >> v2 >> k;
  long double left = 0;
  long double right = l / v2;
  size_t additional = 0;
  const long double EPS = 1e-13;
  while (right - left > EPS || additional < 100) {
    if (right - left < EPS) {
      ++additional;
    }
    auto mid = (left + right) / 2.0;
    long double main_pos = 0.0;
    size_t cur = 0;
    bool good = true;
    long double dist = mid * v2;
    while (cur != n) {
      if (l - main_pos < dist) {
        good = false;
        break;
      } else {
        long double bus_pos = main_pos + dist;
        main_pos += mid * v1;
        main_pos += (bus_pos - main_pos) / (v1 + v2) * v1;
        cur = min(cur + k, n);
      }
    }
    if (good) {
      left = mid;
    } else {
      right = mid;
    }
  }
  std::cout << (l - left * v2) / v1 + left << "\n";
}
