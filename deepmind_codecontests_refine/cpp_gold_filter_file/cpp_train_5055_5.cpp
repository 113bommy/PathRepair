#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 50, INF = 1e18;
long long n, segz[4 * N], segf[4 * N], lazyz[4 * N], lazyf[4 * N], a[N], b[N],
    q;
void shift(long long id) {
  if (lazyz[id] == 0 && lazyf[id] == 0) return;
  lazyf[id * 2] += lazyf[id];
  lazyf[id * 2 + 1] += lazyf[id];
  lazyz[id * 2] += lazyz[id];
  lazyz[id * 2 + 1] += lazyz[id];
  segf[id * 2] += lazyf[id];
  segf[id * 2 + 1] += lazyf[id];
  segz[id * 2] += lazyz[id];
  segz[id * 2 + 1] += lazyz[id];
  lazyf[id] = 0;
  lazyz[id] = 0;
  return;
}
void odd(long long ql, long long qr, long long val, long long l = 1,
         long long r = n + 1, long long id = 1) {
  if (ql >= r || qr <= l) return;
  if (ql <= l && qr >= r) {
    segf[id] += val;
    lazyf[id] += val;
    return;
  }
  shift(id);
  long long mid = (l + r) / 2;
  odd(ql, qr, val, l, mid, id * 2);
  odd(ql, qr, val, mid, r, id * 2 + 1);
  segf[id] = min(segf[id * 2], segf[id * 2 + 1]);
  return;
}
void even(long long ql, long long qr, long long val, long long l = 1,
          long long r = n + 1, long long id = 1) {
  if (ql >= r || qr <= l) return;
  if (ql <= l && qr >= r) {
    segz[id] += val;
    lazyz[id] += val;
    return;
  }
  shift(id);
  long long mid = (l + r) / 2;
  even(ql, qr, val, l, mid, id * 2);
  even(ql, qr, val, mid, r, id * 2 + 1);
  segz[id] = min(segz[id * 2], segz[id * 2 + 1]);
  return;
}
long long getz(long long ql, long long qr, long long l = 1, long long r = n + 1,
               long long id = 1) {
  if (ql >= r || qr <= l) return INF;
  if (ql <= l && qr >= r) return segz[id];
  shift(id);
  long long mid = (l + r) / 2;
  long long ans = getz(ql, qr, l, mid, id * 2);
  ans = min(ans, getz(ql, qr, mid, r, id * 2 + 1));
  segz[id] = min(segz[id * 2], segz[id * 2 + 1]);
  return ans;
}
long long getf(long long ql, long long qr, long long l = 1, long long r = n + 1,
               long long id = 1) {
  if (ql >= r || qr <= l) return INF;
  if (ql <= l && qr >= r) return segf[id];
  shift(id);
  long long mid = (l + r) / 2;
  long long ans = getf(ql, qr, l, mid, id * 2);
  ans = min(ans, getf(ql, qr, mid, r, id * 2 + 1));
  segf[id] = min(segf[id * 2], segf[id * 2 + 1]);
  return ans;
}
bool check(long long l, long long r) {
  long long mn1 = getf(l, r + 1), mn2 = getz(l, r + 1);
  long long x, last;
  if ((l - 1) % 2 == 1)
    x = getf(l - 1, l);
  else
    x = getz(l - 1, l);
  if (l - 1 == 0) x = 0;
  if (r % 2 == 1)
    last = getf(r, r + 1);
  else
    last = getz(r, r + 1);
  if (l % 2 == 1)
    mn1 += x, mn2 -= x;
  else
    mn2 += x, mn1 -= x;
  if (r % 2 == l % 2)
    last += x;
  else
    last -= x;
  if ((r - l + 1) % 2 == 0 && last != 0) return false;
  if ((r - l + 1) % 2 == 1 && last != 1) return false;
  if (l % 2 == 1 && (mn2 < 0 || mn1 < 1)) return false;
  if (l % 2 == 0 && (mn2 < 1 || mn1 < 0)) return false;
  return true;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  for (long long i = 1; i <= n; i++) {
    b[i] = a[i] - b[i - 1];
    if (i % 2 == 1) {
      odd(i, i + 1, b[i]);
      even(i, i + 1, INF);
    }
    if (i % 2 == 0) {
      even(i, i + 1, b[i]);
      odd(i, i + 1, INF);
    }
  }
  cin >> q;
  for (long long i = 0, t, l, r, k; i < q; i++) {
    cin >> t >> l >> r;
    l++, r++;
    if (t == 1) {
      cin >> k;
      if (l % 2 == 1)
        odd(l, r + 1, k);
      else
        even(l, r + 1, k);
      if (r % 2 != l % 2) continue;
      if ((r + 1) % 2 == 1) {
        odd(r + 1, n + 1, -1ll * k);
        even(r + 1, n + 1, k);
      } else {
        odd(r + 1, n + 1, k);
        even(r + 1, n + 1, -1ll * k);
      }
    } else
      cout << check(l, r) << '\n';
  }
  return 0;
}
