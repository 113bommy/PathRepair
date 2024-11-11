#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 11;
int gett(int x) {
  int v = 1;
  if (x < 0) v = -1;
  x = abs(x);
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      int par = 0;
      while (x % i == 0) {
        x /= i;
        par ^= 1;
      }
      if (par) v *= i;
    }
  }
  if (x > 1) v *= x;
  return v;
}
int n, a[maxn], b[maxn], ans[maxn];
bool vis[maxn];
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = gett(a[i]);
  }
  vector<int> all(a, a + n);
  sort(all.begin(), all.end());
  all.resize(unique(all.begin(), all.end()) - all.begin());
  for (int i = 0; i < n; i++) {
    b[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin();
  }
  for (int i = 0; i < n; i++) {
    int k = 0;
    for (int j = i; j < n; j++) {
      if (!vis[b[j]] && a[j] != 0) {
        k++;
        vis[b[j]] = 1;
      }
      ans[max(k, 1)]++;
    }
    for (int j = i; j < n; j++) vis[b[j]] = 0;
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
  cout << endl;
}
