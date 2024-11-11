#include <bits/stdc++.h>
using namespace std;
template <typename X>
inline X sqr(const X& a) {
  return a * a;
}
int nxt() {
  int x;
  cin >> x;
  return x;
}
int main() {
  int n = nxt(), s = nxt();
  vector<int> a(n);
  for (int i = 0; i < int(n); ++i) {
    int h = nxt(), m = nxt();
    a[i] = h * 60 + m;
  }
  if (a[0] > s) {
    cout << 0 << ' ' << 0 << '\n';
    return 0;
  }
  for (int i = 0; i < int(n - 1); ++i) {
    if (a[i + 1] - a[i] > 2 * s) {
      int ans = a[i] + s + 1;
      cout << ans / 60 << ' ' << ans % 60 << '\n';
      return 0;
    }
  }
  cout << (a[n - 1] + s + 1) / 60 << ' ' << (a[n - 1] + s + 1) % 60 << '\n';
  return 0;
}
