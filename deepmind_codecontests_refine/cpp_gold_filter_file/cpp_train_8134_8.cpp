#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
inline bool mina(A &first, B second) {
  return (first > second) ? (first = second, 1) : 0;
}
template <class A, class B>
inline bool maxa(A &first, B second) {
  return (first < second) ? (first = second, 1) : 0;
}
const int MAXN = 200005;
int N, M, K;
int in[MAXN];
pair<int, int> offers[MAXN];
long long dp[MAXN];
long long sumr[MAXN];
long long sum_range(int a, int b) {
  if (a == 0) return sumr[b];
  return sumr[b] - sumr[a - 1];
}
int main() {
  scanf("%d %d %d", &N, &M, &K);
  for (int i = 0; (i) < (N); ++(i)) {
    scanf("%d", &in[i]);
  }
  sort(in, in + N);
  sumr[0] = in[0];
  for (int i = 1; i < N; i++) {
    sumr[i] = sumr[i - 1] + in[i];
  }
  for (int i = 0; (i) < (M); ++(i)) {
    scanf("%d %d", &offers[i].first, &offers[i].second);
  }
  for (int i = 0; (i) < (K); ++(i)) {
    dp[i] = 1LL << 62;
  }
  dp[K] = 0;
  for (int i = K - 1; i >= 0; i--) {
    long long sum = 0;
    for (int j = i; j < K; j++) {
      sum += in[j];
      mina(dp[i], sum + dp[j + 1]);
    }
    for (int j = 0; (j) < (M); ++(j)) {
      if (offers[j].first + i <= K) {
        mina(dp[i], sum_range(i + offers[j].second, i + offers[j].first - 1) +
                        dp[offers[j].first + i]);
      }
    }
  }
  cout << dp[0] << endl;
  return 0;
}
