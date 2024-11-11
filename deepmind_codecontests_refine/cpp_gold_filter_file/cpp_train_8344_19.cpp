#include <bits/stdc++.h>
using namespace std;
vector<vector<long long> > mat;
vector<vector<long long> > res;
void init_mat() {
  mat.assign(3, vector<long long>(3, 0));
  for (long long i = 0; i < 3; i++) mat[0][i] = 1;
  mat[1][0] = 1;
  mat[2][1] = 1;
}
void multiply(vector<vector<long long> >& a, vector<vector<long long> >& b) {
  vector<vector<long long> > pro;
  pro.assign(3, vector<long long>(3, 0));
  for (long long i = 0; i < 3; i++) {
    for (long long j = 0; j < 3; j++) {
      for (long long k = 0; k < 3; k++) {
        pro[i][j] += (a[i][k] % (1000000007 - 1) * b[k][j] % (1000000007 - 1)) %
                     (1000000007 - 1);
        pro[i][j] %= 1000000007 - 1;
      }
    }
  }
  a = pro;
}
void display(vector<vector<long long> > mm) {
  for (long long i = 0; i < 3; i++) {
    for (long long j = 0; j < 3; j++) cout << mm[i][j] << " ";
    cout << endl;
  }
  cout << endl << endl;
}
void rr(long long p) {
  res.assign(3, vector<long long>(3, 0));
  for (long long i = 0; i < 3; i++) res[i][i] = 1;
  while (p > 0) {
    if (p % 2 != 0) multiply(res, mat);
    p /= 2;
    multiply(mat, mat);
  }
}
long long rr_num(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b % 2 != 0) res = (res % 1000000007 * a % 1000000007) % 1000000007;
    b /= 2;
    a = (a % 1000000007 * a % 1000000007) % 1000000007;
  }
  return res;
}
long long BSGS(long long b) {
  long long n = (long long)sqrt(1000000007) + 1;
  unordered_map<long long, long long> value;
  for (long long i = n; i >= 1; --i) value[rr_num(5, i * n)] = i;
  for (long long j = 0; j < n; ++j) {
    long long cur = (rr_num(5, j) * b) % 1000000007;
    if (value[cur]) {
      long long ans = value[cur] * n - j;
      if (ans < 1000000007) return ans;
    }
  }
  return -1;
}
int32_t main() {
  long long n, f1, f2, f3, c;
  cin >> n >> f1 >> f2 >> f3 >> c;
  init_mat();
  rr(n - 3);
  f3 = (f3 % 1000000007 * rr_num(c, 3) % 1000000007) % 1000000007;
  f2 = (f2 % 1000000007 * rr_num(c, 2) % 1000000007) % 1000000007;
  f1 = (f1 % 1000000007 * rr_num(c, 1) % 1000000007) % 1000000007;
  long long T3 = BSGS(f3);
  long long T2 = BSGS(f2);
  long long T1 = BSGS(f1);
  long long ff = T3 * res[0][0] + T2 * res[0][1] + T1 * res[0][2];
  ff = rr_num(5, ff);
  long long inv = rr_num(c, 1000000007 - 2);
  ff = (ff % 1000000007 * rr_num(inv, n) % 1000000007) % 1000000007;
  cout << ff % 1000000007 << endl;
  return 0;
}
