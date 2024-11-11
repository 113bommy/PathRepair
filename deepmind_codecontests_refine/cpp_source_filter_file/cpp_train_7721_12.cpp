#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string s[n];
  for (int i = 0; i < n; i++) cin >> s[i];
  long long a[m];
  for (int i = 0; i < m; i++) cin >> a[i];
  long long ans = 0;
  for (int i = 0; i < m; i++) {
    long long maxi = 0;
    for (char c = 'A'; c <= 'D'; c++) {
      long long temp = 0;
      for (int j = 0; j < n; j++) {
        if (s[j][i] == c) temp += a[i];
      }
      maxi = max(temp, maxi);
    }
    ans += maxi;
  }
  cout << ans << endl;
  return 0;
}
