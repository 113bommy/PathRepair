#include <bits/stdc++.h>
using namespace std;
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr> &operator<<(basic_ostream<Ch, Tr> &os,
                                  Container const &x) {
  os << "{ ";
  for (auto &y : x) os << y << " ";
  return os << "}";
}
template <class X, class Y>
ostream &operator<<(ostream &os, pair<X, Y> const &p) {
  return os << "[ " << p.first << ", " << p.second << " ]";
}
template <class Ch, class Tr, class Tuple, int N>
struct Tp {
  static void print(basic_ostream<Ch, Tr> &os, Tuple const &t) {
    Tp<Ch, Tr, Tuple, N - 1>::print(os, t);
    os << std::get<N - 1>(t) << " ";
  }
};
template <class Ch, class Tr, class Tuple>
struct Tp<Ch, Tr, Tuple, 0> {
  static void print(basic_ostream<Ch, Tr> &os, Tuple const &t) {}
};
template <class Ch, class Tr, class... Args>
basic_ostream<Ch, Tr> &operator<<(basic_ostream<Ch, Tr> &os,
                                  tuple<Args...> const &t) {
  os << "[ ";
  Tp<Ch, Tr, tuple<Args...>, sizeof...(Args)>::print(os, t);
  return os << "]";
}
int const N = 1e5 + 10;
set<int> d;
int a[N];
int n;
long long solve(int m) {
  vector<vector<int>> seg;
  for (int i = 0; i < n; i++) {
    if (!a[i]) continue;
    if (seg.empty() || seg.back().size() == m) {
      seg.emplace_back(1, i);
    } else {
      seg.back().emplace_back(i);
    }
  }
  if (0) cout << seg << '\n';
  for (auto &v : seg) {
    if (v.size() != m) {
      return INT_MAX;
    }
  }
  long long c = 0;
  for (auto &v : seg) {
    int med = v.size() / 2;
    for (auto &i : v) {
      c += abs(v[med] - i);
    }
  }
  return c;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  long long sum = accumulate(a, a + n, 0LL);
  for (long long i = 1; i * i <= sum; i++) {
    if (sum % i == 0) {
      d.emplace(i);
      if (n / i != i) d.emplace(sum / i);
    }
  }
  long long mn = INT_MAX;
  for (auto &i : d) {
    if (i == 1) continue;
    mn = min(mn, solve(i));
    if (0) cout << i << ' ' << mn << ' ';
  }
  cout << (mn == INT_MAX ? -1 : mn);
  return 0;
}
