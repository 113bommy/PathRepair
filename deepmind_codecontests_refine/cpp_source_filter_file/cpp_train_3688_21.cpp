#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n - 1; ++i) {
    cin >> a[i];
  }
  int x, y;
  cin >> x >> y;
  int ans = 0;
  for (int i = x - 1; i < y - 2; ++i) {
    ans += a[i];
  }
  cout << ans;
  return 0;
}
