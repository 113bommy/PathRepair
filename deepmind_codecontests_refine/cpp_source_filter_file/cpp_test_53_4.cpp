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
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << " " << H;
  dbg_out(T...);
}
void solve() {
  int n;
  char c;
  string s;
  cin >> n >> c >> s;
  vector<int> ans;
  bool need = false;
  for (int i = 0; i < n; i++) {
    if (s[i] != c) {
      need = true;
    }
  }
  for (int i = n / 2; i < n - 1; i++) {
    if (s[i] == c) {
      ans.push_back(i + 1);
      break;
    }
  }
  if (need == false) {
    cout << "0\n";
    return;
  }
  if ((int)ans.size() == 0) {
    ans.push_back(n);
    ans.push_back(n - 1);
  }
  cout << ans.size() << '\n';
  for (int i : ans) {
    cout << i << ' ';
  }
  cout << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tests = 1;
  cin >> tests;
  while (tests--) {
    solve();
  }
}
