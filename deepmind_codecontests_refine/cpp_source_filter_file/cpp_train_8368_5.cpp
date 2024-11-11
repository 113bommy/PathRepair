#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, j, k, n, m, ans = 0, o, x, y, ref[105], md = 1000000007, vl;
  string s;
  cin >> s;
  n = s.length();
  ans = 1;
  for (i = 0; i < n - 1; i++) {
    ans = (ans * 2) % md;
  }
  x = 0;
  for (i = 0; i < n; i++) {
    if (s[i] == '0') {
      x = (x * x) % md;
    } else {
      x = (x * 2) % md;
      x = (x + 1) % md;
    }
  }
  ans = (ans * x) % md;
  cout << ans;
  return 0;
}
