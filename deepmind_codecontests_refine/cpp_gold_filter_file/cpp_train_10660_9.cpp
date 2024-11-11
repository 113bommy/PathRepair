#include <bits/stdc++.h>
using namespace std;
int N, M, H;
int A[150010], B[150010];
struct segment_tree {
  int minv[150010 * 4], cov[150010 * 4];
  void push(int l, int r, int id) {
    cov[(id)*2 + 1] += cov[id];
    cov[(id)*2 + 2] += cov[id];
    minv[(id)*2 + 1] += cov[id];
    minv[(id)*2 + 2] += cov[id];
    cov[id] = 0;
  }
  void init(int l, int r, int id) {
    if (l == r) {
      minv[id] = M - l;
      return;
    }
    init(l, (l + r) / 2, (id)*2 + 1);
    init((l + r) / 2 + 1, r, (id)*2 + 2);
    minv[id] = min(minv[(id)*2 + 1], minv[(id)*2 + 2]);
  }
  void insert(int l, int r, int id, int a, int b, int v) {
    if (r < a || b < l) return;
    if (a <= l && r <= b) {
      cov[id] += v;
      minv[id] += v;
      return;
    }
    push(l, r, id);
    insert(l, (l + r) / 2, (id)*2 + 1, a, b, v);
    insert((l + r) / 2 + 1, r, (id)*2 + 2, a, b, v);
    minv[id] = min(minv[(id)*2 + 1], minv[(id)*2 + 2]);
  }
  int getmin() { return minv[0]; }
} seg;
int main() {
  scanf("%d%d%d", &N, &M, &H);
  for (int i = 0; i < M; i++) {
    scanf("%d", &B[i]);
  }
  sort(B, B + M);
  for (int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    A[i] = lower_bound(B, B + M, H - A[i]) - B;
  }
  seg.init(0, M, 0);
  for (int i = 0; i < M - 1; i++) {
    seg.insert(0, M, 0, 0, A[i], -1);
  }
  int ans = 0;
  for (int i = M - 1; i < N; i++) {
    seg.insert(0, M, 0, 0, A[i], -1);
    int val = seg.getmin();
    if (val >= 0) {
      ans++;
    }
    seg.insert(0, M, 0, 0, A[i - M + 1], 1);
  }
  printf("%d\n", ans);
}
