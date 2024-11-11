#include <bits/stdc++.h>
using namespace std;
int a[201];
int n, m, k, i, j, l, p, q, res, maxx;
vector<int> x, y;
int main() {
  cin >> n >> k;
  for (i = 1; i <= n; i++) cin >> a[i], res = (res > a[i] ? res : a[i]);
  for (i = 1; i <= n; i++)
    for (j = i + 1; j <= n; j++) {
      x.clear();
      y.clear();
      maxx = 0;
      for (l = i; l <= j; l++) x.push_back(a[l]), maxx += a[l];
      for (l = 1; l < i; l++) y.push_back(a[l]);
      for (l = j + 1; l <= n; l++) y.push_back(a[l]);
      sort(x.begin(), x.end());
      sort(y.begin(), y.end());
      reverse(y.begin(), y.end());
      for (l = 0; l < min(k, min(j - i + 1, n - j + i - 1)); l++)
        if (x[l] < y[l]) maxx -= x[l] - y[l];
      res = (res > maxx ? res : maxx);
    }
  cout << res;
}
