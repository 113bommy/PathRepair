#include <bits/stdc++.h>
using namespace std;
const long long N = 200000 + 7;
const long long INF = (long long)1e18;
long long l, n, a[N], b[N], ret = INF, rla[N], rlb[N], opt_shift, pr[N],
                            cost[N];
long long type(long long i, long long j) {
  if (i >= j) {
    if (abs(i - j) <= l - abs(i - j))
      return 1;
    else
      return 2;
  } else {
    if (abs(i - j) <= l - abs(i - j))
      return 3;
    else
      return 4;
  }
}
long long fl(long long tp) {
  if (tp == 1) return 0;
  if (tp == 2) return l;
  if (tp == 3) return 0;
  if (tp == 4) return l;
}
long long f1(long long i, long long tp) {
  if (tp == 1) return i;
  if (tp == 2) return -i;
  if (tp == 3) return -i;
  if (tp == 4) return i;
}
long long f2(long long j, long long tp) {
  if (tp == 1) return -j;
  if (tp == 2) return j;
  if (tp == 3) return j;
  if (tp == 4) return -j;
}
void add(long long l, long long r, long long x) {
  assert(l >= 0 && r >= 0);
  if (l <= r) {
    cost[l] += x;
    cost[r + 1] -= x;
  } else {
    cost[l] += x;
    cost[0] += x;
    cost[r + 1] -= x;
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> l >> n;
  vector<pair<long long, long long>> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i].first;
    v[i].second = i + 1;
  }
  sort(v.begin(), v.end());
  for (long long i = 0; i < n; i++) {
    a[i] = v[i].first;
    rla[i] = v[i].second;
  }
  for (long long i = 0; i < n; i++) {
    cin >> v[i].first;
    v[i].second = i + 1;
  }
  sort(v.begin(), v.end());
  for (long long i = 0; i < n; i++) {
    b[i] = v[i].first;
    rlb[i] = v[i].second;
  }
  long long start = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i] > b[n - 1]) {
      start = 0;
    } else {
      while (b[start] < a[i]) {
        start++;
      }
    }
    long long l = 0;
    while (l < n) {
      long long r = l, lo = l + 1, hi = n - 1,
                want = type(a[i], b[(start + l) % n]);
      while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (type(a[i], b[(start + mid) % n]) == want) {
          r = mid;
          lo = mid + 1;
        } else {
          hi = mid - 1;
        }
      }
      long long adding = fl(want) + f1(a[i], want);
      long long first = (n + (start + l) - i) % n,
                last = (n + (start + r) - i) % n;
      add(first, last, adding);
      l = r + 1;
    }
  }
  start = 0;
  for (long long i = 0; i < n; i++) {
    if (b[i] > a[n - 1]) {
      start = 0;
    } else {
      while (a[start] < b[i]) {
        start++;
      }
    }
    long long l = 0;
    while (l < n) {
      long long r = l, lo = l + 1, hi = n - 1,
                want = type(a[(start + l) % n], b[i]);
      while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        if (type(a[(start + mid) % n], b[i]) == want) {
          r = mid;
          lo = mid + 1;
        } else {
          hi = mid - 1;
        }
      }
      long long adding = f2(b[i], want);
      long long first = (n - (start + l) % n + i) % n,
                last = (n - (start + r) % n + i) % n;
      swap(first, last);
      add(first, last, adding);
      l = r + 1;
    }
  }
  for (long long i = 1; i <= n; i++) {
    cost[i] += cost[i - 1];
  }
  for (long long shift = 0; shift < n; shift++) {
    if (cost[shift] < ret) {
      ret = cost[shift];
      opt_shift = shift;
    }
  }
  for (long long i = 0; i < n; i++) {
    long long x = rla[i], y = rlb[(i + opt_shift) % n];
    pr[x] = y;
  }
  cout << ret << "\n";
  for (long long i = 1; i <= n; i++) {
    cout << pr[i] << " ";
  }
  cout << "\n";
}
