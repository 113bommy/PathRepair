#include <bits/stdc++.h>
template <typename T>
T GCD(T a, T b) {
  return a ? GCD(b % a, a) : b;
}
template <typename T>
T LCM(T a, T b) {
  return (a * b) / GCD(a, b);
}
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
  for (auto ob : v) os << ob << " ";
  return os;
}
template <typename T, typename S>
std::ostream &operator<<(std::ostream &os, const std::map<T, S> &v) {
  for (auto ob : v) os << ob.first << " : " << ob.second << std::endl;
  return os;
}
using ld = double;
using ll = long long int;
using ul = unsigned long long int;
using namespace std;
class DSalaryChanging {
  bool Possible(vector<pair<int, int>> money, ll s, int mid, int n) {
    ll sum = 0;
    int cnt = 0;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      if (money[i].second < mid) {
        sum += money[i].first;
      } else if (money[i].first >= mid) {
        cnt++;
        sum += money[i].first;
      } else {
        v.push_back(money[i].first);
      }
    }
    sort(v.begin(), v.end());
    int need = max(0, ((n + 1) / 2) - cnt);
    if (need > v.size())
      return false;
    else {
      for (int i = v.size() - 1; i >= 0; --i) {
        if (need) {
          need--;
          sum += mid;
        } else
          sum += v[i];
      }
      return sum <= s;
    }
  }

 public:
  void solve(std::istream &in, std::ostream &out) {
    ll n, s;
    in >> n >> s;
    vector<pair<int, int>> money;
    for (int i = 0; i < n; ++i) {
      int l, r;
      in >> l >> r;
      money.push_back(make_pair(l, r));
    }
    sort(money.begin(), money.end());
    int low = 1, high = 1e9 + 10, ans = 0;
    while (low + 1 < high) {
      int mid = (low + high) / 2;
      bool isPossible = Possible(money, s, mid, n);
      if (isPossible) {
        ans = mid;
        low = mid;
      } else {
        high = mid;
      }
    }
    out << ans << endl;
  }
};
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(nullptr);
  DSalaryChanging solver;
  std::istream &in(std::cin);
  std::ostream &out(std::cout);
  int n;
  in >> n;
  for (int i = 0; i < n; ++i) {
    solver.solve(in, out);
  }
  return 0;
}
