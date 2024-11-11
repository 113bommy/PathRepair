#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, d;
  cin >> n >> d;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int tobesearched = v[i] + d;
    int greater_ind =
        upper_bound(v.begin() + i + 1, v.end(), tobesearched) - v.begin();
    int ind = greater_ind - 1;
    if (ind >= i + 2 && ind < n) {
      long long total = ind - i + 1;
      total -= 2;
      if (total > 0) {
        ans += total * (total + 1) / 2;
      }
    }
  }
  cout << ans;
  return 0;
}
