#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() { cerr << "\n"; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
bool cmp(const pair<long long, string> &a, const pair<long long, string> &b) {
  return a.first < b.first;
}
void solve() {
  long long n;
  cin >> n;
  vector<pair<long long, string>> v;
  for (long long i = 0; i < n; i++) {
    string a, b;
    cin >> a >> b;
    if (b == "rat")
      v.push_back({0, a});
    else if (b == "woman" || b == "child")
      v.push_back({1, a});
    else if (b == "man")
      v.push_back({2, a});
    else
      v.push_back({3, a});
  };
  stable_sort(v.begin(), v.end(), cmp);
  for (auto c : v) cout << c.second << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
}
