#include <bits/stdc++.h>

using namespace std;

const int64_t INF = 1LL << 60;

template <typename T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  int64_t T;
  cin >> N >> T;
  vector<int64_t> A, B, C;
  for (int i = 0; i < N; i++) {
    int64_t a, b;
    cin >> a >> b;
    if (a == 0) {
      C.emplace_back(b + 1);
    } else {
      A.emplace_back(a);
      B.emplace_back(b);
    }
  }
  vector<int> idx(A.size());
  iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(),
       [&](int a, int b) { return A[b] * (B[a] + 1) < A[a] * (B[b] + 1); });
  vector<int64_t> NA, NB;
  for (int i : idx) {
    NA.emplace_back(A[i]), NB.emplace_back(B[i]);
  }
  A = NA, B = NB;
  sort(C.begin(), C.end());
  vector<int64_t> dp(31, T + 1);
  dp[0] = 0;
  for (int i = 0; i < (int)A.size(); i++) {
    for (int j = (int)dp.size() - 2; j > -1; j--) {
      if (dp[j] > T) continue;
      chmin(dp[j + 1], (A[i] + 1) * (dp[j] + 1) + B[i]);
    }
  }
  int res = 0;
  for (int i = 0; i < (int)dp.size(); i++) {
    if (dp[i] > T) continue;
    int64_t r = T - dp[i];
    int p = 0;
    while (p < (int)C.size() && r >= C[p]) {
      r -= C[p++];
    }
    res = max(res, i + p);
  }
  cout << res << '\n';
  return 0;
}
