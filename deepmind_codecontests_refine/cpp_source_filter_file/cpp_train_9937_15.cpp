#include <bits/stdc++.h>
using namespace std;
int main() {
  long long A[100001], B[100001];
  long long m, n;
  cin >> m >> n;
  long long maxi = 0, sumA = 0, sumB = 0;
  long long maxtable = 0;
  char table = 'A';
  for (int i = 0; i < m; i++) {
    cin >> A[i];
    if (A[i] > maxi) maxi = A[i], maxtable = i, table = 'A';
    sumA += A[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> B[i];
    if (B[i] > maxi) maxi = B[i], maxtable = i, table = 'B';
    sumB += B[i];
  }
  int c_operations = 0;
  if (table == 'A') {
    for (int i = 0; i < m; i++)
      if (maxtable != i) c_operations += min(A[i], sumB);
    c_operations += sumB;
  } else {
    for (int i = 0; i < n; i++)
      if (maxtable != i) c_operations += min(B[i], sumA);
    c_operations += sumA;
  }
  cout << c_operations;
  return 0;
}
