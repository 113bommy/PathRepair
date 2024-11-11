#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed;
  cout.precision(12);
  solve();
  return 0;
}
template <typename T>
void sc(T& x) {
  cin >> x;
}
template <typename Head, typename... Tail>
void sc(Head& head, Tail&... tail) {
  cin >> head;
  sc(tail...);
}
template <typename T>
void pr(const T& x) {
  cout << x << '\n';
}
template <typename Head, typename... Tail>
void pr(const Head& head, const Tail&... tail) {
  cout << head << ' ';
  pr(tail...);
}
bool valid_username(string a) {
  bool ok = (1 <= ((int)a.size()) && ((int)a.size()) <= 16);
  for (int i = 0; i < ((int)a.size()); i++) {
    a[i] = tolower(a[i]);
  }
  for (int i = 0; i < ((int)a.size()); i++) {
    ok &= ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= '0' && a[i] <= '9') ||
           (a[i] == '_'));
  }
  return ok;
}
bool valid_hostname(string a) {
  a.push_back('.');
  stringstream ss(a);
  string x;
  bool ok = (1 <= ((int)a.size()) && ((int)a.size()) <= 32);
  while (getline(ss, x, '.')) {
    ok &= valid_username(x);
  }
  return ok;
}
void solve() {
  string a;
  sc(a);
  int n = ((int)a.size());
  string pref, suf;
  bool passed_at = false;
  for (int i = 0; i < n; i++) {
    if (a[i] == '@' && passed_at == false) {
      passed_at = true;
    } else {
      if (passed_at) {
        suf.push_back(a[i]);
      } else {
        pref.push_back(a[i]);
      }
    }
  }
  suf.push_back('/');
  bool ok = true;
  ok &= valid_username(pref);
  stringstream ss(suf);
  vector<string> tokens;
  string x;
  while (getline(ss, x, '/')) {
    tokens.push_back(x);
  }
  ok &= valid_hostname(tokens[0]);
  for (int i = 1; i < ((int)tokens.size()); i++) {
    ok &= valid_username(tokens[i]);
  }
  pr(ok ? "YES" : "NO");
}
