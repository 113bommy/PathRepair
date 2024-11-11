#include <bits/stdc++.h>
using namespace std;
struct data {
  int64_t id, u1, v1, u2, v2;
};
data Q[200005];
pair<int64_t, int64_t> a[200005];
int64_t n, T, R[200005], C[200005], rs[200005], tree[800005];
bool cmp1(data x1, data x2) { return x1.u1 < x2.u1; }
bool cmp2(data x1, data x2) { return x1.u2 > x2.u2; }
void Update(int64_t k, int64_t l, int64_t r, int64_t pos) {
  if (l == r) {
    tree[k]++;
    return;
  }
  int64_t mid = (l + r) / 2;
  if (pos <= mid)
    Update(2 * k, l, mid, pos);
  else
    Update(2 * k + 1, mid + 1, r, pos);
  tree[k] = tree[2 * k] + tree[2 * k + 1];
}
int64_t Query(int64_t k, int64_t l, int64_t r, int64_t L, int64_t R) {
  if (l > R || L > r) return 0;
  if (L <= l && r <= R) return tree[k];
  int64_t mid = (l + r) / 2;
  return Query(2 * k, l, mid, L, R) + Query(2 * k + 1, mid + 1, r, L, R);
}
void Process1() {
  for (int64_t i = 1; i <= n; i++) {
    R[a[i].first]++;
    C[a[i].second]++;
  }
  for (int64_t i = 1; i <= n; i++) {
    R[i] += R[i - 1];
    C[i] += C[i - 1];
  }
  for (int64_t i = 1; i <= T; i++) {
    int64_t tmp;
    tmp = C[Q[i].u1 - 1];
    rs[i] += tmp * (tmp - 1) / 2;
    tmp = C[n] - C[Q[i].u2];
    rs[i] += tmp * (tmp - 1) / 2;
    tmp = R[Q[i].v1 - 1];
    rs[i] += tmp * (tmp - 1) / 2;
    tmp = R[n] - R[Q[i].v2];
    rs[i] += tmp * (tmp - 1) / 2;
  }
}
void Process2() {
  sort(Q + 1, Q + T + 1, cmp1);
  int64_t p = 1;
  for (int64_t i = 1; i <= T; i++) {
    while (p <= n && a[p].first < Q[i].u1) Update(1, 1, n, a[p++].second);
    int64_t tmp;
    tmp = Query(1, 1, n, 1, Q[i].v1 - 1);
    rs[Q[i].id] += tmp * (tmp - 1) / 2;
    tmp = Query(1, 1, n, Q[i].v2 + 1, n);
    rs[Q[i].id] += tmp * (tmp - 1) / 2;
  }
  reverse(a + 1, a + n + 1);
  for (int64_t i = 1; i <= 4 * n; i++) tree[i] = 0;
  sort(Q + 1, Q + T + 1, cmp2);
  p = 1;
  for (int64_t i = 1; i <= T; i++) {
    while (p <= n && a[p].first > Q[i].u2) Update(1, 1, n, a[p++].second);
    int64_t tmp;
    tmp = Query(1, 1, n, 1, Q[i].v1 - 1);
    rs[Q[i].id] += tmp * (tmp - 1) / 2;
    tmp = Query(1, 1, n, Q[i].v2 + 1, n);
    rs[Q[i].id] += tmp * (tmp - 1) / 2;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> T;
  for (int64_t i = 1; i <= n; i++) {
    cin >> a[i].second;
    a[i].first = i;
  }
  for (int64_t i = 1; i <= T; i++) {
    cin >> Q[i].u1 >> Q[i].v1 >> Q[i].u2 >> Q[i].v2;
    Q[i].id = i;
  }
  Process1();
  Process2();
  for (int64_t i = 1; i <= T; i++) cout << n * (n - 1) / 2 - rs[i] << "\n";
}
