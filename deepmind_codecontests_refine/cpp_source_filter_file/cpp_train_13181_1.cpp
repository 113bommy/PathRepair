#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k, a[16] = {0}, q[5] = {0};
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      cin >> q[j];
    }
    a[q[1] + q[2] * 2 + q[3] * 4 + q[4] * 8] = 1;
  }
  if (a[0]) {
    cout << "YES" << endl;
    return 0;
  }
  for (int i = 0; i < (1 << k); i++) {
    for (int j = 0; j < (1 << k); j++) {
      if (((i & j) == 0) && a[i] && a[j]) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
