#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int l = -1, r = n;
  vector<int> def(n);
  for (int i = 0; i < n; ++i) {
    cin >> def[i];
  }
  while (l + 1 < r) {
    int curr = k;
    int ans = m;
    int mid = (l + r) / 2;
    for (int i = mid; i < n; ++i) {
      if (def[i] <= curr) {
        curr -= def[i];
      } else {
        curr = k - def[i];
        ans--;
      }
    }
    if (ans > 0) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << n - r;
  return 0;
}
