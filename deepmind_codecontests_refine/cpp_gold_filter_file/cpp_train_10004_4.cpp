#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
int i, n, k, used, opened;
string s, ans;
int main() {
  cin >> n >> k >> s;
  for (i = 0; i < n; ++i) {
    if (s[i] == '(' && used < k / 2) ans += '(', ++used, ++opened;
    if (s[i] == ')' && opened) ans += ')', --opened;
  }
  cout << ans << '\n';
  return 0;
}
