#include <bits/stdc++.h>
using namespace std;
const int NN = 4 * 100 * 1000 + 100, INF = 1 << 29;
vector<int> G[NN];
int find_index(int x, vector<int> &A) {
  int lo = 0, hi = ((int)A.size());
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    if (A[mid] < x)
      lo = mid + 1;
    else
      hi = mid;
  }
  return lo;
}
int dp[NN];
int main() {
  ios::sync_with_stdio(false);
  int n, k;
  scanf("%d%d", &n, &k);
  vector<int> A(n);
  for (int i = 0; i < n; i++) scanf("%d", &A[i]);
  vector<int> U = A;
  sort(U.begin(), U.end());
  U.resize(unique(U.begin(), U.end()) - U.begin());
  int idx, idx2;
  for (int i = 0; i < n; i++) {
    idx = find_index(A[i], U);
    G[idx].push_back(i);
  }
  dp[n] = INF;
  for (int i = n - 1; i >= 0; i--) {
    idx = find_index(A[i], U);
    idx2 = find_index(i, G[idx]);
    if (idx2 + k <= ((int)G[idx].size())) {
      dp[i] = G[idx][idx2 + k - 1];
    } else
      dp[i] = INF;
    dp[i] = min(dp[i], dp[i + 1]);
  }
  long long ans = 0;
  for (int i = 0; i < n; i++)
    if (dp[i] != INF) {
      ans += n - dp[i];
    }
  cout << ans << endl;
}
