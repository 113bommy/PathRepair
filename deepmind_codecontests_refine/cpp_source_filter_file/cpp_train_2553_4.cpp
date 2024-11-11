#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1.0);
const int MAXN = 300001;
const int MAXM = MAXN * 10;
const int MODULE = 1000 * 1000 * 1000 + 7;
int n, k, q, m;
long long fct[MAXN];
long long of[MAXN];
long long ok;
int a[MAXM];
long long ans = 0;
int dv[MAXN], dc = 0;
int p[MAXN], pc = 0;
int l[MAXM];
long long f[MAXN];
long long pw(long long a, int b) {
  if (b == 0) return 1ll;
  long long v = pw(a, b / 2);
  v = (v * v) % MODULE;
  if (b % 2) v = (v * a) % MODULE;
  return v;
}
long long obr(long long x) { return pw(x, MODULE - 2); }
void ad(int x) {
  dc = 0, pc = 0;
  m++;
  int dx = x;
  int ii;
  for (ii = 1; ii * ii <= x; ii++) {
    if (x % ii == 0) {
      dv[dc++] = ii;
      if (ii == 1) continue;
      if (dx % ii == 0) p[pc++] = ii;
      while (dx % ii == 0) dx /= ii;
    }
  }
  if (dx != 1) p[pc++] = dx;
  ii--;
  for (; ii > 0; ii--) {
    if ((x % ii == 0) && (ii * ii != x)) dv[dc++] = x / ii;
  }
  for (int i = 0; i < dc; i++) l[dv[i]] = m;
  if (m >= k) {
    for (int i = 0; i < dc; i++) {
      int v = dv[i];
      if (a[v] >= (k - 1)) {
        f[v] = (of[k - 1] * of[a[v] - k + 1]) % MODULE;
        f[v] = (f[v] * fct[a[v]]) % MODULE;
      } else
        f[v] = 0;
    }
    for (int i = 0; i < pc; i++) {
      for (int j = 0; j < dc; j++) {
        long long nj = (long long)dv[j] * (long long)p[i];
        if ((nj <= x) && (l[nj] == m)) {
          f[dv[j]] -= f[nj];
          if (f[dv[j]] < 0) f[dv[j]] += MODULE;
        }
      }
    }
    for (int i = 0; i < dc; i++)
      ans = (ans + (f[dv[i]] * (long long)dv[i])) % MODULE;
  }
  for (int i = 0; i < dc; i++) a[dv[i]]++;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k >> q;
  memset(a, 0, sizeof(a));
  memset(l, 0, sizeof(l));
  fct[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    fct[i] = (fct[i - 1] * i) % MODULE;
  }
  for (int i = 0; i < MAXN; i++) of[i] = obr(fct[i]);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ad(x);
  }
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    ad(x);
    cout << ans << endl;
  }
  return 0;
}
