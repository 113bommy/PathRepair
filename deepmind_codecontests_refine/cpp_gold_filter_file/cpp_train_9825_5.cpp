#include <bits/stdc++.h>
const long long INF = pow(2, 60);
using namespace std;
int n, q, a, b;
int v[100005];
int c[100005];
long long f[100005];
long long fans() {
  memset(f, 128, sizeof(f));
  f[0] = 0;
  int c1 = 0, c2 = -1;
  for (int i = 0; i < n; i++) {
    long long r;
    if (c1 != c[i])
      r = f[c1] + 1LL * b * v[i];
    else {
      assert(c2 >= 0);
      r = f[c2] + 1LL * b * v[i];
    }
    if (f[c[i]] > -INF) r = max(r, f[c[i]] + 1LL * a * v[i]);
    if (r > f[c[i]]) {
      f[c[i]] = r;
      if (r > f[c1]) {
        c2 = c1;
        c1 = c[i];
      } else if (c[i] != c1 && (c2 < 0 || r > f[c2])) {
        c2 = c[i];
      }
    }
  }
  long long r = 0;
  for (int i = 1; i < n + 1; i++) r = max(r, f[i]);
  return r;
}
int main() {
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 0; i < n; i++) cin >> c[i];
  while (q--) {
    cin >> a >> b;
    cout << fans() << endl;
  }
  return 0;
}
