#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  solve();
  return 0;
}
void solve() {
  int i, n, k, d = 0;
  string s, o = "";
  cin >> n >> k;
  cin >> s;
  sort(s.begin(), s.end());
  o += s[0];
  d += s[0] - 'a' + 1;
  for (i = 1; i < n; i++) {
    if (o.length() == k) {
      break;
    }
    if (s[i] >= o.back() + 2) {
      o += s[i];
      d += s[i] - 'a' + 1;
    }
  }
  if (o.length() < k) {
    cout << -1;
  } else {
    cout << d;
  }
}
