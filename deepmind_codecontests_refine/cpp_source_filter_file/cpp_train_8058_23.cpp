#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, m, i, x, a[100001], f[100001];
  bool dd[100001];
  cin >> n >> m;
  memset(f, 0, sizeof(f));
  memset(dd, 0, sizeof(dd));
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = n; i > 0; i--) {
    f[i] = f[i + 1];
    if (dd[a[i]] == 0) f[i]++;
    dd[a[i]] = 1;
  }
  for (i = 1; i <= m; i++) {
    cin >> x;
    cout << f[x] << endl;
  }
}
