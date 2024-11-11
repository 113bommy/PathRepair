#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m;
  cin >> n >> m;
  long long arr[n];
  memset(arr, 0, sizeof(arr));
  long long ans = n;
  for (long long i = 0; i < m; i++) {
    long long u, v;
    cin >> u >> v;
    u--, v--;
    if (u > v) {
      arr[v]--;
      if (arr[v] == -1) ans--;
    } else {
      arr[u]--;
      if (arr[u] == -1) ans--;
    }
  }
  long long q;
  cin >> q;
  for (long long i = 0; i < q; i++) {
    int c;
    cin >> c;
    if (c == 1) {
      long long u, v;
      cin >> u >> v;
      u--, v--;
      if (u > v) {
        arr[v]--;
        if (arr[v] == -1) ans--;
      } else {
        arr[u]--;
        if (arr[u] == -1) ans--;
      }
    } else if (c == 2) {
      long long u, v;
      cin >> u >> v;
      u--, v--;
      if (u > v) {
        arr[v]++;
        if (arr[v] == 0) ans++;
      } else {
        arr[u]++;
        if (arr[u] == 0) ans++;
      }
    } else {
      cout << ans << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  solve();
  return 0;
}
