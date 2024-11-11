#include <bits/stdc++.h>
template <typename C>
int sz(const C &c) {
  return c.size();
}
using namespace std;
int main() {
  iostream::sync_with_stdio(false);
  string s;
  cin >> s;
  int n1 = count(begin(s), end(s), '-');
  int n2 = count(begin(s), end(s), 'o');
  cout << (n2 == 0 || n1 % n2 == 0 ? "YES\n" : "NO\n");
}
