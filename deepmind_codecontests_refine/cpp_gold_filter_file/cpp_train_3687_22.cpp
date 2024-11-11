#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, sum = 0, m, t = 0;
  int a[100010] = {};
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (k == 1) {
    cout << 1;
    return 0;
  }
  m = sum;
  for (int j = 0; j < k; j++) {
    sum = 0;
    for (int i = j; i < n + j; i += k) sum += a[i % n];
    if (sum < m) {
      t = j;
      m = sum;
    }
  }
  cout << t + 1;
  return 0;
}
