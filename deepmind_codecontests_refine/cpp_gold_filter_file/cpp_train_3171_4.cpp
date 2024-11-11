#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200001;
long long a[MAXN];
int n;
long long sum(int r) {
  long long res = 0;
  for (; r >= 0; r = (r & (r + 1)) - 1) res += a[r];
  return res;
}
void add(int x, int dx) {
  for (; x < n; x = (x | (x + 1))) a[x] += dx;
}
long long sum(int l, int r) { return sum(r) - (l ? sum(l - 1) : 0); }
int main() {
  int q;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; ++i) {
    add(i, 1);
  }
  int curL = 0;
  int curR = n - 1;
  bool reversed = 0;
  for (; q; --q) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      int p;
      scanf("%d", &p);
      if (2 * p > curR - curL + 1) {
        reversed ^= 1;
        p = curR - curL + 1 - p;
      }
      for (int i = 0; i < p; ++i) {
        if (reversed) {
          add(curR - 2 * (p - i) + 1, sum(curR, curR));
          --curR;
        } else {
          add(curL + 2 * (p - i) - 1, sum(curL, curL));
          ++curL;
        }
      }
    } else {
      int l, r;
      scanf("%d %d", &l, &r);
      if (reversed)
        printf(
            "%I64d"
            "\n",
            sum(curR - r + 1, curR - l));
      else
        printf(
            "%I64d"
            "\n",
            sum(curL + l, curL + r - 1));
    }
  }
  return 0;
}
