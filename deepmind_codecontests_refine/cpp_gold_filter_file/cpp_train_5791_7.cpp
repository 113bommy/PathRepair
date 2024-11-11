#include <bits/stdc++.h>
using namespace std;
string to_string(bool b) { return (b ? "true" : "false"); }
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
  for (const auto &x : v) {
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
const int mod = 1000000007;
void solve() {
  int n;
  cin >> n;
  map<string, int> m;
  vector<string> v(n);
  for (int i = 0; i < (n); ++i) cin >> v[i];
  for (int i = 0; i < (n); ++i) {
    for (int j = 1; j <= 8; j++) {
      for (int k = 0; k + j <= 9; k++) {
        m[v[i].substr(k, j)]++;
      }
    }
  }
  vector<string> ans(n);
  for (int i = 0; i < (n); ++i) {
    map<string, int> mm;
    for (int j = 1; j <= 8; j++) {
      for (int k = 0; k + j <= 9; k++) {
        mm[v[i].substr(k, j)]++;
      }
    }
    string anss = v[i];
    int len = 9;
    for (auto it = mm.begin(); it != mm.end(); it++) {
      if (m[it->first] == it->second) {
        if ((int)(it->first).size() < len) {
          len = (int)(it->first).size();
          anss = it->first;
        }
      }
    }
    ans[i] = anss;
  }
  for (int i = 0; i < (n); ++i) cout << ans[i] << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt = 1;
  while (tt--) solve();
}
