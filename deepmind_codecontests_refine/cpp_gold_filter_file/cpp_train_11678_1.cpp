#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int a[N];
long long sum[N];
struct seg {
  long long st[N * 4], laz[N * 4];
  void ini(int, int, int);
  void up(int), down(int);
  void update(int, int, int, int, long long);
  void update(int, int, int, int, int, long long);
  long long qe(int, int, int, int, int);
} st[10];
void init();
void work();
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  work();
  return 0;
}
void work() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) cin >> a[i], sum[i] = sum[i - 1] + a[i];
  long long ans = 0;
  for (int i = 0; i < m; i++) st[i].ini(1, n, 1);
  for (int i = 1; i <= n; i++) {
    ans = max(ans, sum[i] - 1LL * k * ((i + m - 1) / m));
    if (i > m) {
      ans = max(ans, sum[i] - (st[i % m].qe(1, i / m, 1, n, 1)));
    }
    for (int j = 0; j < m; j++)
      if (i % m != j) {
        if (i > (j == 0 ? m : j)) {
          ans = max(ans, sum[i] - (st[j].qe(1, i / m + 1, 1, n, 1)));
        }
      }
    st[i % m].update(i / m + 1, 1, n, 1, sum[i]);
    st[i % m].update(1, i / m + 1, 1, n, 1, k);
  }
  cout << ans << endl;
}
long long seg::qe(int l, int r, int s, int e, int i) {
  if (l <= s && e <= r) return st[i];
  down(i);
  int mid = (s + e) / 2;
  long long re = 1e18;
  if (l <= mid) re = min(re, qe(l, r, s, mid, i << 1));
  if (mid < r) re = min(re, qe(l, r, mid + 1, e, i << 1 | 1));
  up(i);
  return re;
}
void seg::update(int index, int s, int e, int i, long long k) {
  if (s == e) {
    st[i] = k;
    return;
  }
  down(i);
  int mid = (s + e) / 2;
  if (index <= mid)
    update(index, s, mid, i << 1, k);
  else
    update(index, mid + 1, e, i << 1 | 1, k);
  up(i);
}
void seg::update(int l, int r, int s, int e, int i, long long k) {
  if (l <= s && e <= r) {
    st[i] += k, laz[i] += k;
    return;
  }
  down(i);
  int mid = (s + e) / 2;
  if (l <= mid) update(l, r, s, mid, i << 1, k);
  if (mid < r) update(l, r, mid + 1, e, i << 1 | 1, k);
  up(i);
}
void seg::ini(int s, int e, int i) {
  st[i] = 1e15;
  if (s == e) return;
  int mid = (s + e) / 2;
  ini(s, mid, i << 1), ini(mid + 1, e, i << 1 | 1);
}
void seg::down(int i) {
  if (!laz[i]) return;
  laz[i << 1] += laz[i], laz[i << 1 | 1] += laz[i];
  st[i << 1] += laz[i], st[i << 1 | 1] += laz[i];
  laz[i] = 0;
}
void seg::up(int i) { st[i] = min(st[i << 1], st[i << 1 | 1]); }
