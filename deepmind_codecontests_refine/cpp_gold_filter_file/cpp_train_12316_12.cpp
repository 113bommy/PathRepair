#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, l, m, n, d, cnt = 0;
  cin >> k >> l >> m >> n >> d;
  vector<int> arr(d + 1, 0);
  if (k == 1 || l == 1 || m == 1 || n == 1) {
    cout << d << "\n";
    return 0;
  }
  for (int i = k; i <= d; i += k) {
    arr[i] = 1;
  }
  for (int i = l; i <= d; i += l) {
    arr[i] = 1;
  }
  for (int i = m; i <= d; i += m) {
    arr[i] = 1;
  }
  for (int i = n; i <= d; i += n) {
    arr[i] = 1;
  }
  for (int i = 1; i <= d; i++) {
    if (arr[i]) cnt++;
  }
  cout << cnt << "\n";
}
