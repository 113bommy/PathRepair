#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
bool Check2(int day_cnt, const vector<ll> &a, ll m) {
  int n = a.size();
  for (int i = 0; i < n; i++) {
    ll cur = a[i];
    if (i > 0) {
      cur -= a[i - 1];
    }
    int d = i / day_cnt;
    m -= max(0, (int)cur - d);
    if (m <= 0) {
      return true;
    }
  }
  return false;
}
bool Check(int day_cnt, const vector<ll> &a, ll m) {
  int n = a.size();
  for (int i = 0; i < n; i++) {
    ll il = 1LL * i * day_cnt;
    if (il >= n) {
      break;
    }
    if (a[il] - i <= 0) {
      break;
    }
    int ir = il + day_cnt - 1;
    ir = min(ir, n - 1);
    if (ir == n - 1 || a[ir] - i <= 0) {
      while (a[ir] - i <= 0) {
        ir--;
      }
      ll sumlr = a[ir];
      if (il > 0) {
        sumlr -= a[il - 1];
      }
      sumlr -= i * (ir - il + 1);
      m -= sumlr;
      break;
    } else {
      ll sumlr = a[ir];
      if (il > 0) {
        sumlr -= a[il - 1];
      }
      sumlr -= i * (ir - il + 1);
      m -= sumlr;
    }
    if (m <= 0) {
      return true;
    }
  }
  return m <= 0;
}
int main(int argc, char **argv) {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%" SCNd64, &a[i]);
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  for (int i = 1; i < n; i++) {
    a[i] += a[i - 1];
  }
  int l = 1, r = n;
  int res = -1;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (Check(mid, a, m)) {
      res = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  printf("%d\n", res);
  return 0;
}
