#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int M = 510;
const int INF = 0x3f3f3f3f;
int a[N], b[N], f[N];
int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    for (int j = 1; j * j <= a[i]; ++j) {
      if (a[i] % j == 0) {
        f[i] = max(f[i], f[b[a[i] / j]] + 1);
        if (j > 1) f[i] = max(f[i], f[b[j]] + 1);
        b[a[i] / j] = b[j] = i;
      }
    }
    ans = max(ans, f[i]);
  }
  cout << ans << endl;
  return 0;
}
