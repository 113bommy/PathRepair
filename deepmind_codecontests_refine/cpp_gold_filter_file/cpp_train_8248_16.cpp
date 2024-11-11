#include <bits/stdc++.h>
using namespace std;
int a[2000] = {0}, b[2000] = {0}, j;
void check(int maxn) {
  bool done = false;
  for (j = 1; j <= 1024; j++) {
    memset(b, 0, sizeof(b));
    for (int i = 0; i <= maxn; i++) {
      if (a[i] > 0) b[i ^ j]++;
    }
    done = true;
    for (int i = 0; i <= maxn; i++) {
      if (a[i] != b[i]) {
        done = false;
        break;
      }
    }
    if (done) {
      cout << j << endl;
      break;
    }
  }
  if (!done) cout << -1 << endl;
}
int main() {
  int t, n, maxn, x;
  cin >> t;
  while (t--) {
    cin >> n;
    memset(a, 0, sizeof(a));
    maxn = 0;
    for (int i = 0; i < n; i++) {
      cin >> x;
      a[x]++;
      maxn = max(maxn, x);
    }
    if (n == 2) {
      if (a[0] > 0)
        cout << maxn << endl;
      else
        check(maxn);
    } else
      check(maxn);
  }
  return 0;
}
