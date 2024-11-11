#include <bits/stdc++.h>
using namespace std;
int M = 1e9 + 7;
long long T[2][2] = {{6, -8}, {1, 0}};
void matMul(long long A[][2], long long B[][2]) {
  long long C[2][2];
  C[0][0] = ((A[0][0] * B[0][0]) % M + (A[0][1] * B[1][0]) % M) % M;
  C[0][1] = ((A[0][0] * B[0][1]) % M + (A[0][1] * B[1][1]) % M) % M;
  C[1][0] = ((A[1][0] * B[0][0]) % M + (A[1][1] * B[1][0]) % M) % M;
  C[1][1] = ((A[1][0] * B[0][1]) % M + (A[1][1] * B[1][1]) % M) % M;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) A[i][j] = (C[i][j] + M) % M;
}
void modexp(long long n) {
  long long A[2][2] = {{0, 1}, {1, 0}};
  while (n) {
    if (n & 1) matMul(A, T);
    matMul(T, T);
    n /= 2;
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      T[i][j] = A[i][j];
    }
  }
}
int main() {
  long long n, ans;
  cin >> n;
  if (n > 2) modexp(n);
  if (n == 0)
    ans = 0;
  else if (n == 1)
    ans = 3;
  else
    ans = ((3 * T[0][0]) % M + (T[0][1] % M)) % M;
  cout << (ans + M) % M;
}
