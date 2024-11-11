#include <bits/stdc++.h>
using namespace std;
long long int seg[1000011];
long long int lazy[1000011];
long long int ap[200011];
void update(long long int star, long long int en, long long int low,
            long long int high, long long int pos) {
  if (low > high) return;
  if (lazy[pos] != 0) {
    seg[pos] = lazy[pos];
    lazy[2 * pos + 1] += lazy[pos];
    lazy[2 * pos + 2] += lazy[pos];
    lazy[pos] = 0;
  }
  if (low > en || high < star) return;
  if (low >= star && high <= en) {
    seg[pos] = -1;
    if (low != high) {
      lazy[2 * pos + 1] += -1;
      lazy[2 * pos + 2] += -1;
    }
    return;
  }
  long long int mid = (low + high) >> 1;
  update(star, en, low, mid, 2 * pos + 1);
  update(star, en, mid + 1, high, 2 * pos + 2);
  seg[pos] = (seg[2 * pos + 1] + seg[2 * pos + 2]);
}
long long int maxq(long long int qlow, long long int qhigh, long long int low,
                   long long int high, long long int pos) {
  if (low > high) return 0;
  if (lazy[pos] != 0) {
    seg[pos] = lazy[pos];
    lazy[2 * pos + 1] += lazy[pos];
    lazy[2 * pos + 2] += lazy[pos];
    lazy[pos] = 0;
  }
  if (qlow > high || qhigh < low) return 0;
  if (low >= qlow && high <= qhigh) {
    return seg[pos];
  }
  long long int mid = (low + high) / 2;
  return maxq(qlow, qhigh, low, mid, 2 * pos + 1) +
         maxq(qlow, qhigh, mid + 1, high, 2 * pos + 2);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t, i, j, l, m, n, r, q, k, d, x;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> l;
    ap[l] = i;
  }
  long long int ans[n + 11];
  for (i = 0; i < n; i++) {
    cin >> ans[i];
  }
  for (i = 0; i < n; i++) {
    long long int p = ap[ans[i]];
    long long int pp = maxq(p, p, 0, n - 1, 0);
    if (pp >= 0) {
      long long int low = 0;
      long long int high = p;
      long long int ans1 = 100000000;
      while (low <= high) {
        long long int mid = (low + high) >> 1;
        long long int pq = maxq(mid, mid, 0, n - 1, 0);
        if (pq == -1) {
          low = mid + 1;
        } else {
          ans1 = min(ans1, mid);
          high = mid - 1;
        }
      }
      cout << (p - ans1 + 1) << " ";
      update(0, p, 0, n - 1, 0);
    } else {
      cout << 0 << " ";
    }
  }
  return 0;
}
