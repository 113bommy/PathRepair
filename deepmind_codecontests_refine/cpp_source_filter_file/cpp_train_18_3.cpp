#include <bits/stdc++.h>
using namespace std;
const int INF = 1061109567;
const int MAXN = 201010;
int n, median;
int v[MAXN];
int ind[MAXN];
long long st[4 * MAXN];
long long adjust[MAXN];
long long inversions[MAXN];
priority_queue<int> maxheap;
priority_queue<int, vector<int>, greater<int> > minheap;
void update(int nd, int l, int r, int pos, int x) {
  if (l == r) {
    st[nd] = x;
    return;
  }
  if (pos < l || pos > r) return;
  int mid = (l + r) >> 1;
  int nxt = nd << 1;
  if (pos <= mid) update(nxt, l, mid, pos, x);
  if (pos > mid) update(nxt + 1, mid + 1, r, pos, x);
  st[nd] = st[nxt] + st[nxt + 1];
}
int query(int nd, int l, int r, int lq, int rq) {
  if (r < lq || rq < l) return 0;
  if (lq <= l && r <= rq) return st[nd];
  int mid = (l + r) >> 1;
  int nxt = nd << 1;
  return query(nxt, l, mid, lq, rq) + query(nxt + 1, mid + 1, r, lq, rq);
}
long long gather(int k, int med_pos) {
  long long rh = k - (k / 2);
  long long lh = k - rh;
  long long r_tar_sum = ((med_pos + (med_pos + rh - 1)) * rh) / 2;
  long long l_tar_sum = ((med_pos - 1 + (med_pos - lh)) * lh) / 2;
  long long r_pos_sum = query(1, 0, n, med_pos, n);
  long long l_pos_sum = query(1, 0, n, 0, max(0, med_pos - 1));
  long long ret_val = (l_tar_sum - l_pos_sum) + (r_pos_sum - r_tar_sum);
  return ret_val;
}
void reset_seg_tree() {
  for (int i = 1; i <= n; i++) update(1, 0, n, i, 0);
  return;
}
void heap_insert(int x) {
  if (maxheap.size() > minheap.size()) {
    if (x < median) {
      minheap.push(maxheap.top());
      maxheap.pop();
      maxheap.push(x);
    } else {
      minheap.push(x);
    }
    median = minheap.top();
  } else if (maxheap.size() == minheap.size()) {
    if (x < median) {
      maxheap.push(x);
      median = maxheap.top();
    } else {
      minheap.push(x);
      median = minheap.top();
    }
  } else {
    if (x > median) {
      maxheap.push(minheap.top());
      minheap.pop();
      minheap.push(x);
    } else {
      maxheap.push(x);
    }
    median = minheap.top();
  }
  return;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    ind[v[i]] = i;
  }
  for (int k = 1; k <= n; k++) {
    heap_insert(ind[k]);
    update(1, 0, n, ind[k], ind[k]);
    adjust[k] = gather(k, median);
  }
  reset_seg_tree();
  inversions[0] = 0;
  for (int k = 1; k <= n; k++) {
    inversions[k] = inversions[k - 1] + query(1, 0, n, ind[k] + 1, n - 1);
    update(1, 0, n, ind[k], 1);
  }
  for (int i = 1; i <= n; i++)
    cout << (inversions[i] + adjust[i]) << " \n"[i == n];
  return 0;
}
