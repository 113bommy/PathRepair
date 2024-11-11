#include <bits/stdc++.h>
using namespace std;
long long iMatrixMultiply(long long multiplicant1, long long multiplicant2,
                          long long ivalue = (long long)1023123123 *
                                             (long long)1023123123) {
  return (multiplicant1 * multiplicant2) % ivalue;
}
long long iMatrixAdd(long long operand1, long long operand2,
                     long long ivalue = (long long)1023123123 *
                                        (long long)1023123123) {
  return (operand1 + operand2) % ivalue;
}
vector<vector<long long> > MatrixIdentity(int row_and_col) {
  vector<vector<long long> > ret = vector<vector<long long> >(
      row_and_col, vector<long long>(row_and_col, 0));
  for (int(i) = 0; (i) < (row_and_col); ++(i)) ret[i][i] = 1LL;
  return ret;
}
vector<vector<long long> > MatrixMultiply(
    vector<vector<long long> > first_matrix,
    vector<vector<long long> > second_matrix,
    long long ivalue = (long long)1023123123 * (long long)1023123123) {
  vector<vector<long long> > ret;
  if (first_matrix[0].size() != second_matrix.size())
    printf("ukuran salah untuk perkalian. %d %d x %d %d\n", first_matrix.size(),
           first_matrix[0].size(), second_matrix.size(),
           second_matrix[0].size());
  for (int(i) = 0; (i) < (((int)first_matrix.size())); ++(i)) {
    vector<long long> ret_row_i;
    for (int(j) = 0; (j) < (((int)second_matrix[0].size())); ++(j)) {
      long long value = 0LL;
      for (int(k) = 0; (k) < (((int)second_matrix.size())); ++(k)) {
        value = iMatrixAdd(
            value,
            iMatrixMultiply(first_matrix[i][k], second_matrix[k][j], ivalue),
            ivalue);
      }
      ret_row_i.push_back(value);
    }
    ret.push_back(ret_row_i);
  }
  return ret;
}
vector<vector<long long> > MatrixPower(
    vector<vector<long long> > matrix, long long pangkat,
    long long ivalue = (long long)1023123123 * (long long)1023123123) {
  vector<vector<long long> > ret = MatrixIdentity(((int)matrix.size()));
  while (pangkat > 0LL) {
    if (pangkat % 2LL) {
      ret = MatrixMultiply(ret, matrix, ivalue);
    }
    pangkat /= 2LL;
    matrix = MatrixMultiply(matrix, matrix, ivalue);
  }
  return ret;
}
vector<long long> MatrixPowerSolver(vector<vector<long long> > matrix,
                                    long long pangkat,
                                    vector<long long> operand_vector,
                                    long long ivalue = (long long)1023123123 *
                                                       (long long)1023123123) {
  vector<vector<long long> > parsed_operand_vector(((int)operand_vector.size()),
                                                   vector<long long>(1, 0));
  for (int(i) = 0; (i) < (((int)operand_vector.size())); ++(i))
    parsed_operand_vector[i][0] = operand_vector[i];
  vector<vector<long long> > unparsed_ret = MatrixMultiply(
      MatrixPower(matrix, pangkat, ivalue), parsed_operand_vector, ivalue);
  vector<long long> ret(((int)unparsed_ret.size()), 0);
  for (int(i) = 0; (i) < (((int)unparsed_ret.size())); ++(i))
    ret[i] = unparsed_ret[i][0];
  return ret;
}
long long fibo(long long x, long long ivalue = (long long)1023123123 *
                                               (long long)1023123123) {
  if (x == 0) return 0 % ivalue;
  if (x == 1) return 1 % ivalue;
  if (x == 2) return 1 % ivalue;
  vector<vector<long long> > matrix(2, vector<long long>(2));
  matrix[0][0] = 0LL;
  matrix[0][1] = 1LL;
  matrix[1][0] = 1LL;
  matrix[1][1] = 1LL;
  vector<long long> init(2);
  init[0] = 0;
  init[1] = 1;
  vector<long long> hasil = MatrixPowerSolver(matrix, x - 1, init, ivalue);
  return hasil[1];
}
long long power(long long a, long long b, long long c) {
  long long ret = 1;
  long long kali = a;
  while (b > 0LL) {
    if (b % 2LL) {
      ret *= kali;
      ret %= c;
    }
    b /= 2LL;
    kali *= kali;
    kali %= c;
  }
  return ret;
}
int main() {
  int n;
  cin >> n;
  long long x, y;
  cin >> x >> y;
  long long p;
  cin >> p;
  vector<long long> m;
  for (int(i) = 0; (i) < (n); ++(i)) {
    int buf;
    scanf("%d", &buf);
    m.push_back(buf);
  }
  if (n == 1) {
    cout << m[0] % p << endl;
    return 0;
  }
  long long xnormal = power(3LL, x, p) % p;
  long long xspecial = ((power(3LL, x, 2LL * p) + 1LL) / 2LL) % p;
  long long ynormal = power(3LL, y, p) % p;
  long long yspecial = ((power(3LL, y, 2LL * p) + 1LL) / 2LL) % p;
  long long sum = 0LL;
  for (int(i) = 0; (i) < (n); ++(i)) {
    if (i == 0 || i == n - 1) {
      sum = (sum + ((m[i] * xspecial) % p)) % p;
      continue;
    }
    sum = (sum + ((m[i] * xnormal) % p)) % p;
  }
  long long smallest = (m[0]) % p;
  long long biggest =
      ((fibo(x, p) * m[n - 2]) % p) + ((fibo(x + 1LL, p) * m[n - 1]) % p);
  biggest %= p;
  sum -= smallest;
  sum -= biggest;
  while (sum < 0LL) sum += p;
  sum = (sum * ynormal) % p;
  sum = (sum + ((smallest * yspecial) % p)) % p;
  sum = (sum + ((biggest * yspecial) % p)) % p;
  cout << sum << endl;
  return 0;
}
