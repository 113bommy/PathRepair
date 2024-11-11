#include <bits/stdc++.h>
using namespace std;
long long a, b, i, n, ans, p, ra[1000006], rb[1000006];
string s;
int main() {
  cin >> s;
  n = s.length();
  cin >> a >> b;
  ans = 0;
  for (i = 0; i < n; i++) {
    ra[i] = ((ans * 10) + (s[i] - '0')) % a;
    ans = ra[i];
  }
  ans = 0;
  p = 1;
  for (i = n - 1; i >= 0; i--) {
    rb[i] = (ans + ((s[i] - '0') * p)) % b;
    ans = rb[i];
    p = (p * 10) % b;
  }
  for (i = 1; i < n; i++) {
    if (ra[i - 1] == 0 && s[i] != '0' && rb[i] == 0) {
      cout << "YES\n";
      cout << s.substr(0, i) << " " << s.substr(i, n - i);
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
