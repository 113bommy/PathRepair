#include <bits/stdc++.h>
using namespace std;
vector<int> z_function(string s) {
  int n = s.size();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r) z[i] = min(z[i - l], r - i + 1);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL), cout.tie(NULL);
  string s1, s2;
  cin >> s1 >> s2;
  vector<int> z1 = z_function(s1);
  int n = z1.size(), p1 = 0;
  for (int i = 1; i < n; ++i) {
    if (i + z1[i] == n && n % i == 0) {
      p1 = i;
      break;
    }
  }
  vector<int> z2 = z_function(s2);
  int m = z2.size(), p2 = 0;
  for (int i = 1; i < m; ++i) {
    if (i + z2[i] == m && m % i == 0) {
      p2 = i;
      break;
    }
  }
  if (s1.substr(0, p1) != s2.substr(0, p2)) {
    cout << 0;
  } else {
    int ans = 0;
    for (int i = p1; i <= n && i <= m; i += p1) {
      if (n % i == 0 && m % i == 0) ans++;
    }
    cout << ans;
  }
  return 0;
}
