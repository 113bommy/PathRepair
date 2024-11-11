#include <bits/stdc++.h>
using namespace std;
long long a;
long long ret(long long x) {
  x = x * (x + 1);
  return x / 2;
}
bool fnc(long long ve) {
  int lo = 1, hi = a, mid;
  while (lo <= hi) {
    mid = (lo + hi) >> 1;
    long long x = ve + ret(mid);
    if (x == a)
      return 1;
    else if (x < a)
      lo = mid + 1;
    else
      hi = mid - 1;
  }
  return 0;
}
int main() {
  long long rt, i = 1;
  scanf("%lld", &a);
  bool f = 0;
  rt = sqrt(a);
  for (; i <= rt; i++) {
    if (fnc(ret(i))) {
      f = 1;
      break;
    }
  }
  printf("%s\n", f ? "YES" : "NO");
  return 0;
}
