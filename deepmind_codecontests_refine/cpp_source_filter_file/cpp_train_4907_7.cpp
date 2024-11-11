#include <bits/stdc++.h>
using namespace std;
const long long N = 25 * 10000 + 8, M = 4e2 + 8, inf = 1e18;
long long n, m, q[M], a[M], s[M], f[M], c[M], r[M], R = inf, l, mid, ans, t, B;
bool val(int ind, long long x) {
  t = 0, B = x;
  for (int i = s[ind]; i < f[ind]; i++) {
    if (B < (a[i + 1] - a[i]) * c[ind]) {
      B = x;
      t++;
    }
    if ((a[i + 1] - a[i]) * c[ind] > x) return 0;
    B -= (a[i + 1] - a[i]) * c[ind];
    if (t > r[ind]) return 0;
  }
  return 1;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) {
    cin >> s[i] >> f[i] >> c[i] >> r[i];
    s[i]--, f[i]--;
  }
  for (int i = 0; i < m; i++) q[i] = i;
  srand(time(0));
  random_shuffle(q, q + m);
  for (int i = 0; i < m; i++) {
    if (!val(q[i], ans)) {
      l = 0, R = inf;
      while (R - l > 1) {
        mid = (l + R) / 2;
        if (val(q[i], mid))
          R = mid;
        else
          l = mid;
      }
      ans = R;
    }
  }
  cout << ans;
}
