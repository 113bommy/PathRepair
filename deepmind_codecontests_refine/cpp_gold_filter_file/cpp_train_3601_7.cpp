#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
vector<int> event[N];
long long sum[2][N << 2];
int n, m, lo[N], hi[N], f[N], prevPivot[N], maxi[2][N << 2], lazy[2][N << 2],
    cnt[2][N << 2];
void init(int v, int l, int r) {
  lazy[0][v] = lazy[1][v] = 0;
  if (l == r) {
    cnt[0][v] = cnt[1][v] = 1;
    sum[0][v] = sum[1][v] = l + 1;
    if (l & 1) {
      maxi[0][v] = -1e9;
      maxi[1][v] = 0;
    } else {
      maxi[0][v] = 0;
      maxi[1][v] = -1e9;
    }
    return;
  }
  int m = (l + r) / 2;
  int v1 = v << 1;
  int v2 = v1 | 1;
  init(v1, l, m);
  init(v2, m + 1, r);
  for (int i : {0, 1}) {
    cnt[i][v] = sum[i][v] = 0;
    maxi[i][v] = max(maxi[i][v1], maxi[i][v2]);
    if (maxi[i][v] == maxi[i][v1]) cnt[i][v] += cnt[i][v1];
    if (maxi[i][v] == maxi[i][v2]) cnt[i][v] += cnt[i][v2];
    if (maxi[i][v] == maxi[i][v1]) sum[i][v] += sum[i][v1];
    if (maxi[i][v] == maxi[i][v2]) sum[i][v] += sum[i][v2];
  }
}
inline void push(int p, int v, int s, int e) {
  if (lazy[p][v] != 0) {
    maxi[p][v] += lazy[p][v];
    if (s != e) {
      lazy[p][2 * v + 0] += lazy[p][v];
      lazy[p][2 * v + 1] += lazy[p][v];
    }
    lazy[p][v] = 0;
  }
}
void update(int p, int v, int s, int e, int l, int r, int x) {
  if (l <= s && e <= r) {
    lazy[p][v] += x;
    push(p, v, s, e);
    return;
  }
  push(p, v, s, e);
  if (r < s || e < l || r < l) return;
  int m = (s + e) / 2;
  int v1 = v << 1;
  int v2 = v1 | 1;
  update(p, v1, s, m, l, r, x);
  update(p, v2, m + 1, e, l, r, x);
  cnt[p][v] = sum[p][v] = 0;
  maxi[p][v] = max(maxi[p][v1], maxi[p][v2]);
  if (maxi[p][v] == maxi[p][v1]) cnt[p][v] += cnt[p][v1];
  if (maxi[p][v] == maxi[p][v2]) cnt[p][v] += cnt[p][v2];
  if (maxi[p][v] == maxi[p][v1]) sum[p][v] += sum[p][v1];
  if (maxi[p][v] == maxi[p][v2]) sum[p][v] += sum[p][v2];
}
void combUpdate(int v, int s, int e, int l, int r, int x) {
  if (l <= s && e <= r) {
    lazy[0][v] += x;
    lazy[1][v] += x;
    push(0, v, s, e);
    push(1, v, s, e);
    return;
  }
  push(0, v, s, e);
  push(1, v, s, e);
  if (r < s || e < l || r < l) return;
  int m = (s + e) / 2;
  int v1 = v << 1;
  int v2 = v1 | 1;
  combUpdate(v1, s, m, l, r, x);
  combUpdate(v2, m + 1, e, l, r, x);
  for (int i : {0, 1}) {
    cnt[i][v] = sum[i][v] = 0;
    maxi[i][v] = max(maxi[i][v1], maxi[i][v2]);
    if (maxi[i][v] == maxi[i][v1]) cnt[i][v] += cnt[i][v1];
    if (maxi[i][v] == maxi[i][v2]) cnt[i][v] += cnt[i][v2];
    if (maxi[i][v] == maxi[i][v1]) sum[i][v] += sum[i][v1];
    if (maxi[i][v] == maxi[i][v2]) sum[i][v] += sum[i][v2];
  }
}
long long query(int p, int v, int s, int e, int l, int r, int n, int st) {
  push(p, v, s, e);
  if (maxi[p][v] < n) return 0;
  if (l <= s && e <= r) {
    return sum[p][v] - st * 1LL * cnt[p][v];
  }
  int m = (s + e) / 2;
  int v1 = v << 1;
  int v2 = v1 | 1;
  if (r <= m) return query(p, v1, s, m, l, r, n, st);
  if (m < l) return query(p, v2, m + 1, e, l, r, n, st);
  return query(p, v1, s, m, l, r, n, st) + query(p, v2, m + 1, e, l, r, n, st);
}
inline void modify(int l, int r, int pivot, int add) {
  if (r < pivot) {
    combUpdate(1, 1, m, pivot, m, add);
  } else if (l <= pivot && pivot <= r) {
    update(pivot & 1, 1, 1, m, pivot, r, add);
    if (((pivot ^ r) & 1) == 0 && r < m) {
      combUpdate(1, 1, m, r + 1, m, add);
    }
  } else {
    combUpdate(1, 1, m, pivot, l - 1, add);
    update(l & 1, 1, 1, m, l, r, add);
    if (((l ^ r) & 1) == 0 && r < m) {
      combUpdate(1, 1, m, r + 1, m, add);
    }
  }
}
long long getSum(int n) {
  long long ret = 0;
  for (int i = 1; i <= n; i++) {
    ret += i * 1LL * (n + 1 - i);
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> lo[i] >> hi[i];
    event[lo[i]].emplace_back(i);
    event[hi[i]].emplace_back(i);
  }
  if (m == 1) {
    cout << 1 << '\n';
    exit(0);
  }
  init(1, 1, m);
  for (int i = 1; i <= n; i++) {
    modify(lo[i], hi[i], 1, 1);
    prevPivot[i] = 1;
  }
  long long answer = 0;
  answer += query(0, 1, 1, m, 1, m, n, 1);
  answer += query(1, 1, 1, m, 1, m, n, 1);
  for (int i = 3; i <= m; i += 2) {
    for (int x : event[i - 2]) {
      if (prevPivot[x] != i) {
        modify(lo[x], hi[x], prevPivot[x], -1);
        prevPivot[x] = i;
        modify(lo[x], hi[x], prevPivot[x], 1);
      }
    }
    for (int x : event[i - 1]) {
      if (prevPivot[x] != i) {
        modify(lo[x], hi[x], prevPivot[x], -1);
        prevPivot[x] = i;
        modify(lo[x], hi[x], prevPivot[x], 1);
      }
    }
    answer += query(0, 1, 1, m, i, m, n, i);
    answer += query(1, 1, 1, m, i, m, n, i);
  }
  init(1, 1, m);
  for (int i = 1; i <= n; i++) {
    modify(lo[i], hi[i], 2, 1);
    prevPivot[i] = 2;
  }
  answer += query(0, 1, 1, m, 1, m, n, 2);
  answer += query(1, 1, 1, m, 1, m, n, 2);
  for (int i = 4; i <= m; i += 2) {
    for (int x : event[i - 2]) {
      if (prevPivot[x] != i) {
        modify(lo[x], hi[x], prevPivot[x], -1);
        prevPivot[x] = i;
        modify(lo[x], hi[x], prevPivot[x], 1);
      }
    }
    for (int x : event[i - 1]) {
      if (prevPivot[x] != i) {
        modify(lo[x], hi[x], prevPivot[x], -1);
        prevPivot[x] = i;
        modify(lo[x], hi[x], prevPivot[x], 1);
      }
    }
    answer += query(0, 1, 1, m, i, m, n, i);
    answer += query(1, 1, 1, m, i, m, n, i);
  }
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= n; i++) {
    f[lo[i]]++;
    f[hi[i] + 1]--;
  }
  for (int i = 1; i <= m; i++) {
    f[i] += f[i - 1];
  }
  int cur = 0;
  for (int i = 1; i <= m; i++) {
    if (f[i]) {
      answer -= getSum(cur);
      cur = 0;
    } else {
      cur++;
    }
  }
  answer -= getSum(cur);
  cout << answer << '\n';
  return 0;
}
