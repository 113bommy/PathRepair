#include <bits/stdc++.h>
using namespace std;
int N, P, K, R, S;
vector<int> a, b, c, as, bs, cs;
vector<vector<vector<vector<int> > > > cc;
int dp(int n, int p, int k, int l) {
  if (n == N) return 0;
  int &ret = cc[n][p][k][l];
  if (ret != -1) return ret;
  if (k == 0) {
    ret = dp(n + 1, p, k, l);
    if (p) {
      int e = min(N - 1, n + K - 1);
      ret = max(ret, dp(n, p - 1, e - n + 1, 1));
      ret = max(ret, dp(n, p - 1, e - n + 1, 0));
    }
    return ret;
  }
  ret = (l ? a[n] : b[n]) + dp(n + 1, p, k - 1, l);
  int e = min(N - 1, n + K - 1);
  if (p) {
    ret = max(ret, cs[n + k - 1] - cs[n] + c[n] +
                       dp(n + k, p - 1, e - (n + k) + 1, l ^ 1));
    if (e - (n + k) == 0)
      max(ret,
          cs[n + k - 1] - cs[n] + c[n] + dp(n + k, p - 1, e - (n + k) + 1, l));
  }
  return ret;
}
int main() {
  scanf("%d %d %d", &N, &P, &K);
  scanf("%d", &R);
  a = vector<int>(N, 0);
  for (int i = 0; i < R; i++) {
    int t;
    scanf("%d", &t);
    a[--t] = 1;
  }
  scanf("%d", &S);
  b = vector<int>(N, 0);
  for (int i = 0; i < S; i++) {
    int t;
    scanf("%d", &t);
    b[--t] = 1;
  }
  c = vector<int>(N, 0);
  for (int i = 0; i < N; i++) {
    c[i] = a[i] | b[i];
  }
  as.resize(N);
  for (int i = 0; i < N; i++) {
    as[i] = a[i];
    if (i) as[i] += as[i - 1];
  }
  bs.resize(N);
  for (int i = 0; i < N; i++) {
    bs[i] = b[i];
    if (i) bs[i] += bs[i - 1];
  }
  cs.resize(N);
  for (int i = 0; i < N; i++) {
    cs[i] = c[i];
    if (i) cs[i] += cs[i - 1];
  }
  cc = vector<vector<vector<vector<int> > > >(
      N, vector<vector<vector<int> > >(
             min(P + 1, 2 * (N / K) + 1),
             vector<vector<int> >(K + 1, vector<int>(2, -1))));
  printf("%d", dp(0, min(P, 2 * (N / K)), 0, 0));
}
