#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, siz = 1e6 + 5;
long long t, n, m, k, a[siz], inp[siz], cnt, co[siz], less_right[siz],
    less_left[siz], tree[siz][2];
pair<long long, long long> p[siz];
long long get(long long ind, long long id) {
  long long ret = 0;
  for (; ind; ind -= ind & -ind) ret += tree[ind][id];
  return ret;
}
void upd(long long id, long long ind, long long val) {
  for (; ind <= cnt; ind += ind & -ind) tree[ind][id] += val;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> p[i].first, p[i].second = i;
  sort(p + 1, p + 1 + n);
  for (long long i = 1; i <= n; i++) {
    a[p[i].second] = ++cnt;
    inp[p[i].second] = p[i].first;
  }
  for (long long i = 1; i <= n; i++) {
    less_left[i] = get(a[i], 0);
    upd(0, a[i], i);
  }
  for (long long i = n; i >= 1; i--) {
    less_right[i] = get(a[i], 1);
    upd(1, a[i], n - i + 1);
  }
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    co[i] = i * (n - i + 1);
    co[i] += less_left[i] * (n - i + 1) + less_right[i] * i;
    co[i] %= mod;
    long long toadd = (co[i] * inp[i]) % mod;
    (ans += toadd) %= mod;
  }
  cout << ans << endl;
}
