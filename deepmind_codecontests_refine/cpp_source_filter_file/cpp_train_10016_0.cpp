#include <bits/stdc++.h>
using namespace std;
const int N = 200200;
const long long inf = (long long)1.01e18;
int a[N];
int b[N];
int at[N];
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    at[a[i]] = i;
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  int maxPos = 0;
  long long ans = 0;
  for (int i = 1; i <= m; i++) {
    if (at[b[i] > maxPos]) {
      maxPos = at[b[i]];
      ans += 2 * (at[b[i]] - i) + 1;
    } else {
      ans++;
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) solve();
  return (0);
}
