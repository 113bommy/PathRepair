#include <bits/stdc++.h>
using namespace std;
const long long LINF = (long long)1e18 + 47;
const int INF = (int)1e9 + 47;
const int MOD = (int)1e9 + 7;
const int modulo = 998244353.;
const int nax = (int)1e5 * 2 + 10;
const double EPS = 1e-7;
const double PI = acos(-1.0);
void mul(int &a, int b) { a = (a * 1ll * b) % modulo; }
int pos[nax];
int a[nax];
int b[nax];
int general[nax];
int ans = 1;
int n, k;
bool process(int x) {
  int p1 = pos[x] - 1;
  int p2 = pos[x] + 1;
  if (p1 < 0) {
    if (general[a[p2]]) return false;
    return true;
  }
  if (p2 > n) {
    if (general[a[p1]]) return false;
    return true;
  }
  if (general[a[p1]] && general[a[p2]]) {
    return false;
  }
  if (!general[a[p1]] && !general[a[p2]]) {
    mul(ans, 2);
  }
  return true;
}
int main() {
  int tt;
  cin >> tt;
  for (int test = (1); test < (tt + 1); test++) {
    cin >> n >> k;
    for (int i = (0); i < (n); i++) {
      cin >> a[i];
      pos[a[i]] = i;
    }
    for (int i = (0); i < (k); i++) {
      cin >> b[i];
      general[b[i]] = 1;
    }
    bool ok = true;
    for (int i = (0); i < (k); i++) {
      ok &= process(b[i]);
      general[b[i]] = 0;
    }
    for (int i = (0); i < (n + 1); i++) general[i] = 0;
    if (!ok)
      cout << 0 << '\n';
    else
      cout << ans << '\n';
    ans = 1;
  }
}
