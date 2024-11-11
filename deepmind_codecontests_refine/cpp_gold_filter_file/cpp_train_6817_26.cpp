#include <bits/stdc++.h>
using namespace std;
double dp[110][110][110];
inline double rec(int i, int j, int k) {
  double &ret = dp[i][j][k];
  if (ret != 0) return ret;
  if (k == 0) return ret = 1;
  if (i == 0 || j == 0) return ret = 0;
  double a = i * j, b = j * k, c = i * k;
  double tot = a + b + c;
  ret += (a / tot) * rec(i, j - 1, k);
  ret += (b / tot) * rec(i, j, k - 1);
  ret += (c / tot) * rec(i - 1, j, k);
  return ret;
}
int main() {
  int r, s, p;
  scanf("%d", &r);
  ;
  scanf("%d", &s);
  ;
  scanf("%d", &p);
  ;
  memset(dp, 0, sizeof(dp));
  ;
  printf("%.12lf ", rec(r, s, p));
  memset(dp, 0, sizeof(dp));
  ;
  printf("%.12lf ", rec(s, p, r));
  memset(dp, 0, sizeof(dp));
  ;
  printf("%.12lf ", rec(p, r, s));
}
