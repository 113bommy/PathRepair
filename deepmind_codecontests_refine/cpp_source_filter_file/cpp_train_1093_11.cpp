#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, a[1000000], p = 0, q = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  if (k <= n) {
    int l = 0, r = (2 * (n - k) - 1);
    p = a[l] + a[r];
    int i = 1;
    while (i < (n - k)) {
      q = a[l] + a[r];
      p = max(p, q);
      l = l + 1;
      r = r - 1;
      i++;
    }
    p = max(p, a[n - 1]);
    cout << p;
  } else
    cout << a[n - 1];
}
