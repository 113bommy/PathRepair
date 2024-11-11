#include <bits/stdc++.h>
using namespace std;
int main() {
  long long ans = 0, temp;
  long long i, n, p, now = 0;
  string s[100];
  cin >> n >> p;
  for (i = 1; i <= n; i++) cin >> s[n - i + 1];
  for (i = 1; i <= n; i++) {
    if (s[i][4] == 'p') {
      ans += (2 * now + 1) * (p / 2);
      now = now * 2 + 1;
    } else {
      ans += (2 * now) * (p / 2);
      now = now * 2;
    }
  }
  cout << ans << endl;
  return 0;
}
