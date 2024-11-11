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
  int n = nxt(), m = nxt();
  vector<int> a(n);
  generate(a.begin(), a.end(), nxt);
  while (m--) {
    int l = nxt() - 1, r = nxt(), x = nxt();
    int cnt = 0;
    for (int i = int(l); i < int(r); ++i) {
      cnt += a[i] < a[x];
    }
    cout << (x == l + cnt ? "Yes" : "NO") << '\n';
  }
  return 0;
}
