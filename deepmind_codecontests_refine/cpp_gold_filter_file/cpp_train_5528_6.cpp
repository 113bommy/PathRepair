#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
long long int l[100010], r[100010];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  long long int n = s.size();
  long long int ans = 0;
  l[0] = 1;
  for (long long int i = 1; i < s.size(); ++i)
    if (s[i] == s[i - 1])
      l[i] = 1;
    else
      l[i] = l[i - 1] + 1;
  r[s.size() - 1] = 1;
  for (long long int i = s.size() - 2; i >= 0; --i)
    if (s[i] == s[i + 1])
      r[i] = 1;
    else
      r[i] = r[i + 1] + 1;
  for (long long int i = 0; i < n; ++i) ans = max({ans, l[i], r[i]});
  for (long long int i = 0; i < n - 1; ++i) {
    if (s[0] != s[n - 1])
      ans = max(ans, min(r[0], i + 1) + min(l[n - 1], n - i - 1));
  }
  cout << ans << endl;
}
