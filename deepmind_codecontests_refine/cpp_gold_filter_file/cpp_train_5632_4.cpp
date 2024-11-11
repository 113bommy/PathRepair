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
  vector<int> a(m), cnt(110, 0);
  generate(a.begin(), a.end(), nxt);
  for (int i = 0; i < int(m); ++i) {
    cnt[a[i]]++;
  }
  for (int i = m; i > 0; i--) {
    int k = 0;
    for (int j = 0; j < int(int((cnt).size())); ++j) {
      k += cnt[j] / i;
    }
    if (k >= n) {
      cout << i << '\n';
      return 0;
    }
  }
  cout << 0 << '\n';
  return 0;
}
