#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, k;
  cin >> n >> k;
  long long int a[n];
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  long long int b[200010] = {0};
  vector<long long int> c[200010];
  for (long long int i = 0; i < n; i++) {
    long long int x = a[i];
    while (x) {
      c[x].push_back(a[i]);
      b[x]++;
      x /= 2;
    }
    b[x]++;
    c[x].push_back(a[i]);
  }
  long long int ans = 1e15;
  for (long long int i = 0; i < 200010; i++) {
    if (b[i] >= k) {
      long long int tmp = 0;
      long long int cnt = 0;
      for (long long int j = 0; j < c[i].size(); j++) {
        if (cnt == k) {
          break;
        }
        long long int x = c[i][j];
        while (x != i) {
          tmp++;
          x /= 2;
        }
        cnt++;
      }
      ans = min(ans, tmp);
    }
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t, q;
  q = 1;
  for (t = 1; t <= q; t++) {
    solve();
  }
}
