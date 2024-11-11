#include <bits/stdc++.h>
using namespace std;
int main() {
  int i;
  int n, d, l;
  cin >> n >> d >> l;
  int pos = (n + 1) / 2;
  int neg = n / 2;
  int a[n + 1];
  if (d > (pos * l - neg) || d < (pos - neg * l)) {
    cout << "-1";
    return 0;
  }
  if (d > 0) {
    for (i = 1; i <= n; i++) a[i] = 1;
    i = 1;
    if (n & 1) d++;
    while (d) {
      a[2 * i - 1] += min(l - 1, d);
      d -= min(l - 1, d);
      i++;
    }
  } else {
    for (i = 1; i <= n; i++) a[i] = 1;
    i = 1;
    d = -d;
    if (n & 1) d++;
    while (d) {
      a[2 * i] += min(l - 1, d);
      d -= min(l - 1, d);
      i++;
    }
  }
  for (i = 1; i <= n; i++) cout << a[i] << " ";
  return 0;
}
