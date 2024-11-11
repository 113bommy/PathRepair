#include <bits/stdc++.h>
using namespace std;
const int P = 10007;
char S[202];
int n;
int Reverse[P];
const int I26 = 3464;
const int d = (25 * I26) % P;
const int e = (24 * I26) % P;
int Power(int a, int x) {
  if (x == 0) return 1;
  int b = Power(a, x / 2);
  b = (b * b) % P;
  if ((x & 1) == 1) b = (a * b) % P;
  return b;
}
int Count(int K, int m, int m_) {
  if (K < 0 || m < 0 || m_ < 0) return 0;
  int tmp, D[P], E[P], SD[P], SE[P];
  D[0] = E[0] = SD[0] = SE[0] = 1;
  if (m > 0) {
    for (int i = 1; i < P; i++) {
      tmp = (d * D[i - 1]) % P;
      tmp = (tmp * (i + m - 1)) % P;
      D[i] = (tmp * Reverse[i]) % P;
      SD[i] = (SD[i - 1] + D[i]) % P;
    }
  }
  if (m_ > 0) {
    for (int i = 1; i < P; i++) {
      tmp = (e * E[i - 1]) % P;
      tmp = (tmp * (i + m_ - 1)) % P;
      E[i] = (tmp * Reverse[i]) % P;
      SE[i] = (SE[i - 1] + E[i]) % P;
    }
  }
  int k = K / P, r = K % P;
  int dk = Power(d, k), ek = Power(e, k);
  if (m == 0) {
    tmp = ((ek - 1) * (P - 13)) % P;
    tmp = (tmp * SE[P - 1]) % P;
    tmp = (ek * SE[r] + tmp) % P;
    return (tmp * Power(26, K)) % P;
  }
  if (m_ == 0) {
    tmp = ((dk - 1) * (P - 26)) % P;
    tmp = (tmp * SD[P - 1]) % P;
    tmp = (dk * SD[r] + tmp) % P;
    return (tmp * Power(26, K)) % P;
  }
  int A, B = 0, C = 0;
  A = (SD[P - 1] * SE[P - 1]) % P;
  for (int i = r + 2; i < P; i++) {
    tmp = SE[P - 1] - SE[P + r - i] + P;
    tmp = (tmp * D[i]) % P;
    B = (B + tmp) % P;
  }
  for (int i = 0; i <= r; i++) {
    tmp = D[i] * SE[r - i];
    C = (C + tmp) % P;
  }
  int a, b, c;
  a = (dk * d + P - 1) % P;
  a = (a * (P - 26)) % P;
  tmp = (ek * e + P - 1) % P;
  tmp = (tmp * (P - 13)) % P;
  a = (a - tmp + P) % P;
  b = (ek - dk + P) % P;
  tmp = (ek * e) % P;
  c = (dk * d + P - tmp) % P;
  A = (A * a) % P;
  B = (B * b) % P;
  C = (C * c) % P;
  return (Power(26, K + 1) * ((A + B + C) % P)) % P;
}
int L, T0[200][201][101], T1[200][201][101];
int main() {
  for (int i = 1; i < P; i++) Reverse[i] = Power(i, P - 2);
  cin >> S >> n;
  while (S[L] != 0) L++;
  n += L;
  for (int i = 0; i < L; i++) T1[i][1][0] = T0[i][0][0] = 1;
  for (int k = 2; k <= L; k++)
    for (int i = 0; i + k <= L; i++)
      if (S[i] == S[i + k - 1])
        for (int t = 1; t <= 100; t++) {
          T0[i][k][t] = T0[i + 1][k - 2][t - 1];
          T1[i][k][t] = T1[i + 1][k - 2][t - 1];
        }
      else
        for (int t = 0; t <= 100; t++) {
          T0[i][k][t] = (T0[i][k - 1][t] + T0[i + 1][k - 1][t]) % P;
          T1[i][k][t] = (T1[i][k - 1][t] + T1[i + 1][k - 1][t]) % P;
        }
  int ans = 0;
  for (int t = 0; t <= 100; t++) {
    int tmp = (Count(n / 2 - L + t, t, L - 2 * t) * T0[0][L][t]) % P;
    ans = (ans + 26 * (n & 1) * tmp) % P;
    tmp = (Count((n + 1) / 2 - L + t, t + 1, L - 2 * t - 1) * T1[0][L][t]) % P;
    ans = (ans + tmp) % P;
  }
  cout << ans;
}
