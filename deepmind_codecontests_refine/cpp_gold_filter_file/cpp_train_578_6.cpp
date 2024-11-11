#include <bits/stdc++.h>
using namespace std;
long long a[100010], b[100010];
int main() {
  long long k = 0, i, n, l, r;
  cin >> n >> l >> r;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (i = 1; i <= n; i++) {
    cin >> b[i];
    if ((i < l || i > r) && a[i] != b[i]) {
      k = 1;
    }
  }
  if (k == 1)
    cout << "LIE";
  else
    cout << "TRUTH";
  return 0;
}
