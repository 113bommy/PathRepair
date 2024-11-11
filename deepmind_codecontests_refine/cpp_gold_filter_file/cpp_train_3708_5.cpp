#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e5 + 5;
const long long int INF = 9e18;
const long long int mod = 1e9 + 7;
long long int n, p, q, r, a[N], seg[4 * N], segx[4 * N];
void build(long long int low, long long int high, long long int pos) {
  if (low == high) {
    seg[pos] = a[low];
    return;
  }
  long long int mid = (low + high) / 2;
  build(low, mid, 2 * pos + 1);
  build(mid + 1, high, 2 * pos + 2);
  seg[pos] = min(seg[2 * pos + 1], seg[2 * pos + 2]);
}
void buildx(long long int low, long long int high, long long int pos) {
  if (low == high) {
    segx[pos] = a[low];
    return;
  }
  long long int mid = (low + high) / 2;
  buildx(low, mid, 2 * pos + 1);
  buildx(mid + 1, high, 2 * pos + 2);
  segx[pos] = max(segx[2 * pos + 1], segx[2 * pos + 2]);
}
long long int query(long long int low, long long int high, long long int qlow,
                    long long int qhigh, long long int pos) {
  if (qlow > high || qhigh < low) return INF;
  if (qlow <= low && qhigh >= high) return seg[pos];
  long long int mid = (low + high) / 2;
  return min(query(low, mid, qlow, qhigh, 2 * pos + 1),
             query(mid + 1, high, qlow, qhigh, 2 * pos + 2));
}
long long int queryx(long long int low, long long int high, long long int qlow,
                     long long int qhigh, long long int pos) {
  if (qlow > high || qhigh < low) return -INF;
  if (qlow <= low && qhigh >= high) return segx[pos];
  long long int mid = (low + high) / 2;
  return max(queryx(low, mid, qlow, qhigh, 2 * pos + 1),
             queryx(mid + 1, high, qlow, qhigh, 2 * pos + 2));
}
int main() {
  long long int omaxi = -INF;
  cin >> n >> p >> q >> r;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  build(0, n - 1, 0);
  buildx(0, n - 1, 0);
  for (long long int i = 0; i < n; i++) {
    long long int x = q * a[i];
    if (p < 0) {
      long long int mini = query(0, n - 1, 0, i, 0);
      x += (p * mini);
    } else {
      long long int maxi = queryx(0, n - 1, 0, i, 0);
      x += (p * maxi);
    }
    if (r < 0) {
      long long int mini = query(0, n - 1, i, n - 1, 0);
      x += (r * mini);
    } else {
      long long int maxi = queryx(0, n - 1, i, n - 1, 0);
      x += (r * maxi);
    }
    omaxi = max(omaxi, x);
  }
  cout << omaxi << endl;
}
