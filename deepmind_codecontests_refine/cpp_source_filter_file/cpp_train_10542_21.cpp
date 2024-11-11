#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> A[505];
pair<long long, long long> B[505];
long long C[505][505];
bool toLeft(pair<long long, long long> a, pair<long long, long long> b,
            pair<long long, long long> c) {
  if (c.second < a.second || c.second > b.second) return 0;
  return a.first * b.second + a.second * c.first + b.first * c.second -
             c.first * b.second - b.first * a.second - a.first * c.second >
         0;
}
bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
  return a.second < b.second;
}
signed main() {
  long long n, m;
  scanf("%lld", &(n));
  scanf("%lld", &(m));
  for (long long i = 0; i < n; i++) {
    scanf("%lld", &(A[i].first));
    scanf("%lld", &(A[i].second));
  }
  for (long long i = 0; i < m; i++) {
    scanf("%lld", &(B[i].first));
    scanf("%lld", &(B[i].second));
  }
  sort(A, A + n, cmp);
  for (long long i = 0; i < n; i++) {
    for (long long j = i + 1; j < n; j++) {
      for (long long k = 0; k < m; k++) {
        if (toLeft(A[i], A[j], B[k])) {
          C[i][j]++;
        }
      }
    }
  }
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = i + 1; j < n; j++) {
      for (long long k = j + 1; k < n; k++) {
        if (C[i][k] == C[i][j] + C[j][k]) {
          ans++;
        }
      }
    }
  }
  cout << ans << '\n';
}
