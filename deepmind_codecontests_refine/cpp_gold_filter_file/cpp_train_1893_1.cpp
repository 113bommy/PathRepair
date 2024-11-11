#include <bits/stdc++.h>
using namespace std;
string A[1000 + 10];
long long N, T, a, b, M;
long long B[1000000 + 10];
long long v[1000000 + 10];
long long dis[1000 + 10][1000 + 10];
void folyd(long long n) {
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      dis[i][j] = 1e18;
      if (A[i][j - 1] == '1') dis[i][j] = 1;
      if (i == j) dis[i][j] = 0;
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      for (long long k = 1; k <= n; k++) {
        dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
      }
    }
  }
}
signed main() {
  scanf("%I64d", &(N));
  ;
  for (long long i = 1; i <= N; i++) {
    cin >> A[i];
  }
  scanf("%I64d", &(M));
  ;
  folyd(N);
  for (long long i = 0; i < M; i++) {
    scanf("%I64d", &(B[i]));
    ;
  }
  long long k = 1;
  v[0] = B[0];
  v[1] = B[1];
  long long pre = B[0];
  long long p = B[1];
  for (long long i = 2; i < M; i++) {
    if (k > 0 && dis[pre][B[i]] > dis[pre][p]) {
      k--;
      pre = v[k - 1];
      p = v[k];
    }
    {
      v[++k] = B[i];
      pre = v[k - 1];
      p = v[k];
    }
  }
  cout << k + 1 << '\n';
  for (long long i = 0; i <= k; i++) {
    cout << v[i] << ' ';
  }
}
