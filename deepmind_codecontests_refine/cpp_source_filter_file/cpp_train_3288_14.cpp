#include <bits/stdc++.h>
using namespace std;
vector<bitset<500> > A[61], B[61];
int N, M;
vector<bitset<500> > mul(vector<bitset<500> > &X, vector<bitset<500> > &Y) {
  vector<bitset<500> > ret(X.size()), YT(Y.size());
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) YT[i][j] = Y[j][i];
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) ret[i][j] = (X[i] & YT[j]).any();
  return ret;
}
int main() {
  scanf("%d %d", &N, &M);
  for (int i = 0; i < 60; i++) {
    A[i].resize(N);
    B[i].resize(N);
  }
  for (int i = 0; i < M; i++) {
    int u, v, t;
    scanf("%d %d %d", &u, &v, &t);
    u--;
    v--;
    if (t == 0)
      A[0][u][v] = 1;
    else
      B[0][u][v] = 1;
  }
  for (int i = 1; i <= 60; i++) {
    A[i] = mul(A[i - 1], B[i - 1]);
    B[i] = mul(B[i - 1], A[i - 1]);
  }
  long long int lpath = 0;
  vector<bitset<500> > Ac(N);
  Ac[0][0] = 1;
  int cnt = 0;
  for (long long int i = 60; i >= 0; i--) {
    bool possib = false;
    vector<bitset<500> > ret;
    if (cnt % 2 == 0)
      ret = mul(Ac, A[i]);
    else
      ret = mul(Ac, B[i]);
    for (int j = 0; j < N; j++)
      if (ret[j].any()) possib = true;
    if (possib) {
      Ac = ret;
      lpath += (1LL << i);
      cnt += 1;
    }
  }
  if (lpath > 1e8)
    printf("-1\n");
  else
    printf("%lld\n", lpath);
  return 0;
}
