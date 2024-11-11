#include <bits/stdc++.h>
using namespace std;
unsigned long long N;
int K;
vector<vector<unsigned long long> > R[40];
vector<vector<unsigned long long> > D[100][40];
void mat_init(vector<vector<unsigned long long> >& A, int a, int b) {
  A.resize(a);
  for (int i = 0; i < a; i++) A[i].resize(b, 0);
}
vector<vector<unsigned long long> > mul(
    const vector<vector<unsigned long long> >& A,
    const vector<vector<unsigned long long> >& B) {
  vector<vector<unsigned long long> > C(
      A.size(), vector<unsigned long long>(B[0].size()));
  for (int i = 0; i < A.size(); i++)
    for (int k = 0; k < B.size(); k++)
      for (int j = 0; j < B[0].size(); j++)
        C[i][j] =
            (C[i][j] + (unsigned long long)A[i][k] * B[k][j]) % 1000000007;
  return C;
}
void show_mat(const vector<vector<unsigned long long> >& A) {
  for (int i = 0; i < A.size(); i++) {
    for (int j = 0; j < A[0].size(); j++) {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}
int main() {
  cin >> N >> K;
  int cnt = 0;
  unsigned long long nN = 1;
  while (nN <= N) {
    nN *= K;
    cnt++;
  }
  nN /= K;
  vector<int> d(cnt);
  for (int i = 0; i < cnt; i++) {
    d[i] = N / nN;
    N %= nN;
    nN /= K;
  }
  for (int i = 0; i <= K; i++) mat_init(R[i], K + 1, K + 1);
  for (int i = 0; i <= cnt; i++)
    for (int j = 0; j < K; j++) mat_init(D[i][j], K + 1, K + 1);
  R[0][K][K] = 1;
  R[1][K][K] = 1;
  for (int j = 0; j < K; j++) R[0][j][j] = 1;
  for (int j = 0; j < K; j++) R[1][(j + K - 1) % K][j] = 1;
  for (int j = 2; j <= K; j++) R[j] = mul(R[j - 1], R[1]);
  for (int j = 0; j <= K; j++) D[0][0][j][j] = 1;
  for (int j = 0; j <= K; j++) D[0][0][j][0] = 1;
  for (int i = 0; i <= cnt; i++) {
    for (int j = 1; j < K; j++) {
      D[i][j] = mul(D[i][j - 1], mul(mul(R[K - j], D[i][0]), R[j]));
    }
    D[i + 1][0] = D[i][K - 1];
  }
  vector<vector<unsigned long long> > ans(1,
                                          vector<unsigned long long>(K + 1, 0));
  ans[0][K] = 1;
  int md = 0;
  for (int i = 0; i < cnt; i++) {
    if (d[i] != 0)
      ans = mul(ans, mul(mul(R[K - md], D[cnt - i - 1][d[i] - 1]), R[md]));
    md += d[i];
    md %= K;
  }
  unsigned long long res = 0;
  for (int i = 0; i < K + 1; i++)
    res = (res + (unsigned long long)ans[0][i]) % 1000000007;
  cout << res << endl;
}
