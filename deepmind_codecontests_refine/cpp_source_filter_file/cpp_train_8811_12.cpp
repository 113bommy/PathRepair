#include <bits/stdc++.h>
using namespace std;
int dp[2][200001], temp[2][200001], inf = INT_MAX / 2;
void SlidingMinimum(int A[], int B[], int k, int c) {
  deque<int> Q;
  for (int i = 0; i < 200001; ++i) {
    while (!Q.empty() && Q.front() <= i - k) Q.pop_front();
    while (!Q.empty() && A[i] <= A[Q.back()]) Q.pop_back();
    Q.push_back(i);
    B[i] = min(B[i], A[Q.front()] + c);
  }
}
void UpdateNoFlip(int k) {
  for (int i = 0; i < 200001; ++i) temp[0][i] = dp[0][i];
  for (int i = k; i < 200001; ++i) temp[1][i] = dp[1][i - k];
}
void UpdateFlip(int k) {
  SlidingMinimum(dp[0], temp[0], k, 2);
  SlidingMinimum(dp[0], temp[1], k, 1);
  SlidingMinimum(dp[1], temp[0], k, 1);
}
void ResetTemp() {
  for (int i = 0; i < 200001; ++i) temp[0][i] = temp[1][i] = inf;
}
void CopyFromTemp() {
  for (int i = 0; i < 200001; ++i) dp[0][i] = temp[0][i], dp[1][i] = temp[1][i];
}
void Print() {
  for (int k = 0; k < 2; ++k) {
    for (int i = 0; i < 200001; ++i) {
      if (dp[k][i] < inf) {
        cout << k << ' ' << i << ' ' << dp[k][i] << '\n';
      }
    }
  }
  cout << '\n';
}
int main() {
  int n, k, p;
  for (int i = 1; i < 200001; ++i) dp[0][i] = dp[1][i] = inf;
  cin >> n >> k;
  p = 0;
  while (k--) {
    int l, r;
    cin >> l >> r;
    if (l > p) {
      ResetTemp();
      UpdateNoFlip(l - p);
      CopyFromTemp();
    }
    ResetTemp();
    int k = r - l;
    UpdateNoFlip(k);
    UpdateFlip(k);
    CopyFromTemp();
    p = r;
  }
  ResetTemp();
  UpdateNoFlip(2 * n - p);
  CopyFromTemp();
  int ans = min(dp[0][n], dp[1][n]);
  if (ans >= inf) {
    cout << "Hungry\n";
  } else {
    cout << "Full\n";
    cout << ans << '\n';
  }
  return 0;
}
