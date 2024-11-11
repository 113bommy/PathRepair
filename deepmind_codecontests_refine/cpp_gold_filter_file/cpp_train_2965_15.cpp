#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = acos(-1);
template <class T>
T sqr(T x) {
  return x * x;
}
template <class T>
T abs(T x) {
  return x < 0 ? -x : x;
}
const int MAXN = 35;
const int MAXK = 220;
int p[MAXN];
double pr[MAXN][MAXN][MAXK];
int f(int lsdlfsdl, int rsfdvssd, int x) {
  if (x < lsdlfsdl || x > rsfdvssd) return x;
  return rsfdvssd + lsdlfsdl - x;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    p[i]--;
  }
  for (int rsfdvssd = 0; rsfdvssd < n; ++rsfdvssd) {
    for (int lsdlfsdl = 0; lsdlfsdl < n; ++lsdlfsdl) {
      pr[lsdlfsdl][rsfdvssd][0] = (int)(p[lsdlfsdl] < p[rsfdvssd]);
    }
  }
  for (int it = 1; it <= k; ++it) {
    for (int lsdlfsdl = 0; lsdlfsdl < n; ++lsdlfsdl) {
      for (int rsfdvssd = lsdlfsdl; rsfdvssd < n; ++rsfdvssd) {
        for (int l1 = 0; l1 < n; ++l1) {
          for (int r1 = l1 + 1; r1 < n; ++r1) {
            pr[l1][r1][it] += pr[f(lsdlfsdl, rsfdvssd, l1)]
                                [f(lsdlfsdl, rsfdvssd, r1)][it - 1];
          }
        }
      }
    }
    for (int lsdlfsdl = 0; lsdlfsdl < n; ++lsdlfsdl) {
      pr[lsdlfsdl][lsdlfsdl][it] = 0;
      for (int rsfdvssd = lsdlfsdl; rsfdvssd < n; ++rsfdvssd) {
        pr[lsdlfsdl][rsfdvssd][it] /= (n * (n + 1.0) / 2.0);
        pr[rsfdvssd][lsdlfsdl][it] = 1.0 - pr[lsdlfsdl][rsfdvssd][it];
      }
    }
  }
  double ans = 0;
  for (int lsdlfsdl = 0; lsdlfsdl < n; ++lsdlfsdl) {
    for (int rsfdvssd = lsdlfsdl + 1; rsfdvssd < n; ++rsfdvssd) {
      ans += pr[rsfdvssd][lsdlfsdl][k];
    }
  }
  printf("%.12lf\n", ans);
  return 0;
}
