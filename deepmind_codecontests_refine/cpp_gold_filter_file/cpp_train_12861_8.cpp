#include <bits/stdc++.h>
using namespace std;
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};
long long m;
long long calc(long long x) {
  long long sum = 0;
  for (int i = (2), _b = (1000000); i <= _b; i++) {
    long long t = (long long)(i)*i * i;
    sum += x / t;
    if (x / t == 0) break;
  }
  return sum;
}
int main() {
  scanf("%I64d", &m);
  long long l = 0, r = (long long)(1e17), res = -1;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (calc(mid) >= m) {
      res = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  if (calc(res) == m) {
    cout << res << endl;
    return 0;
  }
  cout << -1 << endl;
}
