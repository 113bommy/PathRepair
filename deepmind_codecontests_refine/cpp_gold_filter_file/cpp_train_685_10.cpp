#include <bits/stdc++.h>
using namespace std;
int n, m, val[100005], T;
long long Ans[100005];
struct node {
  int id, x, y, val;
  bool operator<(const node &_) const {
    if (x == _.x) return id < _.id;
    return x < _.x;
  }
} A[100005 << 3], B[100005 << 3];
set<int> st[100005];
set<int>::iterator las, nxt, now;
void Insert(int x, int v) {
  if (val[x] == v) return;
  if (val[x] != v && val[x] != 0) {
    int p1 = 0, p2 = 0;
    now = las = nxt = st[val[x]].find(x);
    if (las != st[val[x]].begin()) {
      las--;
      A[++T] = (node){0, x, *las, *las - x};
      p1 = 1;
    }
    nxt++;
    if (nxt != st[val[x]].end()) {
      A[++T] = (node){0, *nxt, x, x - *nxt};
      p2 = 1;
    }
    if (p1 && p2) {
      A[++T] = (node){0, *las, *nxt, *nxt - *las};
    }
    st[val[x]].erase(now);
  }
  int p1 = 0, p2 = 0;
  st[v].insert(x);
  now = las = nxt = st[v].find(x);
  if (las != st[v].begin()) {
    las--;
    A[++T] = (node){0, *las, x, x - *las};
    p1 = 1;
  }
  nxt++;
  if (nxt != st[v].end()) {
    A[++T] = (node){0, x, *nxt, *nxt - x};
    p2 = 1;
  }
  if (p1 && p2) {
    A[++T] = (node){0, *nxt, *las, *las - *nxt};
  }
  val[x] = v;
}
void Insert2(int id, int x, int y) {
  A[++T] = (node){id, y, y, 1};
  A[++T] = (node){id, y, x - 1, -1};
  A[++T] = (node){id, x - 1, y, -1};
  A[++T] = (node){id, x - 1, x - 1, 1};
}
struct BIT {
  long long sum[100005 << 3];
  void Add(int x, int y) {
    while (x <= T) {
      sum[x] += y;
      x += x & -x;
    }
  }
  long long Query(int x) {
    long long res = 0;
    while (x) {
      res += sum[x];
      x -= x & -x;
    }
    return res;
  }
  void Del(int x) {
    while (x <= T) {
      sum[x] = 0;
      x += x & -x;
    }
  }
} bit;
void solve(int L, int R) {
  if (L == R) return;
  int mid = (L + R) >> 1;
  solve(L, mid);
  solve(mid + 1, R);
  int l = L, r = mid + 1, k = l;
  while (l <= mid && r <= R) {
    if (A[l] < A[r]) {
      if (!A[l].id) bit.Add(A[l].y, A[l].val);
      B[k++] = A[l++];
    } else {
      if (A[r].id) Ans[A[r].id] += bit.Query(A[r].y) * A[r].val;
      B[k++] = A[r++];
    }
  }
  while (l <= mid) B[k++] = A[l++];
  while (r <= R) {
    if (A[r].id) Ans[A[r].id] += bit.Query(A[r].y) * A[r].val;
    B[k++] = A[r++];
  }
  for (int i = L; i <= R; i++) {
    A[i] = B[i];
    if (!A[i].id) bit.Del(A[i].y);
  }
}
int main() {
  int cnt = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int v;
    scanf("%d", &v);
    Insert(i, v);
  }
  for (int i = 1; i <= m; i++) {
    int op, x, y;
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1)
      Insert(x, y);
    else
      Insert2(++cnt, x, y);
  }
  solve(1, T);
  for (int i = 1; i <= cnt; i++) printf("%lld\n", Ans[i]);
  return 0;
}
