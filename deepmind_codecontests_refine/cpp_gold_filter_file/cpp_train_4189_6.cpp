#include <bits/stdc++.h>
using namespace std;
template <typename T>
void ___print(T x) {
  cout << x;
}
void ___print(char x) { cout << '\'' << x << '\''; }
void ___print(const char *x) { cout << '\"' << x << '\"'; }
void ___print(const string &x) { cout << '\"' << x << '\"'; }
void ___print(bool x) { cout << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cout << '{';
  ___print(x.first);
  cout << ',';
  ___print(x.second);
  cout << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cout << '{';
  for (auto &i : x) cout << (f++ ? "," : ""), ___print(i);
  cout << "}";
}
void _print() { cout << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cout << ", ";
  _print(v...);
}
void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  s += '#';
  vector<int> ans1, ans2;
  vector<int> temp{1};
  int cur = 1;
  stack<int> v;
  v.push(1);
  for (int i = 0; i < (int)(s.size()); i++) {
    if (s[i] != '>') {
      while (!v.empty()) {
        ans1.emplace_back(v.top());
        v.pop();
      }
      v.push(++cur);
    } else {
      v.push(++cur);
    }
  }
  while (!v.empty()) v.pop();
  cur = n;
  v.push(cur);
  for (int i = 0; i < (int)(s.size()); i++) {
    if (s[i] != '<') {
      while (!v.empty()) {
        ans2.emplace_back(v.top());
        v.pop();
      }
      v.push(--cur);
    } else {
      v.push(--cur);
    }
  }
  for (int xx : ans2) cout << xx << ' ';
  cout << "\n";
  for (int xx : ans1) cout << xx << ' ';
  cout << "\n";
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ;
  int tst;
  cin >> tst;
  while (tst--) {
    solve();
  }
}
