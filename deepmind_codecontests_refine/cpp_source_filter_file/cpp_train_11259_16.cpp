#include <bits/stdc++.h>
using namespace std;
int n, t;
int s[105], d[105], ans[105];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> t;
  for (int i = 1; i <= n; i++) {
    cin >> s[i] >> d[i];
  }
  for (int i = 1; i <= n; i++) {
    if (n <= s[i])
      ans[i] = s[i];
    else
      ans[i] =
          s[i] + (t - s[i]) / d[i] * d[i] + ((t - s[i]) % d[i] != 0) * d[i];
  }
  int x = 1000000;
  int y = 0;
  for (int i = 1; i <= n; i++) {
    if (x > ans[i]) {
      y = i;
      x = ans[i];
    }
  }
  cout << y;
  return 0;
}
