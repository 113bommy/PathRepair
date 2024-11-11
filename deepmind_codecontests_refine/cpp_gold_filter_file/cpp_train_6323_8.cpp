#include <bits/stdc++.h>
using namespace std;
int p[105];
int main() {
  int n, k, ans = 0;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  int i = 1, j = n;
  while ((p[i] <= k || p[j] <= k) && (i < j)) {
    if (p[i] <= k) {
      ans++;
      i++;
    }
    if (p[j] <= k) {
      ans++;
      j--;
    }
  }
  if (i == j) {
    if (p[i] <= k) ans++;
  }
  cout << ans << endl;
  return 0;
}
