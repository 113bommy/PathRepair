#include <bits/stdc++.h>
using namespace std;
int a, b;
bool check(long long l, long long t, long long m, long long r) {
  l -= 1;
  long long dsum = a * (r - l) + b * (r * (r - 1) / 2 - l * (l - 1) / 2);
  return (long long)a + (r - 1) * (long long)b <= t && dsum <= m * t;
}
int binS(int l, int t, int m) {
  int bl = l, br = 1e4;
  while (bl < br) {
    int bm = (bl + br) / 2;
    if (check(l, t, m, bm))
      bl = bm + 1;
    else
      br = bm - 1;
  }
  if (check(l, t, m, bl))
    return bl;
  else if (check(l, t, m, max(l, bl - 1)))
    return bl - 1;
  else
    return -1;
}
int main() {
  int n;
  scanf("%d%d%d", &a, &b, &n);
  for (int i = 0; i < n; ++i) {
    int l, t, m;
    scanf("%d%d%d", &l, &t, &m);
    printf("%d\n", binS(l, t, m));
  }
  return 0;
}
