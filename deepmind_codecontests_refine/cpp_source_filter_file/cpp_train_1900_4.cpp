#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  bool flag = false;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == k) {
      flag = true;
    }
  }
  if (!flag) {
    cout << "no" << '\n';
    return;
  }
  if (n == 1 and flag) {
    cout << "yes" << '\n';
    return;
  }
  flag = false;
  for (int i = 0; i < n; i++) {
    if (i - 1 > 0 and a[i] >= k and a[i - 1] >= k) flag = true;
    if (i - 1 > 0 and i + 1 < n and a[i - 1] >= k and a[i + 1] >= k)
      flag = true;
  }
  if (flag) {
    cout << "yes" << '\n';
    return;
  }
  cout << "no" << '\n';
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
