#include <bits/stdc++.h>
using namespace std;
long long int n, a[100005], b[100005], c[100005], l[100005], r[100005];
long long int tree[400005], lazy[400005];
void lazify(long long int s, long long int e, long long int i) {
  if (lazy[i]) {
    tree[i] += lazy[i];
    if (s != e) {
      lazy[2 * i] += lazy[i];
      lazy[2 * i + 1] += lazy[i];
    }
    lazy[i] = 0;
  }
}
long long int qur(long long int l, long long int r, long long int s,
                  long long int e, long long int i) {
  if (s > r || e < l || l > r) return -1e18;
  lazify(s, e, i);
  if (s >= l && e <= r) return tree[i];
  long long int mid = (s + e) >> 1;
  return max(qur(l, r, s, mid, 2 * i), qur(l, r, mid + 1, e, 2 * i + 1));
}
void upd(long long int l, long long int r, long long int s, long long int e,
         long long int i) {
  if (r == 0) return;
  lazify(s, e, i);
  if (s > r || e < l) return;
  if (s >= l && e <= r) {
    lazy[i]++;
    lazify(s, e, i);
    return;
  }
  long long int mid = (e + s) >> 1;
  upd(l, r, s, mid, 2 * i);
  upd(l, r, mid + 1, e, 2 * i + 1);
  tree[i] = max(tree[2 * i + 1], tree[2 * i]);
}
bool check(long long int x) {
  memset(b, 0, sizeof b);
  memset(c, 0, sizeof c);
  memset(tree, 0, sizeof tree);
  memset(lazy, 0, sizeof lazy);
  for (long long int i = 1; i <= n; i++) {
    r[i] = 0, l[i] = 0;
    long long int y = min(i - 1, x) - a[i];
    if (y < 0) continue;
    r[i] = min(n, i + y);
    l[i] = max(1ll, i - y);
    b[min(n + 1, i + y + 1)] += -1;
    b[max(1ll, i - y)] += 1;
  }
  long long int d = 0;
  for (int i = 1; i <= n; i++) {
    d += b[i];
    b[i] = d;
  }
  upd(l[n], r[n], 1, n, 1);
  for (int i = n - 1; i >= 1; i--) {
    long long int z = max(0ll, i - a[i]);
    long long int k = max(-1ll, x - a[i]);
    long long int y = max(qur(max(1ll, i - k), max(1ll, i - z), 1, n, 1),
                          qur(min(n, i + z), min(n, i + k), 1, n, 1));
    if (k < z) y = -1;
    if (y > 0) return 1;
    upd(l[i], r[i], 1, n, 1);
  }
  return 0;
}
long long int binsearch() {
  long long int l = 1, r = 1000000;
  long long int mid = (l + r) >> 1;
  if (!check(1000000)) return -1;
  while (r - l > 1) {
    if (check(mid))
      r = mid;
    else
      l = mid;
    mid = (l + r) >> 1;
  }
  while (!check(mid)) mid++;
  return mid;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cout << binsearch() << '\n';
  return 0;
}
