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
  string sep;
  for (const T &x : v) os << sep << x, sep = " ";
  return os;
}
const int mxN = 1e5 + 1, oo = 1e9;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int a[3] = {};
    for (int i = 0; i < 3; ++i) a[i] = count(begin(s), end(s), 'A' + i);
    int n = s.size();
    cout << ((n % 2 == 0 and a[0] + a[2] <= a[1]) ? "Yes\n" : "No\n");
  }
}
