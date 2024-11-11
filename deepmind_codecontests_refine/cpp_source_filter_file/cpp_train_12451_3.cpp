#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
inline void gn(long long& x) {
  int sg = 1;
  char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-')
    ;
  c == '-' ? (sg = -1, x = 0) : (x = c - '0');
  while ((c = getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= sg;
}
inline void gn(int& x) {
  long long t;
  gn(t);
  x = t;
}
inline void gn(unsigned long long& x) {
  long long t;
  gn(t);
  x = t;
}
const int mod = 1000000007;
const int N = 15;
void add(int& a, int b) {
  a += b;
  if (a >= mod) a -= b;
}
int mul(int a, int b) {
  long long ret = 1ll * a * b;
  ret %= mod;
  return ret;
}
struct MAT {
  int a[N + 1][N + 1];
  MAT() { memset((a), 0, sizeof(a)); }
  MAT operator*(const MAT& ot) {
    MAT ret;
    for (int i = (0); i <= (N); i++)
      for (int j = (0); j <= (N); j++)
        for (int k = (0); k <= (N); k++) {
          long long ad = mul(a[i][j], ot.a[k][j]);
          ret.a[i][j] += ad;
          ret.a[i][j] %= mod;
        }
    return ret;
  }
};
MAT powmat(MAT a, long long b) {
  MAT ret;
  for (int i = (0); i <= (N); i++) ret.a[i][i] = 1;
  while (b) {
    if (b & 1) ret = ret * a;
    b >>= 1;
    a = a * a;
  }
  return ret;
}
int main() {
  int n;
  long long k;
  gn(n);
  gn(k);
  MAT ans;
  ans.a[0][0] = 1;
  while (n--) {
    long long A, B;
    int c;
    gn(A);
    gn(B);
    gn(c);
    if (A > k) A = k;
    if (B > k) B = k;
    long long dis = B - A;
    MAT b;
    for (int i = (0); i <= (c); i++) {
      b.a[i][i] = 1;
      if (i - 1 >= 0) b.a[i - 1][i] = 1;
      if (i + 1 <= c) b.a[i + 1][i] = 1;
    }
    ans = ans * powmat(b, dis);
  }
  cout << ans.a[0][0] << endl;
  return 0;
}
