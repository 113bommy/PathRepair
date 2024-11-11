#include <bits/stdc++.h>
using namespace std;
long long n, l, r, a[1000005], final = 0;
vector<long long> seg(4 * 1000005);
vector<long long> seg1(4 * 1000005);
void build(long long cur, long long st, long long end) {
  if (st == end) {
    seg[cur] = st;
    return;
  }
  long long mid = (st + end) >> 1;
  build(2 * cur, st, mid);
  build(2 * cur + 1, mid + 1, end);
  if (a[seg[2 * cur]] < a[seg[2 * cur + 1]])
    seg[cur] = seg[2 * cur + 1];
  else
    seg[cur] = seg[2 * cur];
}
long long query(long long cur, long long st, long long end, long long l,
                long long r) {
  if (l <= st && r >= end) return seg[cur];
  if (r < st || l > end) return 0;
  long long mid = (st + end) >> 1;
  long long a1 = query(2 * cur, st, mid, l, r);
  long long a2 = query(2 * cur + 1, mid + 1, end, l, r);
  if (a[a1] > a[a2]) return a1;
  return a2;
}
void build1(long long cur, long long st, long long end) {
  if (st == end) {
    seg1[cur] = st;
    return;
  }
  long long mid = (st + end) >> 1;
  build1(2 * cur, st, mid);
  build1(2 * cur + 1, mid + 1, end);
  if (a[seg1[2 * cur]] < a[seg1[2 * cur + 1]])
    seg1[cur] = seg1[2 * cur];
  else
    seg1[cur] = seg1[2 * cur];
}
long long query1(long long cur, long long st, long long end, long long l,
                 long long r) {
  if (l <= st && r >= end) return seg1[cur];
  if (r < st || l > end) return n + 1;
  long long mid = (st + end) >> 1;
  long long a1 = query1(2 * cur, st, mid, l, r);
  long long a2 = query1(2 * cur + 1, mid + 1, end, l, r);
  if (a[a1] < a[a2]) return a1;
  return a2;
}
long long f(long long aa, long long b) {
  if (aa > b) return 0;
  if (aa == b) return a[aa];
  long long mx = query(1, 1, n, aa, b);
  long long sum =
      (mx - aa + 1) * (b - mx + 1) * a[mx] + f(aa, mx - 1) + f(mx + 1, b);
  return sum;
}
long long f1(long long aa, long long b) {
  if (aa > b || aa > n || b <= 0) return 0;
  if (aa == b) return a[aa];
  long long mn = query1(1, 1, n, aa, b);
  long long sum =
      (mn - aa + 1) * (b - mn + 1) * a[mn] + f1(aa, mn - 1) + f1(mn + 1, b);
  return sum;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  a[0] = 0, a[n + 1] = 1000000007;
  for (int i = 1; i <= n; i++) cin >> a[i];
  build(1, 1, n);
  build1(1, 1, n);
  long long ans = f(1, n) - f1(1, n);
  cout << ans;
  return 0;
}
