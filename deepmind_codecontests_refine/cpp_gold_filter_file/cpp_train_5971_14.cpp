#include <bits/stdc++.h>
using namespace std;
bool debug = false;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
bool ck(int k) {
  double ss = (double)k * m, cnt = 1;
  double C = 1, A = k, B = 1;
  for (long long lp = 1; cnt < n && ss > 0 && A >= 0; lp++) {
    C = C * A / B;
    A--;
    B++;
    double y = min(C, ss / lp);
    cnt += y;
    ss -= y * lp;
  }
  return cnt >= n;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    int l = 0, r = n;
    while (l + 1 < r) {
      int mid = (l + r) / 2;
      if (ck(mid))
        r = mid;
      else
        l = mid + 1;
    }
    if (ck(l))
      printf("%d\n", l);
    else
      printf("%d\n", r);
  }
  return 0;
}
