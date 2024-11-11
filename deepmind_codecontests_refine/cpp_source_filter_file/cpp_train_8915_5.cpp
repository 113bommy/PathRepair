#include <bits/stdc++.h>
using namespace std;
const long long N = 4e5 + 10;
const long long MOD = 1e9 + 7;
const long long oo = 1e9;
long long n, cnt;
long long a[N], BIT[2][N], f[N][2];
set<long long> st;
map<long long, long long> pos;
void compress() {
  for (long long i = 1; i <= n; ++i) st.insert(a[i]), st.insert(a[i] + 1);
  for (auto it = st.begin(); it != st.end(); ++it) pos[(*it)] = ++cnt;
  for (long long i = 1; i <= n; ++i) a[i] = pos[a[i]];
}
void upd(long long base, long long pos, long long val) {
  for (long long i = pos; i <= cnt; i += (i & -i))
    BIT[base][i] = max(BIT[base][i], val);
}
long long getBIT(long long base, long long pos) {
  long long res = 0;
  for (long long i = pos; i >= 1; i -= (i & -i)) res = max(res, BIT[base][i]);
  return res;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] -= i;
  }
  compress();
  for (long long i = 1; i <= n; ++i) {
    f[i][0] = getBIT(0, a[i]) + 1;
    f[i][1] = max(f[i][1], getBIT(1, a[i] + 1) + 1);
    if (i < n) f[i + 1][1] = max(f[i + 1][1], getBIT(0, a[i + 1] + 1));
    upd(0, a[i], f[i][0]);
    upd(1, a[i] + 1, f[i][1]);
  }
  long long ans = 0;
  for (long long i = 1; i <= n; ++i)
    ans = max(0ll, max(ans, max(f[i][1], f[i][0])));
  cout << max(0ll, (n - ans - 1));
}
