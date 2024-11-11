#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, a[10000], b[10000], f[100050], r[10000];
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 1; i <= m; i++) cin >> b[i];
  r[n] = 1;
  f[a[n]] = 1;
  for (long long i = n - 1; i >= 1; i--) {
    if (f[a[i]] == 0) {
      r[i] = r[i + 1] + 1;
      f[a[i]] = 1;
    } else
      r[i] = r[i + 1];
  }
  for (int i = 1; i <= m; i++) cout << r[b[i]] << endl;
  return 0;
}
