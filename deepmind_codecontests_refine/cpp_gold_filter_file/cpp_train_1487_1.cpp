#include <bits/stdc++.h>
using namespace std;
long long i, j, k, l, n, m;
long long a[300009], mx[300009], last[300009], res[300009];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int nt;
  cin >> nt;
  while (nt--) {
    cin >> n;
    for (i = 0; i <= n; i++) last[i] = 0, mx[i] = 0, res[i] = -1;
    for (i = 1; i <= n; i++) {
      cin >> a[i];
      mx[a[i]] = max(mx[a[i]], i - last[a[i]]);
      last[a[i]] = i;
    }
    for (i = 1; i <= n; i++) {
      if (mx[i] != 0) mx[i] = max(mx[i], n - last[i] + 1);
    }
    for (i = 1; i <= n; i++) {
      if (res[mx[i]] == -1) {
        res[mx[i]] = i;
      }
    }
    for (i = 2; i <= n; i++) {
      if (res[i] == -1)
        res[i] = res[i - 1];
      else {
        if (res[i - 1] != -1) res[i] = min(res[i], res[i - 1]);
      }
    }
    for (i = 1; i <= n; i++) cout << res[i] << ' ';
    cout << '\n';
  }
  exit(0);
}
