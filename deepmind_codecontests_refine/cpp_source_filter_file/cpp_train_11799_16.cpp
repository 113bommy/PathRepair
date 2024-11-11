#include <bits/stdc++.h>
using namespace std;
struct sss {
  double q, w;
} a[1005];
int n, ans = 2, m;
bool cmp(sss a, sss s) { return a.q < a.q; }
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    double q, w;
    cin >> q >> w;
    a[i].q = q - w / 2;
    a[i].w = q + w / 2;
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 2; i <= n; i++) {
    if (a[i].q - a[i - 1].w > m) ans += 2;
    if (a[i].q - a[i - 1].w == m) ans++;
  }
  cout << ans;
}
