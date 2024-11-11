#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 10;
int N, M, A[MAX_N], B[MAX_N], ans[MAX_N];
vector<pair<int, int>> queries[MAX_N];
struct SegTree {
  SegTree *cl, *cr;
  int l, r, m, v;
  SegTree(int l, int r) : l(l), r(r), m((l + r) / 2) {
    if (l != r) {
      cl = new SegTree(l, m);
      cr = new SegTree(m + 1, r);
    } else
      cl = cr = nullptr;
  }
  void modify(int x) {
    v++;
    if (l != r) {
      if (x <= m)
        cl->modify(x);
      else
        cr->modify(x);
    }
  }
  int query(int k) {
    if (l == r) return l;
    if (cl->v >= k)
      return cl->query(k);
    else
      return cr->query(k - cl->v);
  }
} * segt;
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
  for (int i = 1; i <= N; i++) B[i] = i;
  sort(B + 1, B + N + 1, [](int a, int b) {
    if (A[a] != A[b]) return A[a] > A[b];
    return a < b;
  });
  scanf("%d", &M);
  for (int i = 1; i <= M; i++) {
    int k, pos;
    scanf("%d%d", &k, &pos);
    queries[k].emplace_back(pos, i);
  }
  segt = new SegTree(1, N);
  for (int i = 1; i <= N; i++) {
    segt->modify(B[i]);
    for (auto q : queries[i]) {
      int p = segt->query(q.first);
      ans[q.second] = A[p];
    }
  }
  for (int i = 1; i <= M; i++) printf("%d\n", ans[i]);
}
