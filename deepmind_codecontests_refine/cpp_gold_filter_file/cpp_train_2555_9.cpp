#include <bits/stdc++.h>
using namespace std;
class Matrix {
 public:
  long long a[201][201];
  inline Matrix(long long init = 0) {
    for (int i = 0; i < (201); ++i)
      for (int j = 0; j < (201); ++j) a[i][j] = init;
  }
  Matrix operator=(const Matrix &m) {
    for (int i = 0; i < (201); ++i)
      for (int j = 0; j < (201); ++j) a[i][j] = m.a[i][j];
    return *this;
  }
};
const long long INF = 1e16;
Matrix operator*(const Matrix &m, const Matrix &n) {
  Matrix ret(-INF);
  for (int i = 0; i < (201); ++i)
    for (int j = 0; j < (201); ++j)
      for (int k = 0; k < (201); ++k)
        ret.a[i][j] = max(
            ret.a[i][j],
            (m.a[i][k] >= 0 && n.a[k][j] >= 0 ? m.a[i][k] + n.a[k][j] : -INF));
  return ret;
}
Matrix operator^(const Matrix &m, long long exp) {
  Matrix ret = m, tmp = m;
  --exp;
  while (exp) {
    if (exp & 1) ret = ret * tmp;
    tmp = tmp * tmp;
    exp >>= 1;
  }
  return ret;
}
class AC_automaton {
 public:
  int n;
  int son[201][26];
  int fail[201];
  long long val[201];
  inline AC_automaton() : n(1) {
    memset(son, 0, sizeof(son));
    memset(fail, 0, sizeof(fail));
    memset(val, 0, sizeof(val));
  }
  inline void insert(string s, int v) {
    int m = s.size();
    int p = 0;
    for (int i = 0; i < (m); ++i) {
      int c = s[i] - 'a';
      if (!son[p][c]) son[p][c] = n++;
      p = son[p][c];
    }
    val[p] += v;
  }
  int que[201], h, t;
  inline void getFail() {
    h = t = 0;
    for (int c = 0; c < (26); ++c)
      if (son[0][c]) que[t++] = son[0][c], fail[son[0][c]] = 0;
    while (h < t) {
      int i = que[h++];
      for (int c = 0; c < (26); ++c) {
        if (!son[i][c])
          son[i][c] = son[fail[i]][c];
        else
          que[t++] = son[i][c], fail[son[i][c]] = son[fail[i]][c];
      }
      val[i] += val[fail[i]];
    }
  }
  inline Matrix turnMatrix() {
    Matrix ret(-INF);
    for (int i = 0; i < (n); ++i)
      for (int c = 0; c < (26); ++c) ret.a[i][son[i][c]] = val[son[i][c]];
    return ret;
  }
} ac;
int n;
long long l;
int a[200];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> l;
  for (int i = 0; i < (n); ++i) cin >> a[i];
  for (int i = 0; i < (n); ++i) {
    string s;
    cin >> s;
    ac.insert(s, a[i]);
  }
  ac.getFail();
  Matrix m = ac.turnMatrix();
  m = m ^ l;
  long long ans = 0;
  for (int i = 0; i < (201); ++i) ans = max(ans, m.a[0][i]);
  cout << ans << endl;
  return 0;
}
