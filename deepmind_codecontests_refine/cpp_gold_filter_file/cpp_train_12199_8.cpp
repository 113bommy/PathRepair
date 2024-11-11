#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s, t;
  cin >> s >> t;
  long long int n = s.length();
  long long int m = t.length();
  long long int fo[m];
  long long int f = 0;
  for (long long int i = 0; i < n; i++) {
    if (s[i] == t[f]) {
      fo[f] = i;
      f++;
    }
    if (f == m) {
      break;
    }
  }
  long long int ba[m];
  long long int b = m - 1;
  for (long long int i = n - 1; i >= 0; i--) {
    if (s[i] == t[b]) {
      ba[b] = i;
      b--;
    }
    if (b == -1) {
      break;
    }
  }
  long long int ans = ba[0];
  for (long long int i = 1; i < m; i++) {
    ans = max(ans, (ba[i] - fo[i - 1] - 1));
  }
  ans = max(ans, (n - 1 - fo[m - 1]));
  cout << ans << endl;
  return 0;
}
