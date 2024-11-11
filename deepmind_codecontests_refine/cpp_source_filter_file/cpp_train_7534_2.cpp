#include <bits/stdc++.h>
using namespace std;
long long segmant_tree[500000];
long long lazy[500000];
void update_segmant_tree_range_query(long long q_low, long long q_high,
                                     long long delta, long long low,
                                     long long high, long long pos) {
  if (low > high) return;
  if (lazy[pos] != 0) {
    segmant_tree[pos] = lazy[pos];
    if (low != high) {
      long long mid = (high + low) / 2;
      lazy[2 * pos + 1] = lazy[pos] / (high - low + 1) * (mid - low + 1);
      lazy[2 * pos + 2] = lazy[pos] - lazy[2 * pos + 1];
    }
    lazy[pos] = 0;
  }
  if (q_low > high || q_high < low) return;
  if (q_low <= low && q_high >= high) {
    segmant_tree[pos] = delta * (high - low + 1);
    if (low != high) {
      long long mid = (high + low) / 2;
      lazy[2 * pos + 1] = delta * (mid - low + 1);
      lazy[2 * pos + 2] = delta * (high - low + 1) - lazy[2 * pos + 1];
    }
    return;
  }
  long long mid = (low + high) / 2;
  update_segmant_tree_range_query(q_low, q_high, delta, low, mid, 2 * pos + 1);
  update_segmant_tree_range_query(q_low, q_high, delta, mid + 1, high,
                                  2 * pos + 2);
  segmant_tree[pos] = segmant_tree[2 * pos + 1] + segmant_tree[2 * pos + 2];
}
long long rang_sum_q_lazy(long long q_low, long long q_high, long long low,
                          long long high, long long pos) {
  if (low > high) return 0;
  if (lazy[pos] != 0) {
    segmant_tree[pos] = lazy[pos];
    if (high != low) {
      long long mid = (high + low) / 2;
      lazy[2 * pos + 1] = lazy[pos] / (high - low + 1) * (mid - low + 1);
      lazy[2 * pos + 2] = lazy[pos] - lazy[2 * pos + 1];
    }
    lazy[pos] = 0;
  }
  if (q_low > high || q_high < low) return 0;
  if (q_low <= low && q_high >= high) return segmant_tree[pos];
  long long mid = (low + high) / 2;
  return rang_sum_q_lazy(q_low, q_high, low, mid, 2 * pos + 1) +
         rang_sum_q_lazy(q_low, q_high, mid + 1, high, 2 * pos + 2);
}
long long input1[100009];
long long input2[100009];
struct po {
  long long x, y, k;
};
po input[100009];
int main() {
  ios_base::sync_with_stdio(false);
  long long n, m;
  cin >> n >> m;
  for (long long i = 0; i < n; i++) cin >> input1[i];
  for (long long i = 0; i < n; i++) cin >> input2[i];
  memset(segmant_tree, 0, sizeof(segmant_tree));
  for (long long i = 1; i <= m; i++) {
    long long t;
    cin >> t;
    if (t == 1) {
      long long x, y, k;
      cin >> x >> y >> k;
      x--;
      y--;
      po ppp;
      ppp.x = x;
      ppp.y = y;
      ppp.k = k;
      input[i] = ppp;
      update_segmant_tree_range_query(y, y + k, i, 0, n - 1, 0);
    } else {
      long long pos;
      cin >> pos;
      pos--;
      long long q = rang_sum_q_lazy(pos, pos, 0, n - 1, 0);
      if (q == 0)
        cout << input2[pos] << endl;
      else
        cout << input1[input[q].x + pos - input[q].y] << endl;
    }
  }
  return 0;
}
