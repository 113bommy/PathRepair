#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << "\n";
  err(++it, args...);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int n, a, b, c, t, k;
  cin >> n >> a >> b >> c >> t;
  int r = 0;
  while (n-- && cin >> k) r += c > b ? (t - k) * (c - b) : a;
  cout << r;
}
