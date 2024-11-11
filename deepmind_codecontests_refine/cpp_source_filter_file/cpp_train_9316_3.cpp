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
pair<T, U>& operator--(pair<T, U>& p) {
  --p.first;
  --p.second;
  return p;
}
template <typename T, typename U>
pair<T, U>& operator++(pair<T, U>& p) {
  ++p.first;
  ++p.second;
  return p;
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
struct line {
  long long a, b, c;
  int i;
};
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rnd(long long l, long long r) {
  return (long long)(rng() % (r - l + 1)) + l;
}
long long rnd(long long r) { return rng() % r; }
long long rnd() { return rng(); }
long double rndf() { return (long double)rng() / (long double)ULLONG_MAX; }
long double rndf(long double l, long double r) { return rndf() * (r - l) + l; }
using i128 = __int128;
pair<pair<i128, i128>, pair<i128, i128>> inter(line l1, line l2) {
  pair<i128, i128> x = {l2.c * l1.b - l1.c * l2.b, l1.a * l2.b - l2.a * l1.b};
  pair<i128, i128> y = {l2.c * l1.a - l1.c * l2.a, l1.b * l2.a - l2.b * l1.a};
  return {x, y};
};
array<vector<line>, 10> preall;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<pair<int, int>> ans;
  int n, k;
  cin >> n >> k;
  vector<line> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].a >> v[i].b >> v[i].c;
    v[i].i = i + 1;
  }
  function<void(const vector<line>&, int)> calc = [&](const vector<line>& v,
                                                      int k) {
    if (v.size() <= k) {
      for (int i = 0; i < v.size(); ++i) {
        ans.emplace_back(v[i].i, -1);
      }
      cout << "YES\n";
      cout << ans.size() << '\n';
      for (auto p : ans) {
        cout << p << '\n';
      }
      exit(0);
    }
    if (k == 0) return;
    vector<line>& nx = preall[k];
    for (int it = 0; it < 5; ++it) {
      int i = rnd(v.size());
      int j = rnd(v.size());
      if (v[i].a * v[j].b == v[j].a * v[i].b) continue;
      auto [x, y] = inter(v[i], v[j]);
      nx.clear();
      for (auto& l : v) {
        if (l.a * x.first * y.second + l.b * y.first * x.second +
                l.c * x.second * y.second ==
            0)
          continue;
        nx.push_back(l);
        if ((v.size() - nx.size()) * k < v.size()) break;
      }
      if ((v.size() - nx.size()) * k < v.size()) continue;
      ans.emplace_back(v[i].i, v[j].i);
      calc(nx, k - 1);
      ans.pop_back();
    }
  };
  calc(v, k);
  cout << "NO\n";
  return 0;
}
