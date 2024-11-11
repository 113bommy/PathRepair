#include <bits/stdc++.h>
using namespace std;
struct BO {
  int a, b;
} a[300];
int n, tot, mt, tt;
int f[110][11000];
int cmp(const BO &x, const BO &y) { return x.b < y.b; }
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].a;
    tot += a[i].a;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i].b;
    mt += a[i].b;
  }
  sort(a + 1, a + n + 1, cmp);
  int K = 0;
  tt = tot;
  for (int i = n; i >= 1 && tot > 0; i--) {
    K++;
    tot -= a[i].b;
  }
  int ans = 0;
  memset(f, -127 / 3, sizeof(f));
  f[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = K; j >= 1; j--)
      for (int k = mt; k >= a[i].b; k--)
        f[j][k] = max(f[j][k], f[j - 1][k - a[i].b] + a[i].a);
  }
  for (int k = tot; k <= mt; k++) ans = max(ans, f[K][k]);
  cout << K << ' ' << tt - ans << endl;
}
