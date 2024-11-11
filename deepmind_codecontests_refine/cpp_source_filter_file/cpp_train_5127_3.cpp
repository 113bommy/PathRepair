#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const long long INF = 1e18;
const int Mod = 1e9 + 7;
const int maxn = 1e6 + 10;
int f[maxn];
void init() {
  memset(f, 0, sizeof(f));
  int m = sqrt(maxn + 0.5);
  for (int i = 2; i < m; i++) {
    if (!f[i]) {
      f[i] = i;
      for (int j = 2 * i; j < maxn; j += i) {
        if (!f[j]) f[j] = i;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t, n, k;
  init();
  cin >> t;
  while (t--) {
    cin >> n >> k;
    long long ans = n + f[n];
    cout << ans + 2 * (k - 1) << endl;
  }
  return 0;
}
