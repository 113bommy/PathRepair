#include <bits/stdc++.h>
using namespace std;
int n, m, k, t, a, b, i, j;
int arr[1000];
int main() {
  cin >> n >> m >> k;
  for (i = 1; i <= n; i++) {
    cin >> a;
    arr[i] = a;
  }
  b = -10000;
  for (i = m; i >= 0; i--) {
    if (arr[i] != 0 && arr[i] <= k) {
      b = i;
      break;
    }
  }
  j = 10000000;
  for (i = m; i <= n; i++) {
    if (arr[i] != 0 && arr[i] <= k) {
      j = i;
      break;
    }
  }
  if ((m - b) < (j - m))
    cout << (m - b) * 10 << endl;
  else
    cout << (j - m) * 10 << endl;
  return 0;
}
