#include <bits/stdc++.h>
using namespace std;
int a[256];
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ;
  string s;
  cin >> s;
  int n = s.size();
  for (int i = 0; i < n; i++) a[s[i]]++;
  long long ans = 0;
  for (int i = 0; i <= 127; i++) {
    ans += a[i] * a[i];
  }
  cout << ans;
  return 0;
}
