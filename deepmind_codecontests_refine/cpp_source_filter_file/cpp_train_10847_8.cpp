#include <bits/stdc++.h>
using namespace std;
long long calc(long long x, long long n) {
  long long ret = 0;
  long long cnt = 1;
  for (int i = 0; i < 31; i++) {
    if ((1 << i) > n) break;
    if (n & (1 << i)) {
      n = n ^ (1 << i);
      if ((x & n) == 0) ret += cnt;
    }
    if (!(x & (1 << i))) cnt *= 2;
  }
  return ret;
}
long long find(int l, int r) {
  if (l == r) return 0;
  long long ret = 0;
  if (l & 1) {
    ret += 2ll * (calc(l, r) - calc(l, l));
    l++;
  }
  if (r & 1) {
    ret += 2ll * (calc(r - 1, r) - calc(r - 1, l));
    r--;
  }
  return ret + 3ll * find(l / 2, r / 2);
}
int main() {
  int T, a, b;
  for (scanf("%d", &T); T--;) {
    cin >> a >> b;
    long long res = 0;
    if (a == 0) {
      res = 2 * b - 1;
      a = 1;
    }
    res += find(a, b + 1);
    cout << res << "\n";
  }
  return 0;
}
