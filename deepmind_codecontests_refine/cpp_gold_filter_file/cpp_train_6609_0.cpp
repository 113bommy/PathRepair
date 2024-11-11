#include <bits/stdc++.h>
using namespace std;
int n;
const int NCLIMIT = 2014;
long long ncr[NCLIMIT][NCLIMIT];
long long ncrmod = 1e9 + 7;
void fillncr() {
  for (int i = 0; i < NCLIMIT; i++)
    for (int j = 0; j < NCLIMIT; j++) {
      if (i < j)
        ncr[i][j] = 0;
      else if (j == 0)
        ncr[i][j] = 1;
      else
        ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % ncrmod;
    }
}
void mul(double* ans, double a) {
  double tans[n + 1];
  for (int(i) = 0; (i) < (n + 1); (i)++) tans[i] = (1 - a) * ans[i];
  for (int(i) = 0; (i) < (n + 1); (i)++) tans[i + 1] += a * ans[i];
  for (int(i) = 0; (i) < (n + 1); (i)++) ans[i] = tans[i];
}
long long co(long long a) {
  if (a == 0) return 0;
  long long ac = a;
  int d = 1;
  while (ac > 9) {
    d += 1;
    ac /= 10;
  }
  long long cnt = 0;
  if (ac == 1) {
    long long tmp = 8;
    for (int(i) = 0; (i) < (d - 1); (i)++) {
      cnt += tmp;
      tmp *= 10;
    }
    return a - cnt;
  } else {
    long long tmp = 1;
    for (int(i) = 0; (i) < (d); (i)++) {
      cnt += tmp;
      tmp *= 10;
    }
    return cnt;
  }
}
int main() {
  fillncr();
  int(nt);
  scanf("%d", &(nt));
  n = nt;
  long long l[n], r[n];
  double p0[n], p1[n];
  for (int(i) = 0; (i) < (n); (i)++) {
    long long(t1), (t2);
    scanf("%I64d%I64d", &(t1), &(t2));
    t1--;
    l[i] = t1;
    r[i] = t2;
    p1[i] = double(co(r[i]) - co(l[i])) / (r[i] - l[i]);
    p0[i] = 1 - p1[i];
  }
  int(kt);
  scanf("%d", &(kt));
  int k = (n * kt + 99) / 100;
  double ans[n + 1];
  for (int(i) = 0; (i) < (n + 1); (i)++) ans[i] = 0;
  ans[0] = 1;
  for (int(i) = 0; (i) < (n); (i)++) mul(ans, p1[i]);
  double pink = 0;
  if (k < 0) pink = 1;
  for (int(i) = 0; (i) < (k); (i)++) pink += ans[i];
  pink = 1 - pink;
  printf("%.10lf", pink);
  return 0;
}
