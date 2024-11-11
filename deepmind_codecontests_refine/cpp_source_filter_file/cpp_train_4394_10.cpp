#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const long long INF = 1e18;
const int M = 1e9 + 7;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  string s;
  cin >> n >> k >> s;
  s = s + s + s;
  n *= 3;
  if (count((s).begin(), (s).end(), 'B') == n &&
      count((s).begin(), (s).end(), 'W') == n) {
    cout << s << endl;
    return 0;
  }
  std::vector<int> a(n);
  bool ok = 1;
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] == s[i + 1]) {
      a[i] = a[i + 1] = 1;
      ok = 0;
    }
  }
  if (ok) {
    if (k & 1) {
      cout << s.substr(1, n / 3 - 1) + s[0] << endl;
    } else {
      cout << s.substr(0, n / 3) << endl;
    }
    return 0;
  }
  for (int i = 1, nxt = 0; i < n - 1; i = nxt) {
    if (a[i]) {
      nxt = i + 1;
      continue;
    }
    while (nxt < n && a[nxt++] == 0)
      ;
    int len = nxt - i;
    for (int j = 0; j < len; ++j) {
      if (k >= min(j + 1, len - j)) {
        s[i + j] = j > len / 2 ? s[nxt] : s[i - 1];
      } else {
        s[i + j] = (k & 1) ? 'W' + 'B' - s[i + j] : s[i + j];
      }
    }
  }
  cout << s.substr(n / 3, n / 3) << endl;
  return 0;
}
