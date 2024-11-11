#include <bits/stdc++.h>
using namespace std;
int n, k, a[105], s[105], b[105];
int main() {
  cin >> n;
  cin >> k;
  int i, dg, j, c[105], p = 1;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n; i++) b[i] = a[i];
  sort(b + 1, b + 1 + n);
  if (b[1] > k)
    cout << "0";
  else {
    for (i = 1; i <= n; i++) {
      s[i] = s[i - 1] + b[i];
      if (s[i] == k) {
        dg = i;
      } else if (s[i] > k) {
        dg = i - 1;
        break;
      } else if (s[n] < k) {
        dg = n;
      }
    }
    for (i = 1; i <= dg; i++) {
      for (j = 1; j <= n; j++)
        if (b[i] == a[j]) {
          a[j] = 32000;
          c[p] = j;
          p++;
          break;
        }
    }
    cout << dg << endl;
    for (j = 1; j < p; j++) cout << c[j] << " ";
  }
}
