#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <class T>
int size(T &&a) {
  return (int)(a.size());
}
ostream &operator<<(ostream &os, string str) {
  for (char c : str) os << c;
  return os;
}
template <class A, class B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << "," << p.second << ')';
}
template <class T>
auto operator<<(ostream &os, T &&x) -> decltype(x.begin(), os) {
  os << '{';
  for (auto it = x.begin(); it != x.end(); ++it)
    os << *it << (it == prev(x.end()) ? "" : " ");
  return os << '}';
}
template <class T>
ostream &operator<<(ostream &os, vector<vector<T>> vec) {
  for (auto x : vec) os << "\n  " << x;
  return os;
}
void dump() {}
template <class T, class... Args>
void dump(T &&x, Args... args) {
  cerr << x << "; ";
  dump(args...);
}
vector<int> ans;
void print_sequence(int st, int en) {
  if (en - st + 1 < 3) return;
  for (int i = st; i <= en - 2; i += 2) ans.emplace_back(i);
  for (int i = en - 4; i >= st; i -= 2) ans.emplace_back(i);
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n), pref_xor(n);
  for (int i = 0; i < (n); ++i) {
    cin >> a[i];
    if (i == 0)
      pref_xor[i] = a[i];
    else
      pref_xor[i] = pref_xor[i - 1] ^ a[i];
  }
  if (pref_xor[n - 1] == 1) {
    cout << "NO\n";
    return;
  }
  ans.clear();
  if (n % 2 == 1) {
    cout << "YES\n";
    print_sequence(0, n - 1);
    cout << size(ans) << '\n';
    for (int x : ans) cout << x + 1 << ' ';
    cout << '\n';
    return;
  }
  for (int i = 0; i < n; i += 2) {
    if (pref_xor[i] == 0) {
      cout << "YES\n";
      print_sequence(0, i);
      print_sequence(i + 1, n - 1);
      cout << size(ans) << '\n';
      for (int x : ans) cout << x + 1 << ' ';
      cout << '\n';
      return;
    }
  }
  cout << "NO\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
}
