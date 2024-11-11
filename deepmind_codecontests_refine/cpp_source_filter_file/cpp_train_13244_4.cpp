#include <bits/stdc++.h>
using namespace std;
vector<int> Char[26];
void answer() {
  long long n, m, ans = 0, ma = 0;
  cin >> n >> m;
  long long a[n + 1];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ma = max(ma, a[i]);
    if (a[i] == m) ans = 1;
  }
  if (ans == 1) {
    cout << 1 << "\n";
    return;
  } else if (ma > m) {
    cout << 2 << "\n";
    return;
  }
  if (ma < m && 2 * ma > m) {
    cout << 2 << '\n';
    return;
  }
  ans = 999999999999;
  for (int i = 0; i < n; i++) {
    if (m % a[i] == 0) ans = min(ans, m / a[i]);
  }
  int f = 2;
  for (int i = 0; i < n; i++) {
    if (a[i] == m % ma) f = 1;
  }
  ans = min(ans, (m / ma) + f);
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int q;
  cin >> q;
  while (q--) answer();
  return 0;
}
