#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  int t;
  cin >> t;
  while (t--) {
    int n, r;
    cin >> n >> r;
    for (int i = 0; i < (int)(n - 1); ++i) {
      int x;
      cin >> x;
      r += x;
    }
    r %= n;
    if (r == 0) r += n;
    cout << r << endl;
  }
  return 0;
}
