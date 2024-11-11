#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7, maxn = 2e5 + 20;
long long int n, k, m, x, y, q, ans, lazzy[maxn << 2], a[maxn], ps[maxn],
    b[maxn];
long long int cnt[maxn << 2];
void put(long long int val, long long int id) {
  lazzy[id] += val;
  cnt[id] += val;
}
void shift(long long int l, long long int r, long long int id) {
  if (r - l > 1 && lazzy[id] != 0) {
    long long int mid = (l + r) >> 1;
    put(lazzy[id], id << 1);
    put(lazzy[id], id << 1 | 1);
  }
  lazzy[id] = 0;
}
void upd(long long int s, long long int e, long long int val,
         long long int id = 1, long long int l = 0, long long int r = n) {
  if (s >= r || e <= l) return;
  if (s <= l && r <= e) {
    put(val, id);
    return;
  }
  shift(l, r, id);
  long long int mid = (l + r) >> 1;
  upd(s, e, val, id << 1, l, mid);
  upd(s, e, val, id << 1 | 1, mid, r);
  cnt[id] = min(cnt[2 * id], cnt[2 * id + 1]);
}
long long int get(long long int s, long long int e, long long int id = 1,
                  long long int l = 0, long long int r = n) {
  if (r <= s || e <= l || cnt[id] > 0) return -1;
  if (r - l < 2) {
    if (cnt[id] < 0) return -1;
    return l + 1;
  }
  shift(l, r, id);
  long long int mid = (l + r) >> 1;
  long long int w = get(s, e, id << 1, l, mid);
  if (w == -1) w = get(s, e, id << 1 | 1, mid, r);
  return w;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    upd(i, i + 1, ans - a[i]);
    ans += a[i];
  }
  for (long long int i = 0; i < q; i++) {
    cin >> k >> x;
    k--;
    upd(k + 1, n, x - a[k]);
    upd(k, k + 1, a[k] - x);
    a[k] = x;
    cout << get(0, n) << endl;
  }
  return 0;
}
