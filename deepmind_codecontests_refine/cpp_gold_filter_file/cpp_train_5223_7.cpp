#include <bits/stdc++.h>
using namespace std;
template <typename T>
vector<T>& operator--(vector<T>& v) {
  for (auto& i : v) --i;
  return v;
}
template <typename T>
vector<T>& operator++(vector<T>& v) {
  for (auto& i : v) ++i;
  return v;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& i : v) is >> i;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T>& v) {
  for (auto& i : v) os << i << ' ';
  return os;
}
template <typename T, typename U>
istream& operator>>(istream& is, pair<T, U>& p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, pair<T, U>& p) {
  os << p.first << ' ' << p.second;
  return os;
}
template <typename T, typename U>
pair<T, U> operator-(pair<T, U> a, pair<T, U> b) {
  return make_pair(a.first - b.first, a.second - b.second);
}
template <typename T, typename U>
pair<T, U> operator+(pair<T, U> a, pair<T, U> b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
template <typename T, typename U>
void umin(T& a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
void umax(T& a, U b) {
  if (a < b) a = b;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long a, b, p, q;
    cin >> a >> b >> p >> q;
    long long t = min(b - a + 1, (long long)sqrt(b - a) + 5);
    vector<pair<long long, int>> v;
    auto g = [&](long long x) { return p * x * 2 % (q * 2); };
    auto f = [&](long long x) { return abs(g(x) - q); };
    42;
    ;
    for (int i = 0; i < t; ++i) {
      v.emplace_back(g(i), i);
    }
    long long ans = a;
    sort(v.begin(), v.end());
    42;
    ;
    for (long long i = a; i + t <= b + 1; i += t) {
      long long need = (q - g(i) + q * 2) % (q * 2);
      int ind = (lower_bound((v).begin(), (v).end(), (make_pair(need, -1))) -
                 (v).begin());
      for (int j = ind - 3; j <= ind + 3; ++j) {
        int k = (j + v.size()) % v.size();
        long long fn = f(i + v[k].second);
        if (fn < f(ans) || (fn == f(ans) && i + v[k].second < ans))
          ans = i + v[k].second;
      }
      ind = (upper_bound((v).begin(), (v).end(), (make_pair(need, -1))) -
             (v).begin());
      for (int j = ind - 3; j <= ind + 3; ++j) {
        int k = (j + v.size()) % v.size();
        long long fn = f(i + v[k].second);
        if (fn < f(ans) || (fn == f(ans) && i + v[k].second < ans))
          ans = i + v[k].second;
      }
    }
    for (long long i = b; i >= max(b - t - 5, a); --i) {
      long long fn = f(i);
      if (fn < f(ans) || (fn == f(ans) && i < ans)) ans = i;
    }
    cout << ans << '\n';
  }
  return 0;
}
