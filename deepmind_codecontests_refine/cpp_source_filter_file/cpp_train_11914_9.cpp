#include <bits/stdc++.h>
using namespace std;
int main() {
  long long o, i, j, n, ar, al;
  cin >> n >> ar >> al;
  long long a[ar + 1], b[al + 1], c[n + 1];
  for (i = 1; i <= ar; i++) cin >> a[i];
  for (j = 1; j <= al; j++) cin >> b[j];
  for (o = 1; o <= n; o++) a[o] = o;
  for (j = 1; j <= al; j++) {
    for (o = 1; o <= n; o++) {
      if (b[j] == o) c[o] = 2;
    }
  }
  for (i = 1; i <= ar; i++) {
    for (o = 1; o <= n; o++) {
      if (a[i] == o) c[o] = 1;
    }
  }
  for (o = 1; o <= n; o++) {
    cout << c[o] << " ";
  }
  return 0;
}
