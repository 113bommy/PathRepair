#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 9;
int a[maxn], b[maxn], fun[maxn];
int main() {
  int i, j, k, n;
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  int mint = min(n, k), fi_ct = 0, ans = 0, mi, d = 0;
  while (fi_ct < n) {
    mi = 0x3f3f3f3f;
    for (i = 0; i < mint; i++) {
      if (b[i] > 0) {
        mi = min(mi, b[i]);
      }
    }
    for (i = 0; i < mint; i++) {
      if (a[i] - b[i] + mi >= d && a[i] - b[i] < d && b[i] > 0) {
        fun[i] = 1;
      }
    }
    for (i = 0; i < mint; i++) {
      if (b[i] > 0) {
        b[i] -= mi;
        if (b[i] == 0) fi_ct++;
      }
    }
    mint = min(n, k + fi_ct);
    d = double((100.0 * fi_ct) / n + 0.5);
  }
  for (i = 0; i < n; i++) {
    if (fun[i]) ans++;
  }
  cout << ans << endl;
}
