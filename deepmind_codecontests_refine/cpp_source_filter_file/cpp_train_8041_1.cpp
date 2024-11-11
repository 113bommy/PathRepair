#include <bits/stdc++.h>
using namespace std;
long long n, m, c, c1, i, j, a[100007];
int main() {
  cin >> m;
  for (j = 1; j <= m; j++) {
    c = 0;
    c1 = 0;
    cin >> n;
    for (i = 0; i <= n; i++) {
      cin >> a[i];
      if (i % 2 == 1 && a[i] % 2 == 0) c++;
      if (i % 2 == 0 && a[i] % 2 == 1) c1++;
    }
    if (c == c1)
      cout << c1 << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
