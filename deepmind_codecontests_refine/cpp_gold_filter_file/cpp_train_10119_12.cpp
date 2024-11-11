#include <bits/stdc++.h>
using namespace std;
char a[11][11];
int main() {
  int n, k;
  cin >> n >> k;
  int key[11];
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < k; ++i) key[i] = i;
  int ans = 99999999;
  do {
    int mi = 99999999, mx = -1;
    for (int i = 0; i < n; ++i) {
      int q = 0;
      for (int j = 0; j < k; ++j) {
        q = q * 10 + (a[i][key[j]] - '0');
      }
      mx = max(mx, q);
      mi = min(mi, q);
    }
    ans = min(ans, mx - mi);
  } while (next_permutation(key, key + k));
  cout << ans;
  return 0;
}
