#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline long long lin() {
  long long x;
  scanf("%lld", &x);
  return x;
}
const int maxn = 3e5 + 10;
int l[maxn], r[maxn], n, k, Root[maxn * 20], L[20 * maxn], R[20 * maxn],
    id[maxn];
int Rs[maxn];
int tot[20 * maxn];
int what;
inline int where(int *arr, long long val) {
  return (int)(lower_bound(arr, arr + n, val) - arr);
}
inline int get(int ql, int qr, int p = 0, int l = 0, int r = n - 1) {
  if (l > qr || r < ql || ql > qr) return 0;
  if (l >= ql && r <= qr) return tot[p];
  int mid = (l + r) >> 1;
  return get(ql, qr, L[p], l, mid) + get(ql, qr, R[p], mid + 1, r);
}
inline bool can(long long lim) {
  what = -1;
  for (int i = 0; i < n; i++) {
    int tot = get(where(Rs, l[i] + lim - 1), n - 1, Root[i]);
    if (tot >= k) {
      what = i;
      return true;
    }
  }
  return false;
}
int q[maxn];
int t;
int cnt = 1;
inline void build(int p = 0, int l = 0, int r = n - 1) {
  if (l == r) return;
  L[p] = cnt++, R[p] = cnt++;
  int mid = (l + r) >> 1;
  build(L[p], l, mid), build(R[p], mid + 1, r);
}
inline int update(int qx, int p = 0, int l = 0, int r = n - 1) {
  if (l > qx || r < qx) return p;
  int ret = cnt++;
  tot[ret] = tot[p] + 1;
  if (l == r) return ret;
  int mid = (l + r) >> 1;
  L[ret] = update(qx, L[p], l, mid), R[ret] = update(qx, R[p], mid + 1, r);
  return ret;
}
int32_t main() {
  n = in(), k = in();
  for (int i = 0; i < n; i++) l[i] = in(), r[i] = in(), Rs[i] = r[i];
  iota(id, id + n, 0);
  sort(id, id + n, [](const int &a, const int &b) {
    return make_pair(l[a], r[a]) < make_pair(l[b], r[b]);
  });
  sort(Rs, Rs + n);
  build();
  Root[0] = update(where(Rs, r[id[0]]), Root[0]);
  for (int i = 1; i < n; i++)
    Root[i] = update(where(Rs, r[id[i]]), Root[i - 1]);
  assert(cnt < 20 * maxn);
  long long low = 0, hi = 2e9 + 5;
  while (low + 1 < hi) {
    long long mid = 1LL * (low + hi) / 2;
    if (can(mid))
      low = mid;
    else
      hi = mid;
  }
  printf("%lld\n", low);
  can(low);
  if (low) {
    for (int i = 0; i < n; i++)
      if (l[i] <= l[id[what]] && r[i] >= l[id[what]] + low - 1) q[t++] = i + 1;
  } else
    for (int i = 0; i < k; i++) q[t++] = i + 1;
  for (int i = 0; i < min(t, k); i++) printf("%d ", q[i]);
  cout << "\n";
}
