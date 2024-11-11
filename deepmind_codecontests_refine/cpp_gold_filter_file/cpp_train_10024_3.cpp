#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (auto &i : v) cin >> i;
  int maxv = -1, maxi = -1, minv = INT_MAX, mini = -1;
  for (int i = 0; i < n; i++) {
    if (v[i] > maxv) {
      maxv = v[i];
      maxi = i;
    }
    if (v[n - 1 - i] < minv) {
      minv = v[n - 1 - i];
      mini = n - 1 - i;
    }
  }
  int ans = maxi + (n - 1 - mini);
  if (maxi > mini) ans--;
  cout << ans << '\n';
}
