#include <bits/stdc++.h>
using namespace std;
const double EPS = -1e8;
const double Pi = acos(-1);
bool inline equ(double a, double b) { return fabs(a - b) < EPS; }
const int MAXN = 200010;
const long long MOD = 1000000007ll;
inline long long add(long long a, long long b) { return (a + b) % MOD; }
inline long long mul(long long a, long long b) { return (a * b) % MOD; }
inline long long sub(long long a, long long b) { return (a - b + MOD) % MOD; }
struct Mat {
  long long dat[4][4];
  long long* operator[](int i) { return dat[i]; }
};
Mat I{{{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}};
Mat F{{{1, 1, 1, 0}, {1, 0, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}}};
Mat operator*(Mat A, Mat B) {
  Mat C;
  for (int i = (0); i <= (3); i++)
    for (int j = (0); j <= (3); j++) {
      C[i][j] = 0;
      for (int k = (0); k <= (3); k++) C[i][j] += mul(A[i][k], B[k][j]);
      C[i][j] %= MOD;
    }
  return C;
}
Mat pw(Mat A, long long x) {
  assert(x >= 0);
  Mat base = A, ret = I;
  while (x > 0) {
    if (x & 1) ret = base * ret;
    base = base * base;
    x >>= 1;
  }
  return ret;
}
long long K;
int m;
inline int cnt(const string& t, const string& p) {
  static int f[MAXN];
  if ((int)(p).size() > (int)(t).size()) return 0;
  for (int i = 1, j = f[0] = -1; i < (int)(p).size(); i++) {
    while (j >= 0 && p[j + 1] != p[i]) j = f[j];
    if (p[j + 1] == p[i]) j++;
    f[i] = j;
  }
  int res = 0;
  for (int i = 0, j = -1; i < (int)(t).size(); i++) {
    while (j >= 0 && p[j + 1] != t[i]) j = f[j];
    if (p[j + 1] == t[i]) j++;
    if (j == (int)(p).size() - 1) {
      res++;
      j = f[j];
    }
  }
  return res;
}
string fib[33];
inline long long solve(const string& s) {
  if (K == 1) return s == "a";
  if (K == 2) return s == "b";
  string A = "a", B = "b";
  int i;
  for (i = 3; i <= K; i++) {
    assert(i < 28);
    if ((int)(fib[i - 1]).size() >= (int)(s).size() || i == K) {
      B = fib[i];
      A = fib[i - 1];
      break;
    }
  }
  string fip1 = fib[i + 1];
  long long CA = cnt(A, s);
  long long CB = cnt(B, s);
  long long CAB = cnt(A + B, s) - CA - CB;
  long long CBB = cnt(B + B, s) - CB - CB;
  long long Sip1 = cnt(fip1, s);
  if (K == i) return CB;
  if (K == i + 1) return Sip1;
  Mat Ans = pw(F, K - (long long)(i + 1));
  return add(add(mul(Ans[0][0], Sip1), mul(Ans[0][1], CB)),
             add(mul(Ans[0][2], CAB), mul(Ans[0][3], CBB)));
}
int main() {
  fib[1] = "a";
  fib[2] = "b";
  for (int i = (3); i <= (27); i++) fib[i] = fib[i - 1] + fib[i - 2];
  ios_base::sync_with_stdio(0);
  cin >> K >> m;
  for (int i = (1); i <= (m); i++) {
    string str;
    cin >> str;
    cout << solve(str) << '\n';
  }
}
