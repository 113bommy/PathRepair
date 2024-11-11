#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 16) + 7;
int cnt, n, Q, B, ind[N], tmp[N], A[N], ans[N], f[43][503][503];
struct qry {
  int l, r, id;
} q1[N], q2[N];
vector<pair<int, int> > op;
bool cmp(int x, int y) { return A[x] < A[y]; }
bool cmpl(qry A, qry B) { return A.l < B.l; }
bool cmpr(qry A, qry B) { return A.r < B.r; }
int merge(int x, int y) {
  if (!x || !y) return (x | y);
  op.push_back(pair<int, int>(x, y));
  return ++cnt;
}
void solve(int id, int L, int R) {
  if (L == R) {
    f[id][1][1] = ind[L];
    return;
  }
  int mid = (L + R) >> 1;
  solve(id + 1, L, mid), solve(id + 2, mid + 1, R);
  for (int i = L; i <= R; ++i) tmp[i] = ind[i];
  inplace_merge(tmp + L, tmp + mid + 1, tmp + R + 1);
  for (int i = L, pl = L, ql = mid + 1; i <= R; ++i) {
    while (pl <= mid && ind[pl] < tmp[i]) ++pl;
    while (ql <= R && ind[ql] < tmp[i]) ++ql;
    for (int j = L, pr = pl - 1, qr = ql - 1; j <= R; ++j) {
      f[id][i - L + 1][j - L + 1] = 0;
      while (pr + 1 <= mid && ind[pr + 1] <= tmp[j]) ++pr;
      while (qr + 1 <= R && ind[qr + 1] <= tmp[j]) ++qr;
      if (pl > pr)
        f[id][i - L + 1][j - L + 1] = f[id + 2][ql - mid][qr - mid];
      else if (ql > qr)
        f[id][i - L + 1][j - L + 1] = f[id + 1][pl - L + 1][pr - L + 1];
      else
        f[id][i - L + 1][j - L + 1] = merge(f[id + 1][pl - L + 1][pr - L + 1],
                                            f[id + 2][ql - mid][qr - mid]);
    }
  }
  for (int i = L; i <= R; ++i) ind[i] = tmp[i];
}
void work(int L, int R) {
  solve(1, L, R);
  static int lft[N], rht[N];
  for (int i = 1, j = L; i <= Q; ++i) {
    while (j <= R && ind[j] < q1[i].l) ++j;
    lft[q1[i].id] = j;
  }
  for (int i = 1, j = L - 1; i <= Q; ++i) {
    while (j + 1 <= R && ind[j + 1] <= q2[i].r) ++j;
    rht[q2[i].id] = j;
  }
  for (int i = 1; i <= Q; ++i)
    if (lft[i] <= rht[i])
      ans[i] = merge(ans[i], f[1][lft[i] - L + 1][rht[i] - L + 1]);
}
int main() {
  cin >> n >> Q;
  for (int i = 1; i <= n; ++i) cin >> A[i], ind[i] = i;
  B = sqrt(Q);
  sort(ind + 1, ind + n + 1, cmp);
  for (int i = 1; i <= Q; ++i) cin >> q1[i].l >> q1[i].r, q1[i].id = i;
  memcpy(q2, q1, sizeof(q1));
  sort(q1 + 1, q1 + Q + 1, cmpl), sort(q2 + 1, q2 + Q + 1, cmpr);
  cnt = n;
  for (int i = 1; i <= n; i += B) work(i, min(n, i + B - 1));
  cout << op.size() + n << endl;
  for (auto t : op) printf("%d %d\n", t.first, t.second);
  for (int i = 1; i <= Q; ++i) printf("%d ", ans[i]);
  return 0;
}
