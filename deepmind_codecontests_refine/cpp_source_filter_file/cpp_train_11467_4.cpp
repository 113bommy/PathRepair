#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum < m) {
    cout << -1;
    return;
  }
  if (sum == m) {
    cout << n;
    return;
  }
  sort(a.rbegin(), a.rend());
  int cnt = 1;
  sum = 0;
  for (int i = 0; i < n; i++) {
    cnt++;
    sum = 0;
    for (int j = 0; j < n; j++) {
      sum += max(a[j] - j / cnt, 0);
    }
    if (sum >= m) break;
  }
  cout << cnt;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  t = 1;
  while (t--) {
    solve();
    cout << '\n';
  }
}
