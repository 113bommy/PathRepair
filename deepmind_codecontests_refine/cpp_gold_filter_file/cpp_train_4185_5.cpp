#include <bits/stdc++.h>
using namespace std;
using namespace std;
inline long long pow_mod(long long X, long long N, long long mod) {
  long long res = 1;
  while (N) {
    if (N & 1) res = res * X % mod;
    X = X * X % mod;
    N >>= 1;
  }
  return res;
}
const long long SI = 1e5 + 100;
const bool DBG = 1;
int N, M;
vector<int> A[SI];
long long tot = 0;
long long YY[SI];
long long XX[SI];
vector<long long> Y, X;
long long get3() {
  long long res = 0;
  for (int i = 1; i <= N; i++) {
    long long temp = YY[i];
    X.clear();
    for (int j = 1; j <= M; j++) {
      X.push_back(XX[j] - A[i][j]);
    }
    sort(X.begin(), X.end(), greater<long long>());
    res = max(res, temp + X[0] + X[1] + X[2]);
  }
  for (int j = 1; j <= M; j++) {
    long long temp = XX[j];
    Y.clear();
    for (int i = 1; i <= N; i++) Y.push_back(YY[i] - A[i][j]);
    sort(Y.begin(), Y.end(), greater<long long>());
    res = max(res, temp + Y[0] + Y[1] + Y[2]);
  }
  return res;
}
long long get2() {
  long long res = 0, temp, b1, b2, v;
  if (N < M) {
    for (int l = 1; l <= N; l++)
      for (int r = l + 1; r <= N; r++) {
        temp = YY[l] + YY[r];
        b1 = b2 = 0;
        for (int j = 1; j <= M; j++) {
          v = XX[j] - A[l][j] - A[r][j];
          if (v >= b1) {
            b2 = b1;
            b1 = v;
          } else if (v > b2)
            b2 = v;
        }
        res = max(res, temp + b1 + b2);
      }
  } else {
    for (int l = 1; l <= M; l++)
      for (int r = l + 1; r <= M; r++) {
        temp = XX[l] + XX[r];
        b1 = b2 = 0;
        for (int i = 1; i <= N; i++) {
          v = YY[i] - A[i][l] - A[i][r];
          if (v >= b1) {
            b2 = b1;
            b1 = v;
          } else if (v > b2)
            b2 = v;
        }
        res = max(res, temp + b1 + b2);
      }
  }
  return res;
}
long long get4() {
  Y.clear();
  X.clear();
  for (int i = 1; i <= N; i++) Y.push_back(YY[i]);
  for (int j = 1; j <= M; j++) X.push_back(XX[j]);
  sort(Y.begin(), Y.end(), greater<long long>());
  sort(X.begin(), X.end(), greater<long long>());
  long long res =
      max(1ll * Y[0] + Y[1] + Y[2] + Y[3], 1ll * X[0] + X[1] + X[2] + X[3]);
  return res;
}
int main() {
  scanf("%d %d", &N, &M);
  for (int i = 1; i <= N; i++) {
    A[i].push_back(-1);
    int v;
    for (int j = 1; j <= M; j++) {
      scanf("%d", &v);
      A[i].push_back(v);
      tot += v;
    }
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      YY[i] += A[i][j];
      XX[j] += A[i][j];
    }
  }
  if (N <= 4 || M <= 4) {
    printf("%I64d", tot);
    return 0;
  }
  long long ans = 0;
  ans = max(ans, get4());
  ans = max(ans, get3());
  ans = max(ans, get2());
  printf("%I64d", ans);
  return 0;
}
