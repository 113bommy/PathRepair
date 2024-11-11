#include <bits/stdc++.h>
using namespace std;
vector<int> l, r;
int a[110000];
int main() {
  int n;
  cin >> n;
  int ans = 0;
  int low = INT_MAX;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 0; i <= n; i++) {
    int diff = a[i + 1] - a[i];
    if (diff > 0) {
      ans += diff;
      for (int j = 0; j < diff; j++) {
        l.push_back(i + 1);
      }
    } else if (diff < 0) {
      diff = abs(diff);
      for (int j = 0; j < diff; j++) {
        r.push_back(i);
      }
    }
  }
  cout << ans << "\n";
  for (int i = 0; i < ans; i++) {
    cout << l[i] << " " << r[i] << "\n";
  }
  return 0;
}
