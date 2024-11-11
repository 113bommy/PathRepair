#include <bits/stdc++.h>
using namespace std;
long long int ans[200009];
void solve() {
  long long int n, m;
  cin >> n >> m;
  long long int a[m + 2];
  for (long long int i = 1; i <= m; i++) {
    cin >> a[i];
  }
  long long int pos[m + 2];
  long long int q = n;
  for (long long int i = m; i > 0; i--) {
    if (q <= 0) {
      cout << -1;
      return;
    }
    long long int x = n - a[i] + 1;
    q = min(q, x);
    pos[i] = q;
    q--;
  }
  q = 1;
  for (long long int i = 1; i <= m; i++) {
    long long int x = min(q, pos[i]);
    pos[i] = x;
    q = x + a[i];
  }
  if (q <= n) {
    cout << -1;
    return;
  }
  for (long long int i = 1; i <= m; i++) cout << pos[i] << ' ';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t = 1;
  for (long long int i = 0; i < t; i++) {
    solve();
  }
}
