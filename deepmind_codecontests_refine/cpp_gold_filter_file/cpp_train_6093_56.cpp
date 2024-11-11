#include <bits/stdc++.h>
using namespace std;
long long INF = 1e16;
int main() {
  long long N, K;
  int i;
  cin >> N >> K;
  vector<int> A(N + 1);
  vector<long long> Pre(N + 1, INF);
  vector<long long> Suf(N + 1, INF);
  for (i = 0; i <= N; ++i) cin >> A[i];
  Suf[N] = Pre[0] = 0;
  for (i = 0; i < N; ++i) {
    if (abs(Pre[i] + A[i]) % 2) break;
    Pre[i + 1] = (Pre[i] + A[i]) >> 1LL;
  }
  for (i = N; i >= 1; --i) {
    if (abs(Suf[i] + A[i]) * 2LL > INF) break;
    Suf[i - 1] = (Suf[i] + A[i]) * 2;
  }
  long long ans = 0;
  for (i = 0; i <= N; ++i) {
    if (Suf[i] != INF && Pre[i] != INF && abs(Pre[i] + Suf[i]) <= K) ++ans;
  }
  if (Suf[N] + Pre[N] == 0) --ans;
  cout << ans;
  return 0;
}
