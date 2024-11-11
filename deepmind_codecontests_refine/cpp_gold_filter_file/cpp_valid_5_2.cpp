#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn];
int b[maxn];
void solve() {
  int n;
  cin >> n;
  a[0] = b[0] = a[n + 1] = b[n + 1] = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%1d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%1d", &b[i]);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (b[i]) {
      if (a[i]) {
        if (a[i - 1] == 1) {
          a[i - 1] = -1;
          ans++;
        } else if (a[i + 1] == 1) {
          a[i + 1] = -1;
          ans++;
        }
      } else if (a[i] == 0)
        ans++, a[i] = -1;
    }
  }
  cout << ans << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
