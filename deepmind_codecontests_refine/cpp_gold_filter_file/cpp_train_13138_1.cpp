#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e6 + 10;
string s;
int z[maxN];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> s;
  int l, r;
  l = r = 0;
  for (int i = 1; i < s.size(); ++i) {
    if (i > r) {
      l = r = i;
      while (r < s.size() && s[r - l] == s[r]) ++r;
      z[i] = r - l;
      --r;
    } else {
      int k = i - l;
      z[i] = min(z[k], r - i + 1);
      if (z[i] >= r - i + 1) {
        l = i;
        while (r < s.size() && s[r - l] == s[r]) ++r;
        z[i] = r - l;
        --r;
      }
    }
  }
  int ans, mx;
  ans = -1, mx = 0;
  for (int i = 1; i < s.size(); ++i) {
    if (i + z[i] == s.size() && z[i] <= mx) {
      ans = z[i];
      break;
    }
    mx = max(mx, z[i]);
  }
  if (ans != -1)
    for (int i = 0; i < ans; ++i) cout << s[i];
  else
    cout << "Just a legend";
  return 0;
}
