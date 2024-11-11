#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-16;
const int N = 209;
const int inf = (int)1e9;
const int mod = (int)1e9 + 7;
char s[N];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      int dx = 0;
      int dy = 0;
      for (int k = i; k <= j; k++) {
        dx += s[k] == 'R' ? 1 : s[k] == 'L' ? -1 : 0;
        dy += s[k] == 'U' ? 1 : s[k] == 'D' ? -1 : 0;
      }
      if (dx == 0 && dy == 0) {
        ans++;
      }
    }
  }
  cout << ans;
  return 0;
}
