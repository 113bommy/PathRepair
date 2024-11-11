#include <bits/stdc++.h>
using namespace std;
using ll = long long;
long double r, v;
long double eps = 1e-7;
const long double mpi = acos(-1.0);
inline long double dist(long double theta) {
  return 2.0L * r * (sin(theta) + theta);
}
inline long double ti(long double theta, long long ni) {
  return 2.0L * r * (mpi * ni + theta) / v;
}
void solve() {
  int si, fi;
  scanf("%d%d", &si, &fi);
  long double d = fi - si;
  long long ni = d / (2.0L * mpi * r);
  long double left = 0;
  long double right = mpi;
  d = fi - si - 2.0L * r * mpi * ni;
  long double dleft = dist(left);
  long double dright = dist(right);
  long double e = eps * v;
  while (dright - dleft > e) {
    long double mid = (right + left) / 2.0L;
    long double dmid = dist(mid);
    if (dmid > d) {
      right = mid;
      dright = dmid;
    } else {
      left = mid;
      dleft = dmid;
    }
  }
  long double res = ti(right, ni);
  printf("%.10Lf\n", res);
  return;
}
int main() {
  int n, ri, vi;
  scanf("%d%d%d", &n, &ri, &vi);
  r = ri;
  v = vi;
  while (n--) {
    solve();
  }
  cout.flush();
  return 0;
}
