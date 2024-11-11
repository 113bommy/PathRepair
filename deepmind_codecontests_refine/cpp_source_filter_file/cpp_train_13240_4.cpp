#include <bits/stdc++.h>
using namespace std;
long long n, ar[2 * 200005], tr[8 * 200005 + 555], dr[2 * 200005 + 555],
    up[2 * 200005 + 555];
long long query(long long, long long, long long, long long, long long),
    q1(long long, long long, long long, long long, long long, long long),
    q2(long long, long long, long long, long long, long long, long long),
    qq(long long, long long, long long, long long, long long);
void build(long long, long long, long long),
    func(long long, long long, long long),
    upd(long long, long long, long long, long long, long long, long long);
int main() {
  scanf("%lld", &n);
  for (int i = 1; i < n + 1; i++) {
    scanf("%lld", &ar[i]);
    ar[n + i] = ar[i];
  }
  build(0, 1, 2 * n);
  func(1, n, 1);
  long long ans = qq(0, 1, 2 * n, 1, n), pos = 1;
  for (int i = 1; i < n + 1; i++) {
    if (ar[i + n] == 1) {
      upd(0, 1, 2 * n, i + n, i + n, 1);
      continue;
    }
    long long temp = qq(0, 1, 2 * n, i, i + n - 1);
    if (ans > temp) ans = temp, pos = i;
    long long x = q1(0, 1, 2 * n, i + 1, i + n - 1, ar[i]);
    upd(0, 1, 2 * n, i, x - 1, -1);
    x = q2(0, 1, 2 * n, i + 1, i + n - 1, ar[i]);
    upd(0, 1, 2 * n, x + 1, i + n - 1, 1);
    x = qq(0, 1, 2 * n, x, x);
    upd(0, 1, 2 * n, i + n, i + n, x + 1);
  }
  cout << ans << " " << pos - 1;
}
void func(long long l, long long r, long long depth) {
  if (l > r) return;
  long long min_ = query(0, 1, 2 * n, l, r);
  upd(0, 1, 2 * n, min_, min_, depth);
  func(l, min_ - 1, depth + 1);
  func(min_ + 1, r, depth + 1);
}
void upd(long long idx, long long l, long long r, long long low, long long high,
         long long val) {
  if (up[idx]) {
    dr[idx] += up[idx];
    if (l != r) {
      up[2 * idx + 1] += up[idx];
      up[2 * idx + 2] += up[idx];
    }
    up[idx] = 0;
  }
  if (r < low || l > high) return;
  if (low <= l && r <= high) {
    dr[idx] += val;
    if (l != r) {
      up[2 * idx + 1] += val;
      up[2 * idx + 2] += val;
    }
    return;
  }
  long long mid = (l + r) / 2;
  upd(2 * idx + 1, l, mid, low, high, val);
  upd(2 * idx + 2, mid + 1, r, low, high, val);
  dr[idx] = max(dr[2 * idx + 1], dr[2 * idx + 2]);
}
long long qq(long long idx, long long l, long long r, long long low,
             long long high) {
  if (up[idx]) {
    dr[idx] += up[idx];
    if (l != r) {
      up[2 * idx + 1] += up[idx];
      up[2 * idx + 2] += up[idx];
    }
    up[idx] = 0;
  }
  if (high < l || low > r) return 0;
  if (low <= l && r <= high) return dr[idx];
  long long mid = (l + r) / 2;
  long long a = qq(2 * idx + 1, l, mid, low, high),
            b = qq(2 * idx + 2, mid + 1, r, low, high);
  return max(a, b);
}
long long query(long long idx, long long l, long long r, long long low,
                long long high) {
  if (r < low || high < l) return 0;
  if (l == r) return l;
  long long mid = (l + r) / 2;
  if (low <= l && r <= high) {
    if (tr[2 * idx + 1] < tr[2 * idx + 2])
      return query(2 * idx + 1, l, mid, low, high);
    return query(2 * idx + 2, mid + 1, r, low, high);
  }
  long long a = query(2 * idx + 1, l, mid, low, high);
  long long b = query(2 * idx + 2, mid + 1, r, low, high);
  if (!(a * b)) return a + b;
  return (ar[a] < ar[b] ? a : b);
}
void build(long long idx, long long l, long long r) {
  if (l == r) {
    tr[idx] = ar[l];
    return;
  }
  long long mid = (l + r) / 2;
  build(2 * idx + 1, l, mid);
  build(2 * idx + 2, mid + 1, r);
  tr[idx] = min(tr[2 * idx + 1], tr[2 * idx + 2]);
}
long long q1(long long idx, long long l, long long r, long long low,
             long long high, long long val) {
  if (low > r || high < l) return -1;
  if (tr[idx] > val) return -1;
  if (l == r) return l;
  long long mid = (l + r) / 2;
  long long a = q1(2 * idx + 1, l, mid, low, high, val);
  if (a == -1) return q1(2 * idx + 2, mid + 1, r, low, high, val);
  return a;
}
long long q2(long long idx, long long l, long long r, long long low,
             long long high, long long val) {
  if (low > r || high < l) return -1;
  if (tr[idx] > val) return -1;
  if (l == r) return l;
  long long mid = (l + r) / 2;
  long long a = q2(2 * idx + 2, mid + 1, r, low, high, val);
  if (a == -1) return q2(2 * idx + 1, l, mid, low, high, val);
  return a;
}
