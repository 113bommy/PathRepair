#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a, b, c;
  for (int i = 0; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    if (y == 0 && z == 0)
      continue;
    else if (y == 1 && z == 0)
      a.push_back(x);
    else if (y == 0 && z == 1)
      b.push_back(x);
    else
      c.push_back(x);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  int n1 = a.size();
  int n2 = b.size();
  int n3 = c.size();
  for (int i = 1; i < n1; i++) {
    a[i] += a[i - 1];
  }
  for (int i = 1; i < n2; i++) {
    b[i] += b[i - 1];
  }
  for (int i = 1; i < n3; i++) {
    c[i] += c[i - 1];
  }
  int ans = INT_MAX;
  int r = k;
  if (r <= n1 && r <= n2) {
    ans = min(ans, (r - 1 >= 0 ? a[r - 1] : 0) + (r - 1 >= 0 ? b[r - 1] : 0));
  }
  int s = 0;
  for (int i = 0; i < k && i < n3; i++) {
    int r = k - i - 1;
    s = c[i];
    if (r <= n1 && r <= n2) {
      ans = min(ans,
                s + (r - 1 >= 0 ? a[r - 1] : 0) + (r - 1 >= 0 ? b[r - 1] : 0));
    }
  }
  if (n3 >= k) ans = min(ans, c[k - 1]);
  if (ans == INT_MAX)
    cout << "-1\n";
  else
    cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tt;
  tt = 1;
  while (tt--) solve();
  return 0;
}
