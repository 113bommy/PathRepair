#include <bits/stdc++.h>
using namespace std;
const long long N = 1000006, INF = 1e18, MOD = 998244353;
long long n, m, r, t, a[N], b[N], c[N], d[N], q = 1, e, o, u, k, x, y, ans,
                                              Ans[N], mx;
vector<long long> v[N];
string s, ss[N];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  cin >> q;
  while (q--) {
    ans = x = y = o = u = 0;
    e = INF;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) c[i] = b[i] = d[i] = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      c[a[i]] = i;
    }
    for (int i = 1; i <= k; i++) {
      cin >> b[i];
    }
    ans = 1;
    d[0] = d[n + 1] = 1;
    for (int i = k; i >= 1; i--) {
      d[c[b[i]]] = 1;
      (ans *= (2 - d[c[b[i]] + 1] - d[c[b[i]] - 1])) %= MOD;
    }
    cout << ans << endl;
  }
}
