#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(nullptr));
const long long MAXN = 110, M = 998244353, SQ = 30000;
long long n, m, k, N;
struct Matrix {
  int a[MAXN][MAXN];
  Matrix& operator*(const Matrix& b) const {
    Matrix& rez = *(new Matrix);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        rez.a[i][j] = 0;
        for (int z = 0; z < N; z++) {
          rez.a[i][j] = (rez.a[i][j] + 1LL * a[i][z] * b.a[z][j]) % (M - 1);
        }
      }
    }
    return rez;
  }
};
Matrix& st(Matrix& a, int b) {
  if (b == 1) return a;
  if (b == 2) return a * a;
  if (b % 2) return a * st(a * a, b / 2);
  return st(a * a, b / 2);
}
long long st(long long a, int b) {
  if (b == 0) return 1;
  if (b % 2) return (a * st((a * a) % M, b / 2)) % M;
  return (st((a * a) % M, b / 2)) % M;
}
long long tta = 1, ttb = 0, ta = 0, tb = 1;
int Mygcd(int a, int b) {
  while (b != 0) {
    int q = a / b;
    int r = a - q * b;
    tta -= ta * q;
    ttb -= tb * q;
    swap(ta, tta);
    swap(tb, ttb);
    ta %= M - 1;
    tb %= M - 1;
    tta %= M - 1;
    ttb %= M - 1;
    a = b;
    b = r;
  }
  return a;
}
int ind(int a, int b) {
  long long n1 = M / SQ + 10, n2 = SQ, tc;
  set<pair<long long, int>>::iterator it;
  set<pair<long long, int>> f;
  for (int i = 0; i < n1; ++i) {
    f.insert({st(a, (SQ * i) % (M - 1)), i});
  }
  for (int j = 0; j < n2; j++) {
    tc = (b * st(a, j)) % M;
    it = f.lower_bound({tc, -1});
    if (it != f.end() && (*it).first == tc) {
      int ans = (*it).second * SQ - j;
      ans %= M - 1;
      ans += M - 1;
      ans %= M - 1;
      return ans;
    }
  }
  throw;
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> k;
  N = k;
  Matrix ma;
  for (int i = 0; i < k; i++) {
    cin >> ma.a[k - i - 1][k - 1];
  }
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k - 1; j++) {
      if (i == j + 1)
        ma.a[i][j] = 1;
      else
        ma.a[i][j] = 0;
    }
  }
  cin >> n >> m;
  long long in = st(ma, n - k).a[N - 1][N - 1];
  long long in2 = ind(3, m);
  long long gc = Mygcd(in, M - 1);
  if (in2 % gc != 0) {
    cout << -1;
    return 0;
  } else {
    tta = (tta % (M - 1) + M - 1) % (M - 1);
    tta = (tta * (in2 / gc)) % (M - 1);
    cout << st(3, tta);
  }
  return 0;
}
