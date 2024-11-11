#include <bits/stdc++.h>
using namespace std;
int N;
vector<long long> temp;
long long modexp(int n) {
  long long ans = 1, x = 10;
  while (n > 0) {
    if (n % 2 == 1) ans = (ans * x) % N;
    x = (x * x) % N;
    n /= 2;
  }
  return ans;
}
void mul(vector<long long>& C, vector<long long>& A, vector<long long>& B,
         int n) {
  int i, j, k;
  long long p = modexp(n);
  for (i = 0; i < N; i++) temp[i] = 0;
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++) {
      k = (i * p + j) % N;
      temp[k] = (temp[k] + A[i] * B[j]) % 1000000007;
    }
  for (i = 0; i < N; i++) C[i] = temp[i];
}
int main() {
  int n, b, m, i, j, k;
  vector<long long> A, B;
  scanf("%d%d%d%d", &n, &b, &k, &N);
  A.resize(N);
  B.resize(N);
  temp.resize(N);
  while (n--) {
    scanf("%d", &i);
    i %= N;
    A[i]++;
  }
  B[0] = 1;
  for (i = 1; b > 0; b /= 2, i *= 2) {
    if (b % 2 == 1) mul(B, B, A, i);
    mul(A, A, A, i);
  }
  cout << B[k] << '\n';
  return 0;
}
