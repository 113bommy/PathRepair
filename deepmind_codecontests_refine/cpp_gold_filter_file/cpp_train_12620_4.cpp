#include <bits/stdc++.h>
using namespace std;
template <typename A>
using VE = vector<A>;
template <typename A>
using USET = unordered_set<A>;
template <typename A>
using HEAP = priority_queue<A>;
template <typename A, typename B>
using PA = pair<A, B>;
template <typename A, typename B>
using UMAP = unordered_map<A, B>;
template <typename A>
using RHEAP = priority_queue<A, vector<A>, greater<A> >;
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(const char c) { return to_string((string) "" + c); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) res += ", ";
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) res += static_cast<char>('0' + v[i]);
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) res += ", ";
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
void debug_out() { cout << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cout << " " << to_string(H);
  debug_out(T...);
}
const int N = 100010, M = 1010;
int n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  cin >> n;
  vector<int> a(n);
  for (auto &u : a) cin >> u;
  long long sum = 0;
  vector<int> res;
  for (int i = 0; i < n; i++) {
    vector<int> t(n);
    t[i] = a[i];
    for (int j = i - 1; j >= 0; j--) t[j] = min(a[j], t[j + 1]);
    for (int j = i + 1; j < n; j++) t[j] = min(a[j], t[j - 1]);
    long long tsum = accumulate(t.begin(), t.end(), 0LL);
    if (tsum > sum) {
      sum = tsum;
      res = t;
    }
  }
  for (auto &u : res) cout << u << ' ';
  cout << '\n';
  return 0;
}
