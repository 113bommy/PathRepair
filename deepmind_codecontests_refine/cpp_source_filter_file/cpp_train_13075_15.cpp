#include <bits/stdc++.h>
using namespace std;
const long long int mod = (long long int)(1e9) + 7LL;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, ans = 1000, mx, in;
  cin >> n >> m;
  string s, t, ss, tt;
  cin >> s >> t;
  for (int i = 0; i < m - n + 2; i++) {
    ss = t.substr(i, n);
    mx = 0;
    for (int j = 0; j < n; j++) {
      if (ss[j] != s[j]) mx++;
    }
    if (ans > mx) {
      ans = mx;
      in = i;
    }
  }
  cout << ans << "\n";
  ss = t.substr(in, n);
  for (int j = 0; j < n; j++) {
    if (ss[j] != s[j]) cout << j + 1 << " ";
  }
  return 0;
}
