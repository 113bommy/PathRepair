#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, d = 0, i, k, ans = 0, x;
  char s[10000];
  cin >> n >> ans;
  for (i = 1; i <= n; i++) {
    cin >> s[0] >> x;
    if (s[0] == '+')
      ans += x;
    else if (ans >= x)
      ans -= x;
    else
      d++;
  }
  cout << ans << " " << d;
}
