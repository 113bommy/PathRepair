#include <bits/stdc++.h>
using namespace std;
int dadsadasda;
const int INF = 0x3f3f3f3f;
const long long LLINF = 1e18;
const int MAXN = 1e3 + 19;
const int MAXK = 1e6 + 10;
int N, M, K;
long long P;
int MAT[MAXN][MAXN];
long long SR[MAXN], SC[MAXN];
priority_queue<long long> PQR, PQC;
long long TR, TC;
long long A[MAXK], B[MAXK];
int main() {
  dadsadasda = scanf("%d %d %d", &N, &M, &K);
  dadsadasda = scanf("%lld", &P);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) dadsadasda = scanf("%d", &MAT[i][j]);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++) {
      SR[i] += MAT[i][j];
      SC[j] += MAT[i][j];
    }
  for (int i = 0; i < N; i++) PQR.push(SR[i]);
  for (int j = 0; j < M; j++) PQC.push(SC[j]);
  for (int i = 1; i < K + 1; i++) {
    A[i] += A[i - 1];
    B[i] += B[i - 1];
    long long aux = PQR.top();
    PQR.pop();
    A[i] += aux;
    PQR.push(aux - M * P);
    aux = PQC.top();
    PQC.pop();
    B[i] += aux;
    PQC.push(aux - N * P);
  }
  long long ans = -LLINF;
  for (int i = 0; i < K + 1; i++)
    ans = max(ans, A[i] + B[K - i] - i * (K - i) * P);
  printf("%lld\n", ans);
  return 0;
}
