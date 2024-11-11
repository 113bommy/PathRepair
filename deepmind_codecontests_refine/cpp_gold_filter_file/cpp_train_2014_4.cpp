#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, e, f, g, h, i, j, k;
long long mod, T;
struct node {
  long long x[5][5];
  friend node operator*(const node &x, const node &y) {
    node T;
    long long vv;
    for (long long iii = 1LL; iii <= 2LL; iii++)
      for (long long jjj = 1LL; jjj <= 2LL; jjj++) {
        T.x[iii][jjj] = 0LL;
        for (long long kkk = 1LL; kkk <= 2LL; kkk++) {
          vv = (long long)(((long double)x.x[iii][kkk] *
                            (long double)y.x[kkk][jjj]) /
                           (long double)mod);
          vv = x.x[iii][kkk] * y.x[kkk][jjj] - vv * mod;
          T.x[iii][jjj] += vv + mod;
          T.x[iii][jjj] %= mod;
        }
      }
    return T;
  }
};
node F, G, H, ch[10], root;
long long an;
long long Fi[1600005];
vector<long long> E[2];
node Mi(long long x) {
  node kk;
  int ii, jj;
  if (x == 1LL) return root;
  kk = Mi(x >> 1);
  kk = kk * kk;
  if (x & 1) kk = kk * root;
  return kk;
}
long long Fib(long long x) {
  if (x == 1LL) return 1LL;
  if (x == 2LL) return 1LL;
  root.x[1][1] = 0LL;
  root.x[1][2] = 1LL;
  root.x[2][1] = 1LL;
  root.x[2][2] = 1LL;
  F = Mi(x - 2);
  return (F.x[1][2] + F.x[2][2]) % mod;
}
int main() {
  scanf("%I64d", &a);
  mod = 1000000LL;
  T = 1500000LL;
  Fi[1] = Fi[2] = 1;
  for (i = 3; i <= 1500000LL; i++) Fi[i] = (Fi[i - 1] + Fi[i - 2]) % mod;
  for (i = 1; i <= 1500000LL; i++)
    if (Fi[i] == a % mod) E[1].push_back(i);
  for (b = 1; b <= 7; b++) {
    mod *= 10;
    E[(b & 1) ^ 1].clear();
    for (i = 0; i < E[b & 1].size(); i++) {
      e = E[b & 1][i];
      j = e;
      while (j <= T * 10LL) {
        if (Fib(j) == a % mod) E[(b & 1) ^ 1].push_back(j);
        j += T;
      }
    }
    T *= 10;
  }
  if (E[0].size() == 0) {
    printf("-1\n");
    return 0;
  }
  an = E[0][0];
  for (i = 0; i < E[0].size(); i++) an = min(an, E[0][i]);
  printf("%I64d\n", an);
  return 0;
}
