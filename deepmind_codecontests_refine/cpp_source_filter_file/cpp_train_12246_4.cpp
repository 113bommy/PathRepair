#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int INF = 1e6 + 5;
int n, k;
int a[N];
struct seg_tree {
  int val[4 * N];
  int mini(int x, int y) {
    if (a[x] < a[y]) return x;
    return y;
  }
  int query(int pos, int low, int high, int l, int r) {
    if (l > high || r < low) return 0;
    if (l <= low && r >= high) return val[pos];
    int mid = (low + high) / 2;
    return mini(query(pos * 2, low, mid, l, r),
                query(pos * 2 + 1, mid + 1, high, l, r));
  }
  void update(int pos, int low, int high, int l, int r, int d) {
    if (l > high || r < low) return;
    if (l <= low && r >= high) {
      a[low] = d;
      return;
    }
    int mid = (low + high) / 2;
    update(pos * 2, low, mid, l, r, d);
    update(pos * 2 + 1, mid + 1, high, l, r, d);
    val[pos] = mini(val[pos * 2], val[pos * 2 + 1]);
  }
  void build(int pos, int low, int high, int arr[]) {
    if (low == high) {
      val[pos] = low;
      return;
    }
    int mid = (low + high) / 2;
    build(pos * 2, low, mid, arr);
    build(pos * 2 + 1, mid + 1, high, arr);
    val[pos] = mini(val[pos * 2], val[pos * 2 + 1]);
  }
} seg;
int nxt[N][3];
struct seg_tree_next {
  int val[4 * N];
  int query(int pos, int low, int high, int l, int r) {
    if (l > r) return n + 1;
    if (l > high || r < low) return 0;
    if (l <= low && r >= high) return val[pos];
    int mid = (low + high) / 2;
    return min(query(pos * 2, low, mid, l, r),
               query(pos * 2 + 1, mid + 1, high, l, r));
  }
  void update(int pos, int low, int high, int l, int r, int d) {
    if (l > high || r < low) return;
    if (l <= low && r >= high) {
      val[pos] = d;
      return;
    }
    int mid = (low + high) / 2;
    update(pos * 2, low, mid, l, r, d);
    update(pos * 2 + 1, mid + 1, high, l, r, d);
    val[pos] = min(val[pos * 2], val[pos * 2 + 1]);
  }
  void build(int pos, int low, int high) {
    if (low == high) {
      val[pos] = n + 1;
      return;
    }
    int mid = (low + high) / 2;
    build(pos * 2, low, mid);
    build(pos * 2 + 1, mid + 1, high);
    val[pos] = min(val[pos * 2], val[pos * 2 + 1]);
  }
} seg_next;
int sec[N];
void get_next() {
  seg_next.build(1, 1, n);
  int i;
  int res;
  for (i = 1; i <= n; i++) {
    sec[i] = n + 1;
  }
  nxt[n][1] = n + 1;
  nxt[n][2] = n + 1;
  seg_next.update(1, 1, n, a[n], a[n], n);
  for (i = n - 1; i >= 1; i--) {
    res = seg_next.query(1, 1, n, 1, a[i] - 1);
    nxt[i][1] = res;
    if (res != n + 1) {
      nxt[i][2] = min(seg_next.query(1, 1, n, 1, a[res] - 1),
                      seg_next.query(1, 1, n, a[res] + 1, a[i] - 1));
      nxt[i][2] = min(nxt[i][2], sec[a[res]]);
    } else {
      nxt[i][2] = n + 1;
    }
    sec[a[i]] = seg.query(1, 1, n, a[i], a[i]);
    seg_next.update(1, 1, n, a[i], a[i], i);
  }
}
vector<int> is_min[N];
int lb[N], ub[N];
void check(int ind) {
  int i;
  if (n + 1 - ind <= k)
    lb[ind] = 0;
  else
    lb[ind] = a[seg.query(1, 1, n, ind + 1, ind + k)];
  ub[ind] = n + 1;
  for (i = 0; i < is_min[ind].size(); i++) {
    if (nxt[is_min[ind][i]][2] - is_min[ind][i] > k) {
      ub[ind] = min(ub[ind], a[is_min[ind][i]]);
    }
  }
  lb[ind]++;
  ub[ind]--;
}
int mark[N];
int triggered;
int min_triggered = INF;
vector<int> v;
vector<int> swappers;
map<int, int> mymap;
map<int, int>::iterator it;
void Compress() {
  int i;
  for (i = 1; i <= n; i++) mymap[a[i]];
  i = 0;
  for (it = mymap.begin(); it != mymap.end(); ++it) {
    i++;
    it->second = i;
  }
  for (i = 1; i <= n; i++) {
    a[i] = mymap[a[i]];
  }
}
bool swap_sort(int x, int y) { return a[x] < a[y]; }
bool v_sort(int x, int y) {
  if (lb[x] != lb[y]) return lb[x] < lb[y];
  return ub[x] > ub[y];
}
struct seg_tree2 {
  int val[4 * N], lazy[4 * N];
  void refresh(int pos, int low, int high) {
    if (lazy[pos] == 0) return;
    val[pos] += lazy[pos] * (high - low + 1);
    if (low != high) {
      lazy[pos * 2] += lazy[pos];
      lazy[pos * 2 + 1] += lazy[pos];
    }
    lazy[pos] = 0;
  }
  int query(int pos, int low, int high, int l, int r) {
    refresh(pos, low, high);
    if (l > high || r < low) return 0;
    if (l <= low && r >= high) return val[pos];
    int mid = (low + high) / 2;
    return query(pos * 2, low, mid, l, r) +
           query(pos * 2 + 1, mid + 1, high, l, r);
  }
  void update(int pos, int low, int high, int l, int r, int d) {
    refresh(pos, low, high);
    if (l > high || r < low) return;
    if (l <= low && r >= high) {
      lazy[pos] += d;
      refresh(pos, low, high);
      return;
    }
    int mid = (low + high) / 2;
    update(pos * 2, low, mid, l, r, d);
    update(pos * 2 + 1, mid + 1, high, l, r, d);
    val[pos] = val[pos * 2] + val[pos * 2 + 1];
  }
  void build(int pos, int low, int high, int arr[]) {
    if (low == high) {
      val[pos] = arr[low];
      return;
    }
    int mid = (low + high) / 2;
    build(pos * 2, low, mid, arr);
    build(pos * 2 + 1, mid + 1, high, arr);
    val[pos] = val[pos * 2] + val[pos * 2 + 1];
  }
} seg2;
inline int readInt() {
  bool minus = false;
  int result = 0;
  char ch;
  ch = getchar();
  while (true) {
    if (ch == '-') break;
    if (ch >= '0' && ch <= '9') break;
    ch = getchar();
  }
  if (ch == '-')
    minus = true;
  else
    result = ch - '0';
  while (true) {
    ch = getchar();
    if (ch < '0' || ch > '9') break;
    result = result * 10 + (ch - '0');
  }
  if (minus)
    return -result;
  else
    return result;
}
int main() {
  int i;
  n = readInt();
  k = readInt();
  for (i = 1; i <= n; i++) {
    a[i] = readInt();
  }
  Compress();
  seg.build(1, 1, n, a);
  a[0] = INF;
  get_next();
  for (i = 1; i <= n; i++) {
    is_min[nxt[i][1]].push_back(i);
  }
  for (i = 1; i <= n; i++) {
    check(i);
  }
  for (i = 1; i <= n; i++) {
    if (nxt[i][1] - i > k) {
      mark[i]++;
      mark[i + k + 1]--;
      triggered++;
      min_triggered = min(min_triggered, a[i]);
    }
  }
  if (!triggered) {
    printf("YES\n");
    return 0;
  }
  for (i = 1; i <= n; i++) {
    mark[i] = mark[i - 1] + mark[i];
    if (mark[i] == triggered) {
      v.push_back(i);
    }
  }
  if (!v.empty())
    for (i = v.back() + 1; i <= n; i++) {
      if (a[i] < min_triggered && lb[i] <= ub[i]) {
        swappers.push_back(i);
      }
    }
  if (v.size() == 0 || swappers.size() == 0) {
    printf("NO\n");
    return 0;
  }
  sort(swappers.begin(), swappers.end(), swap_sort);
  sort(v.begin(), v.end(), v_sort);
  for (i = 0; i < v.size(); i++) {
    ub[v[i]] = min(ub[v[i]], a[v[i]] - 1);
  }
  for (i = 0; i < swappers.size(); i++) {
    seg2.update(1, 1, n, lb[swappers[i]], ub[swappers[i]], 1);
  }
  int last = 0;
  for (i = 0; i < v.size(); i++) {
    if (last < swappers.size())
      while (a[swappers[last]] < lb[v[i]]) {
        seg2.update(1, 1, n, lb[swappers[last]], ub[swappers[last]], -1);
        last++;
        if (last == swappers.size()) break;
      }
    if (seg2.query(1, 1, n, lb[v[i]], ub[v[i]])) {
      printf("YES\n");
      cerr << v[i] << endl;
      cerr << lb[v[i]] << " " << ub[v[i]] << endl;
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}
