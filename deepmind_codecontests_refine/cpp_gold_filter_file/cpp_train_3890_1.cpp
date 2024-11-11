#include <bits/stdc++.h>
using namespace std;
long long orig_matrix[4] = {3, 1, 0, 1};
long long n, m;
void matrix_multi(long long out_matrix[], long long out_matrix_copy[]) {
  long long temp[4];
  temp[0] = ((out_matrix[0] * out_matrix_copy[0]) % m +
             (out_matrix[1] * out_matrix_copy[2]) % m) %
            m;
  temp[1] = ((out_matrix[0] * out_matrix_copy[1]) % m +
             (out_matrix[1] * out_matrix_copy[3]) % m) %
            m;
  temp[2] = ((out_matrix[2] * out_matrix_copy[0]) % m +
             (out_matrix[3] * out_matrix_copy[2]) % m) %
            m;
  temp[3] = ((out_matrix[2] * out_matrix_copy[1]) % m +
             (out_matrix[3] * out_matrix_copy[3]) % m) %
            m;
  for (int i = 0; i < 4; i++) {
    out_matrix[i] = temp[i];
  }
}
void multiply(long long out_matrix[], long long n) {
  long long out_matrix_copy[4];
  long long out_matrix_copy_2[4];
  for (int i = 0; i < 4; i++) {
    out_matrix_copy[i] = out_matrix[i];
    out_matrix_copy_2[i] = out_matrix[i];
  }
  if (n == 1 || n == 0) return;
  if (n % 2 == 1) {
    matrix_multi(out_matrix_copy_2, out_matrix_copy);
    multiply(out_matrix_copy_2, n / 2);
    matrix_multi(out_matrix_copy_2, out_matrix_copy);
  } else {
    matrix_multi(out_matrix_copy_2, out_matrix_copy);
    multiply(out_matrix_copy_2, n / 2);
  }
  for (int i = 0; i < 4; i++) out_matrix[i] = out_matrix_copy_2[i];
  return;
}
int main() {
  cin >> n >> m;
  long long out_matrix[4] = {3, 1, 0, 1};
  if (n == 1) {
    cout << 2 % m;
    return 0;
  }
  multiply(out_matrix, n - 1);
  cout << ((out_matrix[0] * 2) % m + (out_matrix[1] * 2) % m) % m;
}
