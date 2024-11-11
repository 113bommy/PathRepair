#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n;
int c[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  int ans = 1;
  for (int i = 0; i < n; i++) {
    if (c[i] != c[0]) ans = max(ans, i);
  }
  for (int i = 0; i < n; i++) {
    if (c[i] != c[n - 1]) ans = max(ans, n - 1 - i);
  }
  cout << ans << endl;
  return 0;
}
