#include <bits/stdc++.h>
using namespace std;
vector<long long> A;
template <class Iter, class T>
bool not_in(Iter beg, Iter end, T const& val) {
  return std::none_of(beg, end, [val](T const& t) { return t == val; });
}
int main() {
  int t, k;
  long long n, s;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> n >> s >> k;
    for (int q = 0; q < k; ++q) A.clear();
    long long a;
    bool test = false;
    for (int j = 0; j < k; ++j) {
      cin >> a;
      if (a == s) test = true;
      A.push_back(a);
    }
    if (!test)
      cout << 0 << '\n';
    else {
      long long w = 1e16, z = 1e16;
      for (long long x = s; x <= n; ++x) {
        if (not_in(begin(A), end(A), x)) {
          w = abs(s - x);
          break;
        }
      }
      for (long long x = s - 1; x > 0; --x) {
        if (not_in(begin(A), end(A), x)) {
          z = abs(s - x);
          break;
        }
      }
      cout << min(w, z) << '\n';
    }
  }
}
