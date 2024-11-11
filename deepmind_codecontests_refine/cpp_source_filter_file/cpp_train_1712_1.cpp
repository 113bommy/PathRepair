#include <bits/stdc++.h>
using namespace std;
int n, m;
int A[100005];
vector<int> S[100005], B[100005];
vector<int> prefix, suffix;
long long mut(long long x) {
  if (x < 0) return -x;
  return x;
}
int main() {
  long long ans = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d", &A[i]);
  }
  for (int i = 1; i <= m; i++) {
    if (i > 1) ans += mut(A[i] - A[i - 1]);
    if (i > 1) {
      if (A[i - 1] < A[i])
        S[A[i]].push_back(A[i - 1]);
      else if (A[i - 1] > A[i])
        B[A[i]].push_back(A[i - 1]);
    }
    if (i < m) {
      if (A[i + 1] < A[i])
        S[A[i]].push_back(A[i + 1]);
      else if (A[i + 1] > A[i])
        B[A[i]].push_back(A[i + 1]);
    }
  }
  for (int i = 1; i <= n; i++) {
    sort(S[i].begin(), S[i].end());
    sort(B[i].begin(), B[i].end());
  }
  long long sum = ans;
  for (int i = 1; i <= n; i++) {
    int N = S[i].size(), M = B[i].size();
    prefix.clear();
    prefix.assign(N, 0);
    for (int j = 0; j < N; j++) {
      prefix[j] += S[i][j];
      if (j) prefix[j] += prefix[j - 1];
    }
    suffix.clear();
    suffix.assign(M, 0);
    for (int j = 0; j < M; j++) {
      suffix[j] += B[i][j];
      if (j) suffix[j] += suffix[j - 1];
    }
    long long prefixback = 0, suffixback = 0;
    if (prefix.empty() == false) prefixback = prefix.back();
    if (suffix.empty() == false) suffixback = suffix.back();
    for (int j = 0; j < N; j++) {
      long long tmp = sum;
      tmp -= i * 1LL * N - prefixback;
      tmp -= suffixback - i * 1LL * M;
      tmp += S[i][j] * 1LL * (j + 1) - prefix[j];
      tmp += prefixback - prefix[j] - S[i][j] * 1LL * (N - j - 1);
      tmp += suffixback - S[i][j] * 1LL * M;
      ans = min(ans, tmp);
    }
    for (int j = 0; j < M; j++) {
      long long tmp = sum;
      tmp -= i * 1LL * N - prefixback;
      tmp -= suffixback - i * 1LL * M;
      tmp += B[i][j] * 1LL * N - prefixback;
      tmp += B[i][j] * 1LL * (j + 1) - suffix[j];
      tmp += suffixback - suffix[j] - B[i][j] * 1LL * (M - j - 1);
      ans = min(ans, tmp);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
