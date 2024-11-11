#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long n, z, a, b, x, y, d, m, k, c, N = 1e5 + 5;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  long long arr[n], arr1[m];
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < m; i++) cin >> arr1[i];
  for (int w = 1; w < 512; w++) {
    for (int i = 0; i < n; i++) {
      a = 0;
      for (int j = 0; j < m; j++) {
        b = arr[i] & arr1[j];
        if ((b | w) == w) {
          a = 1;
          break;
        }
      }
      if (a == 0) break;
      if (i == n - 1) return cout << w, 0;
    }
  }
  return 0;
}
