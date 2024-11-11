#include <bits/stdc++.h>
template <typename T>
void pMin(T& a, T b) {
  if (b < a) {
    a = b;
  }
}
template <typename T>
void pMax(T& a, T b) {
  if (b > a) {
    a = b;
  }
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& c);
template <typename A, typename B>
std::ostream& operator<<(std::ostream& os, const std::pair<A, B>& c) {
  std::cout << "(" << c.first << ", " << c.second << ")";
  return os;
}
template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& c) {
  if (c.size() == 0) {
    os << "{}";
    return os;
  }
  os << "{" << c[0];
  for (int64_t i = 1; i < (int64_t)c.size(); i++) {
    os << ", " << c[i];
  }
  os << "}";
  return os;
}
using namespace std;
int main() {
  if (0) {
    freopen("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0);
    cin.tie(0);
  }
  int64_t t;
  cin >> t;
  while (t--) {
    int64_t n;
    cin >> n;
    int64_t curr = 0;
    while (n > 0) {
      int64_t currmax = 1;
      curr++;
      int64_t i;
      bool flag = false;
      for (i = 1; (1ll << (i + 1ll)) - 1ll <= n; i++) {
        flag = true;
        currmax = (1ll << (i + 1ll)) - 1ll;
        curr += (1ll << (i + 1ll)) - 1ll;
      }
      for (int64_t j = 1; j < 32; j++) {
        if (1 << j == n) {
          curr += j + 1;
          break;
        }
      }
      n -= (1ll << (i));
      if (n > 0) {
        curr += (i + 1ll);
      }
    }
    cout << curr << endl;
  }
  return 0;
}
