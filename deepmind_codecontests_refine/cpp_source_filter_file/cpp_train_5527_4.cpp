#include <bits/stdc++.h>
using namespace std;
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
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
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  int n, m;
  cin >> n >> m;
  vector<long long> data(n + 2);
  data[0] = 0;
  data[n + 1] = m;
  vector<long long> ssump(n + 2);
  vector<long long> ssumn(n + 2);
  bool p = true;
  int i = 1;
  for (; i < n + 2; i++) {
    if (i < n + 1) cin >> data[i];
    if (p) {
      ssump[i] += ssump[i - 1] + data[i] - data[i - 1];
      ssumn[i] = ssumn[i - 1];
    } else {
      ssump[i] = ssump[i - 1];
      ssumn[i] += ssumn[i - 1] + data[i] - data[i - 1];
    }
    p = !p;
  }
  long long sol = ssump[n + 1];
  if (data[1] != 1) {
    sol = max(sol, ssumn[n + 1] + 1ll);
  }
  if (data[n - 2] != m - 1) {
    sol = max(sol, ssump[n] + 1ll);
  }
  for (i = 1; i < n + 1; i++) {
    if (data[i - 1] + 1 < data[i]) {
      sol = max(sol, ssump[i - 1] + 1ll + ssumn[n + 1] - ssumn[i]);
    }
    if (data[i + 1] - 1 > data[i]) {
      sol = max(sol, ssump[i] + data[i + 1] - data[i] - 1ll + ssumn[n + 1] -
                         ssumn[i + 1]);
    }
  }
  cout << sol;
  42;
  42;
  42;
  return 0;
}
