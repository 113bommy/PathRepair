#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const int mod = 1e9 + 7;
int t, n;
int a[maxn], last[maxn], ans[maxn], d[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) last[i] = 0, d[i] = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      ans[i] = -1;
      d[a[i]] = max(d[i], i - last[a[i]]);
      last[a[i]] = i;
    }
    for (int x = 1; x <= n; x++) {
      d[x] = max(d[x], n - last[x] + 1);
      for (int i = d[x]; i <= n && ans[i] == -1; i++) ans[i] = x;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
  }
  return 0;
}
