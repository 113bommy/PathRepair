#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long maxn = 3e6;
const long long mod = 1e9 + 7;
const long double PI = acos((long double)-1);
long long pw(long long a, long long b, long long md = mod) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = (a * res) % md;
    }
    a = (a * a) % md;
    b >>= 1;
  }
  return (res);
}
int q, n, k;
string a, b, s;
char ans[30];
int use[30];
bool chk(int pos = 0, int d = 1, int u = 1) {
  if (pos >= n or (!d and !u)) return (1);
  int c = s[pos] - 'a';
  if (ans[c]) {
    if (d and ans[c] < a[pos]) return (0);
    if (u and ans[c] > b[pos]) return (0);
    return (chk(pos + 1, d and (ans[c] == a[pos]), u and (ans[c] == b[pos])));
  }
  for (int i = 0; i < k; i++) {
    if (use[i]) continue;
    if ((d and 'a' + i < a[pos]) or (u and 'a' + i > b[pos])) continue;
    use[i] = 1;
    ans[c] = 'a' + i;
    if (chk(pos + 1, d and (ans[c] == a[pos]), u and (ans[c] == b[pos])))
      return (1);
    use[i] = ans[c] = 0;
  }
  return (0);
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> q;
  while (q--) {
    cin >> k;
    cin >> s >> a >> b;
    n = s.size();
    memset(use, 0, sizeof use);
    memset(ans, 0, sizeof ans);
    int pos = 0;
    while (pos < n and a[pos] == b[pos]) pos++;
    for (int i = 0; i < pos; i++) {
      int c = s[i] - 'a';
      if (!ans[c]) {
        if (use[a[i] - 'a']) break;
        ans[c] = a[i];
        use[a[i] - 'a'] = 1;
        if (ans[c] != a[i]) break;
      }
    }
    if (!chk()) {
      cout << "NO" << '\n';
      continue;
    }
    int cur = 0;
    for (int i = 0; i < k; i++) {
      if (!ans[i]) {
        while (use[cur]) cur++;
        ans[i] = cur + 'a';
        cur++;
      }
    }
    cout << "YES" << '\n';
    for (int i = 0; i < k; i++) cout << ans[i];
    cout << '\n';
  }
  return (0);
}
