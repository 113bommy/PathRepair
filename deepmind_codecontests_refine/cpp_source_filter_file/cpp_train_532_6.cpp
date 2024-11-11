#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, j, k, l = 0, n, m;
  cin >> n >> m >> k;
  long long int a[n], b[m];
  for (i = 0; i < n; i++) cin >> a[i];
  for (j = 0; j < n; j++) cin >> b[j];
  long long int ans = 0;
  for (i = 0; i < k; i++) {
    long long int p;
    cin >> p;
    p--;
    long long int q = a[p];
    for (j = 0; j < n; j++) {
      if (b[j] == b[p]) q = max(q, a[j]);
    }
    if (q >= a[p]) ans++;
  }
  cout << ans;
}
