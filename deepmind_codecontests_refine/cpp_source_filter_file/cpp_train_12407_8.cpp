#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wshadow"
#pragma GCC diagnostic ignored "-Wsign-compare"
using namespace std;
const int N = 1e5 + 5;
int n, m, k = 0, t = 1, x, y, z, l, r, w, d, q, ct = 0, ans = 0, f = 0;
string s, p;
set<int> si;
map<int, int> mi;
signed main() {
  cin >> n >> s;
  int a[n], b[n];
  for (int i = 1; i <= n; i++) cin >> a[i - 1] >> b[i - 1];
  int ans = count(s.begin(), s.end(), '1');
  for (int i = 1; i < 100000; i++) {
    for (int j = 0; j < n; j++) {
      if (i > b[j])
        if ((i - b[j]) % a[j] == 0) {
          s[j] = '0' + '1' - s[j];
        }
    }
    int curr = count(s.begin(), s.end(), '1');
    ans = max(ans, curr);
  }
  cout << ans;
}
