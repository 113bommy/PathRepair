#include <bits/stdc++.h>
using namespace std;
int n, m, res = 0;
int a[100];
int main() {
  cin >> n >> m;
  for (int i = 0, q, w, e; i < m; i++) {
    cin >> q >> w >> e;
    a[q] += -e;
    a[w] += e;
  }
  for (int i = 1; i <= n; i++)
    if (a[i] >= 0) res += a[i];
  cout << res << endl;
  return 0;
}
