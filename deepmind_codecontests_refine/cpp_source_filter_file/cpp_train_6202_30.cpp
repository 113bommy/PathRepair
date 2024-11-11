#include <bits/stdc++.h>
using namespace std;
long long n, init, fin, vt, vp, pt, d, ttren, mytime, ans;
int main() {
  cin >> n >> init >> fin >> vt >> vp >> pt >> d;
  long long dif = init - fin;
  if (dif < 0) dif = -dif;
  mytime = vp * dif;
  if (init < fin) {
    if (d == 1) {
      if (pt <= init) {
        ttren = (fin - pt) * vt;
      }
      if (pt > init) {
        ttren = (n - pt + n - fin) * vt;
      }
    }
    if (d == -1) {
      ttren = (pt + fin) * vt;
    }
  }
  if (init > fin) {
    if (d == -1) {
      if (pt >= init) {
        ttren = (pt - fin) * vt;
      }
      if (pt < init) {
        ttren = (pt + n + n - fin) * vt;
      }
    }
    if (d == 1) {
      ttren = (n - pt + n - fin) * vt;
    }
  }
  ans = min(mytime, ttren);
  cout << ans;
  return 0;
}
