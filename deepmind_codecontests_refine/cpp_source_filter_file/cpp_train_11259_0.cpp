#include <bits/stdc++.h>
using namespace std;
int n, t, s[105], d[105];
int main() {
  cin >> n >> t;
  for (int i = 1; i <= n; i++) cin >> s[i] >> d[i];
  for (int i = 1; i <= n; i++)
    while (s[i] < t) s[i] += d[i];
  int ans, minn = 100006;
  for (int i = 1; i <= n; i++)
    if (s[i] < minn) {
      minn = s[i];
      ans = i;
    }
  cout << ans;
  return 0;
}
