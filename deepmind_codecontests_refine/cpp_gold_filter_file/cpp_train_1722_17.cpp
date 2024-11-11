#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, ans = 0;
  cin >> n >> k;
  vector<int> v1(n + 1);
  vector<int> v2(n + 1);
  for (int i = 1; i <= n; i++) cin >> v1[i];
  for (int i = 1; i <= n; i++) cin >> v2[i];
  int start = 1, end = 2000, mid;
  while (start <= end) {
    mid = (start + end) / 2;
    bool m = true;
    int index = 0;
    int v = k;
    for (int i = 1; i <= n; i++) {
      int x = (mid * v1[i]) - v2[i];
      int y = (v2[i] / v1[i]);
      if (y >= mid) {
        m = true;
      } else if (v >= x) {
        m = true;
        v = (v - x);
      } else {
        m = false;
        index = i;
        break;
      }
    }
    if (m == true) {
      ans = mid;
      start = mid + 1;
    } else {
      end = mid - 1;
    }
    m = true;
  }
  cout << ans;
  return 0;
}
