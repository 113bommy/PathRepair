#include <bits/stdc++.h>
using namespace std;
int a[10000], c[10000], k[10000], j, n, i, l, b, v;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (j = 1; j <= n; j++) {
    for (i = 1; i <= n; i++) c[i] = 0;
    b = 0;
    for (i = j; i <= n; i++) {
      v = a[i];
      c[v]++;
      if (c[v] > c[b] or (c[v] == c[b] && v < b)) b = v;
      k[b]++;
    }
  }
  for (i = 1; i <= n - 1; i++) cout << k[i] << " ";
  cout << k[n] << endl;
  return 0;
}
