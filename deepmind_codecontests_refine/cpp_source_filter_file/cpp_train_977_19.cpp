#include <bits/stdc++.h>
using namespace std;
int n;
int a[100010];
int f[100010];
int main() {
  while (cin >> n) {
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    int ans = 1;
    f[1] = a[1];
    for (int i = 2; i <= n; ++i) {
      int pos = lower_bound(f, f + ans, a[i]) - f;
      if (a[i] >= f[pos])
        f[++ans] = a[i];
      else
        f[ans] = a[i];
    }
    cout << ans << endl;
  }
  return 0;
}
