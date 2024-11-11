#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, m, p, i, j, r = 0, s = 0;
  cin >> n >> m >> p;
  long long int a[n], b[m];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % p != 0 && r == 0) {
      r = i;
    }
  }
  for (i = 0; i < m; i++) {
    cin >> b[i];
    if (b[i] % p != 0 && s == 0) {
      s = i;
    }
  }
  cout << r + s;
  return 0;
}
