#include <bits/stdc++.h>
using namespace std;
int main() {
  int cnt = 0, n, k, a[1000], z[1000];
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  z[0] = a[0];
  for (int i = 0; i < n - 1; i++) {
    if (z[i] + a[i + 1] < k) {
      z[i + 1] = k - (z[i]);
      cnt += k - (z[i] + a[i + 1]);
    } else {
      z[i + 1] = a[i + 1];
    }
  }
  cout << cnt << endl;
  for (int i = 0; i < n; i++) cout << z[i] << " ";
  return 0;
}
