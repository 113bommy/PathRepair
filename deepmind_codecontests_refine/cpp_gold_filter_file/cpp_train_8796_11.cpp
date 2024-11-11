#include <bits/stdc++.h>
using namespace std;
int kor = 1e7;
int main() {
  long long n, rad, v;
  cin >> n >> rad >> v;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    long long d = r - l;
    int ma = 0;
    while (d < kor) {
      d *= 10;
      rad *= 10;
      ma++;
    }
    long long mnv = 0;
    long long mxv = d;
    while (mnv != mxv) {
      long long cv = (mnv + mxv) / 2;
      double cd = cv + rad * sin((double)cv / rad);
      if (cd < (d / 2)) {
        mnv = cv + 1;
        continue;
      }
      mxv = cv;
    }
    long long ev = mnv;
    mnv = 0;
    mxv = d;
    while (mnv != mxv) {
      long long cv = (mnv + mxv) / 2;
      double cd = cv - rad * sin((double)cv / rad);
      if (cd < (d / 2)) {
        mnv = cv + 1;
        continue;
      }
      mxv = cv;
    }
    long long bv = min(ev, mnv);
    bv *= 2;
    double t = (double)bv / v;
    while (ma > 0) {
      t /= 10;
      rad /= 10;
      ma--;
    }
    cout << setprecision(20) << t << endl;
  }
  cin >> n;
}
