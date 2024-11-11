#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  long long len = s.length();
  long long a[len + 1], b[len + 1];
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  for (long long i = 0; i < len; i++) {
    if (s[i] == 'a') {
      a[i + 1] = a[i] + 1;
      b[i + 1] = b[i];
    } else {
      b[i + 1] = b[i] + 1;
      a[i + 1] = a[i];
    }
  }
  long long ans = INT_MIN;
  long long temp = 0;
  for (long long i = 0; i <= len; i++) {
    for (long long j = i + 1; j <= len; j++) {
      temp += a[i];
      temp += (b[j] - b[i]);
      temp += (a[len] - a[j]);
      ans = max(ans, temp);
      temp = 0;
    }
  }
  cout << ans << "\n";
  return 0;
}
