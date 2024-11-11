#include <bits/stdc++.h>
using namespace std;
int v[10000];
int main() {
  int n, t, i, j, cnt = 0, s = 0, ok = 0, cnt1 = 0;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cnt = 0;
    ok = 0;
    cnt1 = 0;
    cin >> t;
    for (j = 1; j <= t; j++) {
      cin >> v[j];
      if (v[j] % 2 == 0)
        cnt++;
      else
        cnt1++;
    }
    sort(v + 1, v + t + 1);
    if (cnt % 2 == 0 and cnt1 % 2 == 0) {
      cout << "YES\n";
      continue;
    }
    if (cnt % 2 == 0 and cnt1 % 2 == 1) {
      cout << "NO\n";
      continue;
    }
    if (cnt % 2 == 1 and cnt1 % 2 == 0) {
      cout << "NO\n";
      continue;
    }
    for (j = 1; j <= t; j++) {
      if (v[j + 1] - v[j] == 1) {
        ok = 1;
        cout << "YES\n";
        break;
      }
    }
    if (ok == 0) cout << "NO\n";
  }
  return 0;
}
