#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    int x = max(0, k - a[i] - a[i - 1]);
    a[i] += x;
    ans += x;
  }
  cout << ans << endl;
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
