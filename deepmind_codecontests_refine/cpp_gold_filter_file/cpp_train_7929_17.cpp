#include <bits/stdc++.h>
using namespace std;
int pos[10010];
int main() {
  int n;
  cin >> n;
  int a[n + 10];
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int m;
  cin >> m;
  int b[m + 10];
  for (int i = 1; i <= m; ++i) cin >> b[i];
  for (int j = 1; j <= n; ++j) {
    for (int z = 1; z <= m; ++z) {
      int s = a[j] + b[z], f = 0;
      for (int i = 1; i <= n; ++i)
        if (s != a[i]) f++;
      for (int k = 1; k <= m; ++k)
        if (s != b[k]) f++;
      if (f == n + m) {
        cout << a[j] << ' ' << b[z];
        exit(0);
      }
    }
  }
  return 0;
}
