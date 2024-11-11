#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T& num) {
  bool start = false, neg = false;
  char c;
  num = 0;
  while ((c = getchar()) != EOF) {
    if (c == '-')
      start = neg = true;
    else if (c >= '0' && c <= '9') {
      start = true;
      num = num * 10 + c - '0';
    } else if (start)
      break;
  }
  if (neg) num = -num;
}
const long double eps = 1e-14;
inline int dcmp(long double x) {
  if (fabs(x) < eps) return 0;
  return x > 0 ? 1 : -1;
}
int lX, rX, lY, rY;
long double l = 0, r = 1e9, L, R;
inline void add(int s, int v, int li, int ri) {
  L = li - s;
  R = ri - s;
  if (v == 0) {
    if (!(dcmp(L) <= 0 && dcmp(R) >= 0)) {
      printf("-1\n");
      exit(0);
    }
  } else {
    L /= v;
    R /= v;
    if (dcmp(L - R) > 0) swap(L, R);
    l = max(l, L);
    r = min(r, R);
  }
}
int main() {
  int n;
  read(n);
  read(lX);
  read(lY);
  read(rX);
  read(rY);
  for (int i = (1); i <= (n); i++) {
    int sX, sY, vX, vY;
    read(sX);
    read(sY);
    read(vX);
    read(vY);
    add(sX, vX, lX, rX);
    add(sY, vY, lY, rY);
  }
  if (dcmp(l - r) <= 0)
    printf("%.20lf\n", (double)l);
  else
    printf("-1\n");
  return 0;
}
