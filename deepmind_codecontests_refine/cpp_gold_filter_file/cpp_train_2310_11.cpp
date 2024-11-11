#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b & 1) {
      res = res * a;
    }
    a = a * a;
    b = b / 2;
  }
  return res;
}
long long int const N = 2e5 + 1;
void solve() {
  string s;
  cin >> s;
  long long int i, j, l;
  long long int a[26] = {0};
  for (i = 0; i < s.size(); i++) {
    a[s[i] - 'a']++;
    long long int ans = 0;
    for (j = 0; j < s[i] - 'a'; j++) ans += a[j];
    if (ans > 0)
      cout << "Ann" << '\n';
    else
      cout << "Mike" << '\n';
  }
}
int32_t main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
