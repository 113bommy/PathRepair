#include <bits/stdc++.h>
using namespace std;
const int _N = 1e3 + 10, mod = 1e9 + 7, INF = 0x3f3f3f3f;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    char s[_N];
    int f[_N] = {0}, idx = 0, ans = 0;
    cin >> s + 1;
    for (int i = 1; s[i]; i++) {
      if (s[i] == '1')
        f[idx]++;
      else
        idx++;
    }
    sort(f, f + idx + 1);
    reverse(f, f + idx + 1);
    for (int i = 0; i <= idx + 1; i++) {
      if (i % 2 == 0) ans += f[i];
      if (f[i] == 0) break;
    }
    cout << ans << '\n';
  }
}
