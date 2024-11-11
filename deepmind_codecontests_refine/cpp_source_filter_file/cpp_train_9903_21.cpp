#include <bits/stdc++.h>
using namespace std;
const int MaxK = 100000 + 5, MaxN = 100000 + 5;
const long long INF = 0x7F7F7F7F7F7F7F7F;
int K, N;
int A[MaxN];
long long B[MaxN];
int MC[MaxK];
priority_queue<long long, vector<long long>, greater<long long> > pq;
void init() {
  scanf("%d %d", &K, &N);
  for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
  for (int i = 1; i <= N; ++i) scanf("%lld", &B[i]);
}
void solve() {
  for (int i = 1; i <= N; ++i) {
    int v = A[i];
    if (B[MC[v]] < B[i]) MC[v] = i;
  }
  for (int i = 1; i <= N; ++i) {
    int v = A[i];
    if (MC[v] != i) pq.push(B[i]);
  }
  long long ans = 0;
  for (int i = 1; i <= K; ++i) {
    if (MC[i] == 0) {
      ans += pq.top();
      pq.pop();
    }
  }
  cout << ans << endl;
}
int main() {
  init();
  solve();
  return 0;
}
