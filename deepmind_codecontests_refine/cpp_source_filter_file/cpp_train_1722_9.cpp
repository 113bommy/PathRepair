#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  std::vector<int> a(n);
  std::vector<int> b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  int l = 0;
  int r = 1001;
  while (l < r) {
    int count = 0;
    int mid = (l + r) / 2;
    for (int i = 0; i < n; i++) {
      count += max(0, a[i] * (mid + 1) - b[i]);
    }
    if (count <= k) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  if (l == r) {
    cout << l << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}
