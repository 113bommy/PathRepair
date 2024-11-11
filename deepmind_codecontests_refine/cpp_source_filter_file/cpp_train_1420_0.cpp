#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 0, j;
  cin >> n;
  vector<int> v(n), used(n);
  for (int i = 1; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  for (int i = 0; i < n - 1; i++) {
    j = i + 1;
    while (j < n && (v[j] == v[i] || used[j] == 1)) j++;
    if (j < n) {
      v[i] = 0;
      used[j] = 1;
    }
  }
  for (int i = 0; i < n; i++)
    if (v[i] > 0) ans++;
  cout << ans;
  return 0;
}
