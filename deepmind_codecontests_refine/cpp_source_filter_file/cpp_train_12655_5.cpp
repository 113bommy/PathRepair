#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int a[n];
  int ans = 0;
  vector<int> add(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    if (a[i - 1] + a[i] < k) {
      int t = k - a[i - 1] - a[i];
      add[i] = t;
      ans += t;
      a[i] += t;
    }
  }
  cout << ans << "\n";
  for (int i = 0; i < n; i++) {
    cout << add[i] << " ";
  }
  return 0;
}
