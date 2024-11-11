#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(2 * n), f(n + 1), s(n + 1);
  for (int i = 0; i < (2 * n); i++) cin >> v[i];
  for (int i = 0; i <= n; i++) f[i] = s[i] = -1;
  for (int i = 0; i < (2 * n); i++) {
    if (f[v[i]] == -1) {
      f[v[i]] = i;
    } else
      s[v[i]] = i;
  }
  for (int i = 1; i < n; i++) {
    if ((abs(f[i] - s[i + 1]) + abs(s[i] - f[i + 1])) <
        (abs(f[i] - f[i + 1]) + abs(s[i] - s[i + 1]))) {
      int c = s[i + 1];
      s[i + 1] = f[i + 1];
      f[i + 1] = c;
    }
  }
  int ans = f[1] + s[1];
  for (int i = 1; i < n; i++) {
    ans += abs(f[i + 1] - f[i]);
    ans += abs(s[i + 1] - s[i]);
  }
  cout << ans << '\n';
  return 0;
}
