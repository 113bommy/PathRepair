#include <bits/stdc++.h>
using namespace std;
const int Maxn = 100010 * 3;
int Mo = 998244353;
int P = 998244353, G = 3;
struct fft {
  long long FA[Maxn], FB[Maxn], tmp[Maxn];
  long long pw(long long a, int b, int Mo) {
    long long ans = 1;
    for (; b; b /= 2, a = a * a % Mo)
      if (b & 1) ans = a * ans % Mo;
    return ans;
  }
  int Getlen(int x) {
    while (x & (x - 1)) x += x & -x;
    return x;
  }
  void FFT(int N, long long *A, int ck) {
    long long w1 = pw(G, (P - 1) / N, P), Rev = pw(N, P - 2, P), Wx[Maxn];
    Wx[0] = 1;
    for (int i = 1; i <= N; i++) Wx[i] = w1 * Wx[i - 1] % P;
    for (int d = N / 2; d; d /= 2) {
      long long wn = 1, w = ck ? Wx[N - d] : Wx[d];
      for (int i = 0; i < N; i += d, wn = wn * w % P)
        for (int j = 0, p = 2 * i % N; j < d; j++)
          tmp[i + j] = (wn * A[p + d + j] + A[p + j]) % P;
      for (int i = 0; i < N; i++) A[i] = tmp[i];
    }
    if (ck)
      for (int i = 0; i < N; i++) A[i] = Rev * A[i] % P;
  }
  void Poly_Div(long long *A, long long *B, long long *D, long long *R, int nA,
                int nB) {
    long long FA[Maxn], FB[Maxn];
    for (int i = 0; i < nA; i++) FA[i] = A[nA - i];
    for (int i = 0; i < nB; i++) FB[i] = B[nB - i];
    int nD = nA - nB + 1, nR;
    Poly_Inv(nD, FB, D);
    Poly_Multi(FA, D, D, nD, nD);
    nR = Poly_Multi(FB, D, R, nB, nD) - nD;
    for (int i = 0; i < nR; i++) R[i] = (FA[i + nD] - R[i + nD]) % Mo;
    for (int i = 0; i < nD / 2; i++) swap(D[i], D[nD - i]);
    for (int i = 0; i < nR / 2; i++) swap(R[i], R[nR - i]);
  }
  int Poly_Multi(long long *A, long long *B, long long *C, int nA, int nB) {
    int nC = nA + nB - 1, m = Getlen(nC);
    for (int i = 0; i < m; i++) FA[i] = FB[i] = 0;
    for (int i = 0; i < nA; i++) FA[i] = A[i];
    for (int i = 0; i < nB; i++) FB[i] = B[i];
    FFT(m, FA, 0);
    FFT(m, FB, 0);
    for (int i = 0; i < m; i++) C[i] = FA[i] * FB[i] % P;
    FFT(m, C, 1);
    return nC;
  }
  void Poly_Inv(int t, long long *A, long long *B) {
    long long FA[Maxn];
    B[0] = pw(A[0], Mo - 2, Mo);
    for (int m = 2; m < t * 2; m <<= 1) {
      Poly_Multi(A, B, FA, m, m);
      Poly_Multi(FA, B, FA, m, m);
      for (int i = 0; i < m; i++) B[i] = (2 * B[i] - FA[i]) % Mo;
    }
  }
  void Poly_Sqrt(long long *A, long long *B, int t) {
    long long FB[Maxn] = {};
    int Rev2 = pw(2, Mo - 2, Mo);
    B[0] = 1;
    t <<= 1;
    for (int m = 2; m < t; m <<= 1) {
      for (int i = m / 2; i < m; i++) B[i] = 0;
      Poly_Inv(m, B, FB);
      Poly_Multi(A, FB, FB, m, m);
      for (int i = 0; i < m; i++) B[i] = (B[i] + FB[i]) % P * Rev2 % Mo;
    }
  }
} FFT;
int a, deg, N, M;
long long A[Maxn], B[Maxn], C[Maxn];
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &a);
    deg = max(deg, a);
    A[a] -= 4;
  }
  deg = max(deg, M) + 1;
  deg = FFT.Getlen(deg);
  A[0] = 1;
  FFT.Poly_Sqrt(A, B, deg);
  B[0]++;
  FFT.Poly_Inv(deg, B, A);
  for (int i = 1; i <= M; i++) cout << (Mo + A[i] * 2) % Mo << endl;
}
