#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a[100010], n, i, j, k, l, r;
  char c[10010];
  cin >> n;
  for (i = 0; i < n; i++) scanf("%lld", &a[i]);
  scanf("%s", c);
  l = (long long)-1e10;
  r = (long long)1e10;
  for (i = 4; i < n; i++) {
    if (c[i] == '0') {
      if (c[i - 1] == '0') continue;
      k = (long long)1e10;
      for (j = 0; j < 5; j++) {
        if (a[i - j] < k) k = a[i - j];
      }
      r = min(r, k - 1);
    }
    if (c[i] == '1') {
      if (c[i - 1] == '1') continue;
      k = (long long)-1e10;
      for (j = 0; j < 5; j++) {
        if (a[i - j] > k) k = a[i - j];
      }
      l = max(l, k + 1);
    }
  }
  if (l == (long long)-1e10) {
    l = (long long)-1e9;
  }
  if (r == (long long)1e10) {
    r = (long long)1e9;
  }
  cout << l << " " << r << endl;
  return 0;
}
