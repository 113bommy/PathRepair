#include <bits/stdc++.h>
using namespace std;
typedef long long Matrix[17][17];
void Print(Matrix &M, int N) {
  for (int i = 0; i < (N); i++) {
    for (int j = 0; j < (N); j++) printf("%lld ", M[i][j]);
    printf("\n");
  }
}
void Copy(Matrix &A, Matrix &B, int N) {
  for (int i = 0; i < (N); i++)
    for (int j = 0; j < (N); j++) A[i][j] = B[i][j];
}
void Clear(Matrix &M, int N) {
  for (int i = 0; i < (N); i++)
    for (int j = 0; j < (N); j++) M[i][j] = 0;
}
void One(Matrix &M, int N) {
  Clear(M, N);
  for (int i = 0; i < (N); i++) M[i][i] = 1;
}
void Mul(Matrix &A, Matrix &B, int N) {
  Matrix R;
  Clear(R, N);
  for (int i = 0; i < (N); i++)
    for (int j = 0; j < (N); j++)
      for (int k = 0; k < (N); k++)
        R[i][j] = (R[i][j] + A[i][k] * B[k][j]) % 1000000007LL;
  Copy(A, R, N);
}
void Pow(Matrix &M, int N, int Pow) {
  Matrix R;
  Clear(R, N);
  for (int i = 0; i < (N); i++) R[i][i] = 1;
  while (Pow) {
    if (Pow & 1) Mul(R, M, N);
    Mul(M, M, N);
    Pow >>= 1;
  }
  Copy(M, R, N);
}
Matrix A, B;
int index(int first, int second) { return first * 4 + second; }
bool valid2(int a, int b) {
  if (a == b) return false;
  if ((a & 2) == (b & 2) && (a & 1) != (b & 1)) return false;
  return true;
}
bool valid3(int a, int b, int c) {
  if (!valid2(b, c)) return false;
  if ((a == 0 && b == 2 && c == 1) || (a == 1 && b == 2 && c == 0))
    return false;
  return true;
}
long long base[16];
long long getSum(long long N) {
  if (N == 0) return 0;
  Copy(B, A, 17);
  Pow(B, 17, N - 1);
  long long sum = 0;
  for (int i = 0; i < (17); i++)
    sum = (sum + base[i] * B[16][i]) % 1000000007LL;
  return sum;
}
long long getPal(long long N) { return getSum((N + 1) / 2); }
int main() {
  for (int a = 0; a < (4); a++)
    for (int b = 0; b < (4); b++)
      for (int c = 0; c < (4); c++)
        if (valid3(a, b, c)) A[index(b, c)][index(a, b)] = 1;
  for (int i = 0; i < (17); i++) A[16][i] = 1;
  for (int a = 0; a < (4); a++)
    for (int b = 0; b < (4); b++)
      if (valid2(a, b)) base[index(a, b)] = 1;
  base[16] = 4;
  long long Dw, Up;
  cin >> Dw >> Up;
  long long sum = (getSum(Up) - getSum(Dw - 1) + 1000000007LL) % 1000000007LL;
  long long pal = (getPal(Up) - getPal(Dw - 1) + 1000000007LL) % 1000000007LL;
  cout << (sum + pal) % 1000000007LL * 500000004LL % 1000000007LL << endl;
  return 0;
}
