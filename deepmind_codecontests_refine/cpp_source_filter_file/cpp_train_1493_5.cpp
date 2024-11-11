#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
A cvt(B x) {
  stringstream ss;
  ss << x;
  A y;
  ss >> y;
  return y;
}
int x = 0;
void solve(int k, int l1, int r1, int l2, int r2) {
  if (r1 < l1 || r2 < l2) return;
  if (r1 - l1 + 1 <= x || r2 - l2 + 1 <= x) return;
  int m = 1 << (k - 1);
  if (m < l1) {
    l1 -= m;
    r1 -= m;
  }
  if (m < l2) {
    l2 -= m;
    r2 -= m;
  }
  if (l2 < l1) {
    swap(l1, l2);
    swap(r1, r2);
  }
  if (k == 1)
    x = max(x, 1);
  else {
    x = max(x, min(r1, r2) - l2 + 1);
    if (r2 <= r1) return;
    if (r1 < m) {
      solve(k - 1, l1, r1, l2, min(r2, m - 1));
      solve(k - 1, l1, r1, m + 1, r2);
    } else {
      solve(k - 1, l1, m - 1, 1, r2 - m);
    }
  }
}
int main() {
  int l1, r1, l2, r2;
  scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
  solve(30, l1, r1, l2, r2);
  printf("%d\n", x);
  return 0;
}
