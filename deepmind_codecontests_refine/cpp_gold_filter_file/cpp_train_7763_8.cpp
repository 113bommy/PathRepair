#include <bits/stdc++.h>
using namespace std;
int f(int x) {
  int res = 0;
  while (res * (res + 1) / 2 <= x) ++res;
  return res - 1;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int xs = 0, n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    xs ^= f(x);
  }
  cout << (xs ? "NO" : "YES");
}
