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
    const vector<vector<long long> >& first_matrix,
    const vector<vector<long long> >& second_matrix,
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
long long power(long long a, long long b,
                long long c = 1000000007LL * 1000000007LL) {
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
long long multiplicativeinverse(long long a, long long modulo) {
  return power(a, modulo - 2, modulo);
}
long long modu = 1000000007LL;
int encode(int a, int b) { return a * 4 + b; }
enum Color { W, second, R, Y };
int ok(int c1, int c2) {
  if (c1 == c2) return 0;
  if (c1 == W && c2 == Y) return 0;
  if (c1 == Y && c2 == W) return 0;
  if (c1 == R && c2 == second) return 0;
  if (c1 == second && c2 == R) return 0;
  return 1;
}
int ok(int c1, int c2, int c3) {
  if (c1 == second && c2 == W && c3 == R) return 0;
  if (c1 == R && c2 == W && c3 == second) return 0;
  return ok(c1, c2) && ok(c2, c3);
}
vector<vector<int> > flags;
vector<int> bawa;
void populate(int cnt) {
  if (cnt == 0) {
    flags.push_back(bawa);
  } else {
    for (int(i) = 0; (i) < (4); ++(i)) {
      bawa.push_back(i);
      populate(cnt - 1);
      bawa.pop_back();
    }
  }
}
long long solve(long long stripes) {
  if (stripes == 0) return 0LL;
  if (stripes == 1) return 4LL;
  vector<vector<long long> > matrix(32, vector<long long>(32, 0LL));
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      for (int k = 0; k < 4; ++k) {
        if (ok(i, j, k)) {
          matrix[encode(j, k)][encode(i, j)] += 1LL;
        }
      }
    }
  }
  for (int(i) = 0; (i) < (16); ++(i))
    for (int(j) = 0; (j) < (16); ++(j)) matrix[i + 16][j] = matrix[i][j];
  for (int(i) = 0; (i) < (16); ++(i)) matrix[i + 16][i + 16] = 1LL;
  vector<long long> init(32);
  vector<long long> initcpy;
  for (int(i) = 0; (i) < (4); ++(i))
    for (int(j) = 0; (j) < (4); ++(j))
      if (ok(i, j)) init[encode(i, j)] = init[encode(i, j) + 16] = 1LL;
  initcpy = init;
  vector<long long> full = MatrixPowerSolver(matrix, stripes - 2LL, init, modu);
  long long all = 0LL;
  for (int(i) = 0; (i) < (16); ++(i)) all = (all + full[i + 16]) % modu;
  long long sym = 0LL;
  if (stripes >= 3LL) sym = 8LL;
  if (stripes > 4LL) {
    long long target = (stripes - 1LL) / 2LL;
    vector<long long> half =
        MatrixPowerSolver(matrix, target - 2LL, initcpy, modu);
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 4; ++j)
        for (int k = 0; k < 4; ++k) {
          if (ok(i, j, k) && ok(j, k, j) && ok(k, j, i)) {
            sym = (sym + half[16 + encode(i, j)]) % modu;
          }
        }
  }
  long long asym = (all - sym + modu) % modu;
  asym = (asym * multiplicativeinverse(2LL, modu)) % modu;
  return asym + sym + 4LL;
}
int main() {
  long long l, r;
  cin >> l >> r;
  cout << ((solve(r) - solve(l - 1LL) + 4LL * modu) % modu) << endl;
  return 0;
}
