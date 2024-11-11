#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    bool ok = 0;
    a[n + 1] = a[n + 2] = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      ok = ok | (a[i] == k);
    }
    if (!ok)
      cout << "no\n";
    else if (n == 1)
      cout << "yes\n";
    else {
      ok = 0;
      for (int i = 1; i <= n; ++i) {
        if (a[i] >= k) {
          if (a[i - 1] >= a[i] || a[i + 1] >= a[i])
            ok = 1;
          else if (a[i + 2] >= a[i] || (i > 1 && a[i - 2] >= a[i]))
            ok = 1;
        }
      }
      if (ok)
        cout << "yes\n";
      else
        cout << "no\n";
    }
  }
  return 0;
}
