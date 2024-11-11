#include <bits/stdc++.h>
using namespace std;
long long r, h;
long long ans(long long s) {
  long long i = 1, j = r, md, ok = -1;
  while (i <= j) {
    md = (i + j) / 2;
    double kk = ((double)md / (double)s);
    if (kk >= 0.8 && kk <= 1.25) {
      ok = md;
      i = md + 1;
    } else if (kk < 0.8) {
      i = md + 1;
    } else
      j = md - 1;
  }
  return ok;
}
long long anss(long long s) {
  long long i = 1, j = h, md, ok = -1;
  while (i <= j) {
    md = (i + j) / 2;
    double kk = ((double)md / (double)s);
    if (kk >= 0.8 && kk <= 1.25) {
      ok = md;
      i = md + 1;
    } else if (kk < 0.8) {
      i = md + 1;
    } else
      j = md - 1;
  }
  return ok;
}
int main() {
  long long p, l = 0, i, j, k;
  cin >> h >> r;
  for (i = 0; i < h; i++) {
    k = pow(2, i);
    if (k > h) break;
    if (ans(k) != -1) {
      p = k;
      l = ans(k);
    }
  }
  long long pp = 0, lll = 0;
  for (i = 0; i < r; i++) {
    k = pow(2, i);
    if (k > r) break;
    if (anss(k) != -1) {
      pp = anss(k);
      lll = k;
    }
  }
  if (p < pp && p * l <= pp * lll) {
    p = pp;
    l = lll;
  }
  cout << p << " " << l;
}
