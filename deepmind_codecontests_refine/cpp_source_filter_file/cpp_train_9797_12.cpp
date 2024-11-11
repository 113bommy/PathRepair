#include <bits/stdc++.h>
using namespace std;
const int nax = 1000 * 1007;
int main() {
  int n, k;
  cin >> n >> k;
  int ans = 0, curr = 0, index = 0;
  for (int i = 0; i < k + 1; i++) {
    curr = 0;
    int j = i;
    while (j < n) {
      curr++;
      j += (2 * k) + 1;
    }
    if (curr > ans) {
      ans = curr;
      index = i;
    }
  }
  cout << ans << endl;
  for (int i = index + 1; i <= n; i += (2 * k) + 1) cout << i << " ";
  return 0;
}
