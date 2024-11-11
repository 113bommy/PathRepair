#include <bits/stdc++.h>
using namespace std;
int L[2];
int R[2];
int H[2];
int P[2];
int T[2];
double W[2][1024][202];
double S[202];
double SS[1024];
void F(int a, int b) {
  memset((W[a]), 0, sizeof(W[a]));
  W[a][0][H[a]] += P[b] / 100.0;
  for (int(i) = (L[b]); (i) < (R[b] + 1); ++(i)) {
    int t = H[a] - i;
    if (t < 0) t = 0;
    W[a][0][t] += 1.0 / (R[b] - L[b] + 1) * (100 - P[b]) / 100.0;
  }
  for (int(i) = (1); (i) < (1024); ++(i)) {
    S[0] = W[a][i - 1][0];
    for (int(j) = (1); (j) < (H[a] + 1); ++(j))
      S[j] = S[j - 1] + W[a][i - 1][j];
    for (int(j) = (-200); (j) < (H[a] + 1); ++(j)) {
      if (j > 0) W[a][i][j] = W[a][i - 1][j] * P[b] / 100.0;
      int Min = j + L[b];
      int Max = j + R[b];
      if (Min <= H[a] && Max > 0) {
        if (Max > H[a]) Max = H[a];
        if (Min <= 0) Min = 1;
        if (Min <= Max) {
          double t = S[Max] - (Min == 0 ? 0.0 : S[Min - 1]);
          W[a][i][max(j, 0)] += t / (R[b] - L[b] + 1) * (100 - P[b]) / 100.0;
        }
      }
    }
  }
}
int main() {
  cin >> H[0] >> T[0] >> L[0] >> R[0] >> P[0];
  cin >> H[1] >> T[1] >> L[1] >> R[1] >> P[1];
  F(0, 1);
  F(1, 0);
  double res = 0.0;
  SS[0] = W[0][0][0];
  for (int(i) = (1); (i) < (1024); ++(i)) SS[i] = SS[i - 1] + W[0][i][0];
  for (int(i) = (0); (i) < (1024); ++(i)) {
    int t1 = i * T[0];
    int t2 = t1 / T[1];
    if (t1 % T[1] == 0) t2--;
    double p = 1.0;
    if (t2 >= 1024) t2 = 1024 - 1;
    if (t2 >= 0 && t2 < 1024) p = 1.0 - SS[t2];
    res += p * W[1][i][0];
  }
  printf("%0.9f\n", res);
  return 0;
}
