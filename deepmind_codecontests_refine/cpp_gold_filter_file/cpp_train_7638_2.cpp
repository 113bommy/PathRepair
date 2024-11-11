#include <bits/stdc++.h>
using namespace std;
template <class T1>
void deb(T1 e) {
  cout << e << endl;
}
template <class T1, class T2>
void deb(T1 e1, T2 e2) {
  cout << e1 << " " << e2 << endl;
}
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3) {
  cout << e1 << " " << e2 << " " << e3 << endl;
}
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << endl;
}
template <class T1, class T2, class T3, class T4, class T5>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << endl;
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6
       << endl;
}
long long sqr(long long n) { return n * n; }
double LOG(long long a, long long b) { return (log(a) / log(b)); }
long long GCD(long long a, long long b) {
  if (a < 0) return GCD(-a, b);
  if (b < 0) return GCD(a, -b);
  return (!b) ? a : GCD(b, a % b);
}
long long LCM(long long a, long long b) {
  if (a < 0) return LCM(-a, b);
  if (b < 0) return LCM(a, -b);
  return (a * (b / GCD(a, b)));
}
long long BigMod(long long B, long long P, long long M) {
  if (!P) return 1;
  if (!(P % 2)) return sqr(BigMod(B, P / 2, M)) % M;
  return (B % M) * (BigMod(B, P - 1, M)) % M;
}
int mat[105][105];
int main(void) {
  int n, m, d;
  int i, j;
  memset(mat, 0, sizeof(mat));
  cin >> n >> m >> d;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) scanf("%d", &mat[i][j]);
  int val = mat[0][0] % d;
  if (n == m && n == 1) {
    deb("0");
    return 0;
  }
  long long tmp = 0ll;
  bool flag = true;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (mat[i][j] % d != val)
        flag = false;
      else
        tmp += (mat[i][j] - val) / d;
      if (!flag) break;
    }
    if (!flag) break;
  }
  int res = (1 << 30);
  if (!flag)
    deb("-1");
  else {
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        int cur = 0;
        int k, l;
        for (k = 0; k < n; k++) {
          for (l = 0; l < m; l++) cur += abs(mat[i][j] - mat[k][l]) / d;
        }
        res = min(res, cur);
      }
    }
    deb(res);
  }
  return 0;
}
