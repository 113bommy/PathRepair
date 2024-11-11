#include <bits/stdc++.h>
using namespace std;
const int maxn = 60;
const int maxm = 20000 + 10;
long long dp[maxn][maxm], A[maxn][maxm], tree[4 * maxm];
int N, M, K;
void update(int node, int start, int end, int idx, long long val) {
  if (start > idx || end < idx) return;
  if (start == idx && end == idx) {
    tree[node] = val;
    return;
  }
  int mid = (start + end) >> 1;
  update(2 * node, start, mid, idx, val);
  update(2 * node + 1, mid + 1, end, idx, val);
  tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}
long long query(int node, int start, int end, int l, int r) {
  if (start > r || end < l) return 0;
  if (start >= l && end <= r) return tree[node];
  int mid = (start + end) >> 1;
  long long p1 = query(2 * node, start, mid, l, r);
  long long p2 = query(2 * node + 1, mid + 1, end, l, r);
  return max(p1, p2);
}
long long getSum(int i, int l, int r) {
  return A[i][r] - ((l - 1 >= 0) ? A[i][l - 1] : 0);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> K;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
      if (j) A[i][j] += A[i][j - 1];
    }
  }
  for (int j = 0; j < M; j++) {
    if (j + K - 1 >= M) break;
    long long sum = getSum(0, j, j + K - 1) + getSum(1, j, j + K - 1);
    update(1, 0, M - 1, j, sum);
    dp[0][j] = sum;
  }
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < M; j++) {
      long long maxi = 0;
      if (j + K - 1 >= M) break;
      for (int k = j - K + 1; k <= j + K - 1; k++) {
        if (k < 0 || j >= M) continue;
        long long sum = dp[i - 1][k] + getSum(i, j, j + K - 1) +
                        getSum(i + 1, j, j + K - 1);
        int lInt = max(j, k);
        int rInt = min(k + K - 1, j + K - 1);
        sum -= getSum(i, lInt, rInt);
        maxi = max(maxi, sum);
      }
      if (j - K >= 0) {
        long long sum = getSum(i, j, j + K - 1) + getSum(i + 1, j, j + K - 1);
        maxi = max(maxi, sum + query(1, 0, M - 1, 0, j - K));
      }
      if (j + K < M) {
        long long sum = getSum(i, j, j + K - 1) + getSum(i + 1, j, j + K - 1);
        maxi = max(maxi, sum + query(1, 0, M - 1, j + K, M - 1));
      }
      dp[i][j] = maxi;
    }
    for (int j = 0; j < M; j++) update(1, 0, M - 1, j, 0);
    for (int j = 0; j < M; j++) update(1, 0, M - 1, j, dp[i][j]);
  }
  long long res = 0;
  for (int i = 0; i < M; i++) res = max(res, dp[N - 1][i]);
  cout << res << '\n';
  return 0;
}
