#include <bits/stdc++.h>
using namespace std;
long long ceil(long long x) { return x % 2 ? x / 2 + 1 : x / 2; }
int main() {
  long long n, x1, x2;
  cin >> n >> x1 >> x2;
  string s;
  cin >> s;
  long long c = 0;
  for (int i = 1; i < n; i++)
    if (s[i] != s[i - 1]) c++;
  long long ans = 0;
  if (c == 0) {
    if (s[0] == '1')
      cout << 0;
    else
      cout << x2;
    return 0;
  } else if (s[0] == '0' && s[n - 1] == '0') {
    ans = min(c / 2 * x1 + x2, (c / 2 + 1) * x2);
  } else if (s[0] == '0' && s[n - 1] == '1') {
    ans = min(c / 2 * x1 + x2, (c / 2 + 1) * x2);
  } else if (s[0] == '1' && s[n - 1] == '0') {
    ans = min(c / 2 * x1 + x2, (c / 2 + 1) * x2);
  } else if (s[0] == '1' && s[n - 1] == '1') {
    ans = min((c / 2 - 1) * x1 + x2, (c / 2) * x2);
  }
  cout << ans;
}
