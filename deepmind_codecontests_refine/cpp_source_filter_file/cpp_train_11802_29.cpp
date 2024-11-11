#include <bits/stdc++.h>
using namespace std;
class Matrix {
 private:
  int n, m;
  long long MOD;
  vector<vector<long long> > data;
  long long mod(long long x, long long md) {
    while (x < 0) x += md;
    if (x < md)
      return x;
    else
      return x % md;
  }

 public:
  Matrix() {
    n = m = 0;
    MOD = 1000000007LL;
  }
  Matrix(int n_, int m_) {
    n = n_;
    m = m_;
    data = vector<vector<long long> >(n, vector<long long>(m, 0LL));
    MOD = 1000000007LL;
  }
  Matrix(int n_, int m_, long long MOD_) {
    n = n_;
    m = m_;
    MOD = MOD_;
    data = vector<vector<long long> >(n, vector<long long>(m, 0LL));
  }
  int get_row() { return n; }
  int get_col() { return m; }
  void set(int row, int col, long long value) { data[row][col] = value; }
  long long get(int row, int col) { return data[row][col]; }
  Matrix IdentSq(int z) {
    Matrix a(z, z);
    for (int i = 0; i < (int)z; i++) a.set(i, i, 1);
    return a;
  }
  Matrix operator*(Matrix a) {
    if (m != a.get_row()) return Matrix(1, 1);
    Matrix b(n, a.get_col(), MOD);
    long long val = 0;
    for (int i = 0; i < (int)n; i++)
      for (int j = 0; j < a.get_col(); j++) {
        for (int k = 0; k < m; k++) {
          val = mod(b.data[i][j] + mod(data[i][k] * a.data[k][j], MOD), MOD);
          b.set(i, j, val);
        }
      }
    return b;
  }
  Matrix operator^(long long P) {
    if (P == 0LL) return IdentSq(m);
    if (P == 1LL) return *this;
    if (P & 1LL) return (*this) * ((*this) ^ (P - 1));
    Matrix a = (*this) ^ (P / 2);
    return a * a;
  }
};
int main() {
  long long m, l, r, k;
  scanf("%I64d", &m);
  scanf("%I64d", &l);
  scanf("%I64d", &r);
  scanf("%I64d", &k);
  vector<long long> possible_ans;
  for (long long a = 1LL; a * a <= r; a++) {
    possible_ans.push_back(a);
    possible_ans.push_back(r / a);
  }
  for (long long a = 1LL; a * a <= l; a++) {
    if (l % a == 0)
      possible_ans.push_back(l / a);
    else if (a)
      possible_ans.push_back(l / (a - 1));
  }
  long long ans = 0, l_up, r_down;
  for (int i = 0; i < (int)possible_ans.size(); i++) {
    l_up = (l / possible_ans[i]) + (l % possible_ans[i] != 0);
    r_down = (r / possible_ans[i]);
    if (r_down - l_up + 1 >= k) {
      ans = max(ans, possible_ans[i]);
    }
  }
  Matrix a(2, 2, m);
  a.set(0, 0, 1LL);
  a.set(0, 1, 1LL);
  a.set(1, 0, 1LL);
  a.set(1, 1, 0LL);
  a = a ^ ans;
  printf("%I64d\n", a.get(0, 1));
  return 0;
}
