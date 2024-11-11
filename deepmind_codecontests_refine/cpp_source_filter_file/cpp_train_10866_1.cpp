#include <bits/stdc++.h>
using namespace std;
long long a[100010], le[100010], ri[100010];
int main() {
  long long n, q, i, j;
  cin >> n >> q;
  for (i = 1; i <= n; i++) cin >> a[i];
  ri[n] = n;
  for (i = n - 1; i >= 1; i--) {
    if (a[i] > a[i + 1])
      ri[i] = i + 1;
    else
      ri[i] = ri[i + 1];
  }
  le[1] = 1;
  for (i = 2; i <= n; i++) {
    if (a[i] > a[i - 1])
      le[i] = i;
    else
      le[i] = le[i - 1];
  }
  while (q--) {
    long long l, r;
    cin >> l >> r;
    if (ri[l] >= le[r])
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
