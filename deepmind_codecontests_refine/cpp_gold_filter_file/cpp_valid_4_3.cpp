#include <bits/stdc++.h>
using namespace std;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
void helper() {
  int p;
  cin >> p;
  p--;
  cout << 2 << ' ' << p << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while (t--) helper();
  return 0;
}
