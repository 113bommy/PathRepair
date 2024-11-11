#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int INF = 2e9;
const long long INFLL = 1e18;
const int MAX_N = 1000;
int N, M;
long long K, P;
long long arr[MAX_N + 1][MAX_N + 1];
long long sum[2][MAX_N + 1];
priority_queue<long long> pq;
vector<long long> mx[2];
long long ans = -INFLL;
int main() {
  scanf("%d%d%lld%lld", &N, &M, &K, &P);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      scanf("%lld", &arr[i][j]);
      sum[0][i] += arr[i][j];
      sum[1][j] += arr[i][j];
    }
  }
  for (int i = 0; i < N; i++) {
    pq.push(sum[0][i]);
  }
  for (int i = 0; i < K; i++) {
    mx[0].push_back(pq.top());
    long long t = pq.top();
    pq.pop();
    pq.push(t - P * M);
  }
  while (!pq.empty()) pq.pop();
  for (int i = 0; i < M; i++) {
    pq.push(sum[1][i]);
  }
  for (int i = 0; i < K; i++) {
    mx[1].push_back(pq.top());
    long long t = pq.top();
    pq.pop();
    pq.push(t - P * N);
  }
  long long S[2];
  S[0] = S[1] = 0;
  for (int i = 0; i < K; i++) {
    S[1] += mx[1][i];
  }
  for (int i = 0; i <= K; i++) {
    int j = K - i;
    ans = max(ans, S[0] + S[1] - (long long)i * (long long)j * P);
    if (i == K) break;
    S[0] += mx[0][i];
    S[1] -= mx[1][K - i - 1];
  }
  cout << ans;
  return 0;
}
