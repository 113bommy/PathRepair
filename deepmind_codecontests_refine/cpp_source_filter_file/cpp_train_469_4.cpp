#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100100;
const int MAXSEG = 1 << 18;
int N;
int A[MAXN];
int seg[MAXN];
long long dp[MAXN];
void build_tree(int node, int left, int right) {
  if (left == right) {
    seg[node] = left;
    return;
  }
  int mid = (left + right) / 2;
  build_tree(2 * node, left, mid);
  build_tree(2 * node + 1, mid + 1, right);
  seg[node] = A[seg[2 * node]] > A[seg[2 * node + 1]] ? A[seg[2 * node]]
                                                      : A[seg[2 * node + 1]];
}
int query(int node, int left, int right, int ql, int qr) {
  if (left > right || ql > qr || right < ql || qr < left) return N + 1;
  if (ql <= left && right <= qr) return seg[node];
  int mid = (left + right) / 2;
  int q1 = query(2 * node, left, mid, ql, qr);
  int q2 = query(2 * node + 1, mid + 1, right, ql, qr);
  return A[q1] > A[q2] ? q1 : q2;
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i < N; i++) scanf("%d", &A[i]);
  A[N] = N;
  build_tree(1, 1, N);
  for (int i = N - 1; i >= 1; i--) {
    int idx = query(1, 1, N, i + 1, A[i]);
    dp[i] = N + idx - A[i] - i + dp[idx];
  }
  long long ans = 0;
  for (int i = 1; i <= N; i++) ans += dp[i];
  printf("%I64d\n", ans);
  return 0;
}
