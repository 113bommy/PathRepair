#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[n][m];
  int best[n];
  for (int i = 0; i < (n); i++)
    for (int j = 0; j < (m); j++) cin >> a[i][j];
  memset(best, 0, sizeof best);
  for (int j = 0; j < (m); j++) {
    for (int i = 0; i < n;) {
      int s = i;
      i++;
      while (i < n && a[i - 1][j] <= a[i][j]) i++;
      best[s] = max(i - 1, best[s]);
    }
    for (int i = (1); i < (n); i++)
      if (a[i - 1][j] <= a[i][j]) best[i] = max(best[i], best[i - 1]);
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    cout << (best[l] >= r ? "YES" : "NO") << endl;
  }
  return 0;
}
