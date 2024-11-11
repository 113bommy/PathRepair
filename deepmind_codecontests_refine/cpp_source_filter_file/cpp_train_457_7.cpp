#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, l, i, j, a[110], m, maxn;
  cin >> n >> l;
  for (i = 1; i <= n; i++) cin >> a[i];
  sort(a, a + i);
  maxn = 0;
  if (a[i - 1] >= l) {
    for (i = l; i <= a[i - 1]; i++) {
      m = 0;
      for (j = 0; j < n; j++) m += a[j] / i * i;
      maxn = max(m, maxn);
    }
    cout << maxn << endl;
  } else
    cout << "0" << endl;
  return 0;
}
