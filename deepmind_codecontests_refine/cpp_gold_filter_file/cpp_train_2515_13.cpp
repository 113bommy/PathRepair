#include <bits/stdc++.h>
using namespace std;
const int kMaxValue = 1000000;
struct IntervalTree {
  IntervalTree(const int N) : N(N), adds(4 * N, 0), maxVals(4 * N, 0) {}
  void Relax(const int node) {
    const int addValue = adds[node];
    adds[node] = 0;
    maxVals[node] += addValue;
    if (node * 2 + 2 < 4 * N) {
      adds[node * 2 + 1] += addValue;
      adds[node * 2 + 2] += addValue;
      return;
    }
  }
  void AddImpl(const int L, const int R, const int l, const int r,
               const int node, const int val) {
    Relax(node);
    if (R < l || r < L) {
      return;
    }
    if (L <= l && r <= R) {
      adds[node] += val;
      Relax(node);
      return;
    }
    AddImpl(L, R, l, (l + r) / 2, node * 2 + 1, val);
    AddImpl(L, R, (l + r) / 2 + 1, r, node * 2 + 2, val);
    maxVals[node] = max(maxVals[node * 2 + 1], maxVals[node * 2 + 2]);
  }
  int FindMaxNonZeroImpl(const int l, const int r, const int node) {
    Relax(node);
    if (maxVals[node] <= 0) {
      return -1;
    }
    if (l == r) {
      return l;
    }
    const int rightIndex = FindMaxNonZeroImpl((l + r) / 2 + 1, r, node * 2 + 2);
    if (rightIndex != -1) {
      return rightIndex;
    }
    return FindMaxNonZeroImpl(l, (l + r) / 2, node * 2 + 1);
  }
  int FindMaxNonZero() { return FindMaxNonZeroImpl(0, N - 1, 0); }
  void Add(const int L, const int R, const int val) {
    AddImpl(L, R, 0, N - 1, 0, val);
  }
  const int N;
  vector<int> adds;
  vector<int> maxVals;
};
int main() {
  int n, m;
  cin >> n >> m;
  IntervalTree tree(kMaxValue + 1);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    tree.Add(0, a[i], 1);
  }
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d", &b[i]);
    tree.Add(0, b[i], -1);
  }
  int q;
  cin >> q;
  for (int it = 0; it < q; ++it) {
    int type, i, x;
    scanf("%d%d%d", &type, &i, &x);
    --i;
    if (type == 1) {
      tree.Add(0, a[i], -1);
      a[i] = x;
      tree.Add(0, a[i], 1);
    } else {
      tree.Add(0, b[i], 1);
      b[i] = x;
      tree.Add(0, b[i], -1);
    }
    printf("%d\n", tree.FindMaxNonZero());
  }
  return 0;
}
