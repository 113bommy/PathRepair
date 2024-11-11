#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int mod = 1e9 + 7;
string to_string(string& s) { return '"' + s + '"'; }
string to_string(bool& b) { return b ? "true" : "false"; }
string to_string(const char* s) {
  string t;
  return to_string(t = s);
}
template <class A, class B>
string to_string(pair<A, B>& p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <class A>
string to_string(A& v) {
  string s;
  for (auto& x : v) s += (s.empty() ? "" : ", ") + to_string(x);
  return "{" + s + "}";
}
template <class... Ts>
void _debug(Ts&... args) {
  (..., (cerr << " " << to_string(args)));
  cerr << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    if (n <= 5) {
      cout << 15 << '\n';
      continue;
    }
    if (n % 2 != 0) n++;
    cout << n * 5 / 2 << '\n';
  }
}
