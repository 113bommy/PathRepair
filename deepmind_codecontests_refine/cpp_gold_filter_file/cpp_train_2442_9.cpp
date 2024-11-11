#include <bits/stdc++.h>
using namespace std;
int n, k, a[1005], b[1005][1005], f[1005][1005], ans = 0;
int main() {
  cin >> n >> k;
  if (k == 1) {
    cout << n << endl;
    return 0;
  }
  for (int i = 0; i < int(k); i++)
    for (int j = 0; j < int(n); j++) {
      cin >> a[j];
      b[i][a[j]] = j;
    }
  ans = f[k - 1][0] = 1;
  for (int t = 0; t < int(k - 1); t++) f[t][a[0]] = 1;
  for (int i = 1; i < int(n); i++) {
    for (int j = 0; j < int(i); j++) {
      int mmin = int(1e9);
      for (int t = 0; t < int(k - 1); t++) {
        if (b[t][a[j]] > b[t][a[i]])
          mmin = 0;
        else
          mmin = min(mmin, f[t][a[j]]);
      }
      f[k - 1][i] = max(f[k - 1][i], mmin + 1);
    }
    ans = max(ans, f[k - 1][i]);
    for (int j = 0; j < int(i); j++)
      for (int t = 0; t < int(k - 1); t++) f[t][a[i]] = f[k - 1][i];
  }
  cout << ans << endl;
  return 0;
}
