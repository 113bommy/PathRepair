#include <bits/stdc++.h>
using namespace std;
const double inf = 1e12;
int N, K;
vector<int> T;
vector<double> psum;
vector<double> invs, tt;
void prec() {
  psum.resize(N);
  for (int i = 0; i < N; i++) {
    psum[i] = (double)T[i];
    if (i != 0) psum[i] += psum[i - 1];
  }
  invs.resize(N);
  for (int i = 0; i < N; i++) {
    invs[i] = (double)1 / T[i];
    if (i != 0) invs[i] += invs[i - 1];
  }
  tt.resize(N);
  for (int i = 0; i < N; i++) {
    tt[i] = (double)psum[i] / T[i];
    if (i != 0) tt[i] += tt[i - 1];
  }
}
struct CHT {
  int pos;
  vector<double> M, B;
  void init() {
    pos = 0;
    M.clear();
    B.clear();
  }
  bool bad(int l1, int l2, int l3) {
    return (B[l3] - B[l1]) * (M[l1] - M[l2]) <
           (B[l2] - B[l1]) * (M[l1] - M[l3]);
  }
  void add(double m, double b) {
    M.push_back(m);
    B.push_back(b);
    while (M.size() >= 3 && bad(M.size() - 3, M.size() - 2, M.size() - 1)) {
      M.erase(M.end() - 2);
      B.erase(B.end() - 2);
    }
    if (M.size() >= 2) {
      if (M[M.size() - 1] == M[M.size() - 2]) {
        M.erase(M.end() - 2);
        B.erase(B.end() - 2);
      }
    }
  }
  double qur(double x) {
    if (pos >= M.size()) pos = M.size() - 1;
    while (pos < M.size() - 1 &&
           M[pos + 1] * x + B[pos + 1] < M[pos] * x + B[pos]) {
      pos++;
    }
    return M[pos] * x + B[pos];
  }
} cht;
vector<vector<double> > dp;
int main() {
  scanf("%d %d", &N, &K);
  T.resize(N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &T[i]);
  }
  prec();
  dp = vector<vector<double> >(K + 1, vector<double>(N, 0));
  for (int i = 0; i < N; i++) {
    dp[1][i] = tt[N - 1];
    if (i != 0)
      dp[1][i] -= tt[i - 1] + psum[i - 1] * (invs[N - 1] - invs[i - 1]);
  }
  for (int k = 2; k <= K; k++) {
    cht.init();
    cht.add(invs[N - 1], inf);
    for (int i = N; i--;) {
      double x = i == 0 ? 0 : (double)-psum[i - 1];
      dp[k][i] = cht.qur(x);
      dp[k][i] += i == 0 ? 0 : -tt[i - 1];
      dp[k][i] += i == 0 ? 0 : invs[i - 1] * (double)psum[i - 1];
      if (i != 0) cht.add(invs[i - 1], dp[k - 1][i] + tt[i - 1]);
    }
  }
  printf("%.10lf", dp[K][0]);
}
