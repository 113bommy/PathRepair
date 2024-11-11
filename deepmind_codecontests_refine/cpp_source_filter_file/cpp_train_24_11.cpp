#include <bits/stdc++.h>
using namespace std;
template <typename T>
void pr(vector<T> &v) {
  for (int i = 0; i < (int)(v).size(); i++) cout << v[i] << " ";
  cout << endl;
}
template <typename T>
void pr(vector<vector<T>> &v) {
  for (int i = 0; i < (int)(v).size(); i++) {
    pr(v[i]);
  }
}
template <typename T>
void re(T &first) {
  cin >> first;
}
template <typename T>
void re(vector<T> &a) {
  for (int i = 0; i < (int)(a).size(); i++) re(a[i]);
}
template <class Arg, class... Args>
void re(Arg &first, Args &...rest) {
  re(first);
  re(rest...);
}
template <typename T>
void pr(T first) {
  cout << first << endl;
}
template <class Arg, class... Args>
void pr(const Arg &first, const Args &...rest) {
  cout << first << " ";
  pr(rest...);
  cout << endl;
}
void ps() { cout << endl; }
template <class T, class... Ts>
void ps(const T &t, const Ts &...ts) {
  cout << t;
  if (sizeof...(ts)) cout << " ";
  ps(ts...);
}
void solve() {
  int n;
  re(n);
  vector<int> a(n);
  re(a);
  if (a[0] + a[1] <= a[n - 1]) {
    ps(0, 1, n - 1);
  } else {
    pr(-1);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  re(t);
  for (int tt = 0; tt < t; tt++) {
    solve();
  }
}
