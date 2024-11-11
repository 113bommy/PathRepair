#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using std::bitset;
using namespace std;
map<long long, long long> M;
long long a[101000];
long long k, b, n, ans;
int main() {
  long long i, j, tem;
  long long s, s0, sum, cnt, x;
  while (scanf("%I64d%I64d%I64d", &k, &b, &n) != EOF) {
    M.clear();
    for (i = 1; i <= n; i++) scanf("%I64d", &a[i]);
    s = ans = 0;
    for (i = 1; i <= n; i++) {
      s += a[i];
      s = s % (k - 1);
      x = s - b;
      if (x < 0) x += k - 1;
      ans += M[x];
      if (s == b || (b == k - 1 && s == 0)) ans++;
      M[s]++;
    }
    s0 = sum = 0;
    for (i = 1; i <= n; i++) {
      if (a[i])
        s0 = 0;
      else
        s0++;
      sum += s0;
    }
    if (b == 0) ans = sum;
    if (b == k - 1) ans -= sum;
    printf("%d\n", ans);
  }
  return 0;
}
