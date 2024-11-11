#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(char ch) {
  string s;
  s += ch;
  return s;
}
string to_string(const char* s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
pair<long double, long double> find_next(long double x, long double y,
                                         long double vx, long double vy,
                                         long double d) {
  long double root = sqrt(vx * vx + vy * vy);
  long double X = x + (vx / root) * d, Y = y + (vy / root) * d;
  return {X, Y};
}
void solve() {
  long double x, y, vx, vy, a, b, c, d;
  cin >> x >> y >> vx >> vy >> a >> b >> c >> d;
  vector<pair<long double, long double> > v;
  v.push_back(find_next(x, y, vx, vy, b));
  v.push_back(find_next(x, y, -vy, vx, a / 2.0));
  v.push_back(find_next(x, y, -vy, vx, c / 2.0));
  auto it = v.back();
  v.push_back(find_next(it.first, it.second, -vx, -vy, d));
  it = v.back();
  v.push_back(find_next(it.first, it.second, vy, -vx, c));
  v.push_back(find_next(x, y, vy, -vx, c / 2.0));
  v.push_back(find_next(x, y, vy, -vx, a / 2.0));
  cout << fixed << setprecision(18);
  for (auto it : v) {
    cout << it.first << " " << it.second << "\n";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  for (int tc = 1; tc <= t; tc++) {
    solve();
  }
}
