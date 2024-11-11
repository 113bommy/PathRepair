#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int z, T;
  cin >> T;
  for (z = 1; z <= T; z++) {
    long long int N, M;
    cin >> N >> M;
    long long int a, b, c, i, j, k, A[N], dp[N];
    queue<long long int> q;
    bool x[N];
    for (i = 0; i < N; i++) {
      x[i] = true;
      dp[i] = 1e10;
      cin >> A[i];
      if (A[i] == 0) {
        x[i] = false;
        dp[i] = 0;
        q.push(i);
      }
    }
    while (q.size() != 0) {
      a = q.front();
      x[a] = false;
      q.pop();
      if (a - M >= 0) {
        if (x[a - M]) {
          dp[a - M] = dp[a] + 1;
          x[a - M] = false;
          q.push(a - M);
        }
      } else {
        b = N - (M - a);
        if (x[b]) {
          dp[b] = dp[a] + 1;
          x[b] = false;
          q.push(b);
        }
      }
    }
    a = 0;
    for (i = 0; i < N; i++) {
      a = max(a, dp[i]);
    }
    if (a >= 1e10) {
      cout << "-1\n";
    } else {
      cout << a << "\n";
    }
  }
  return 0;
}
