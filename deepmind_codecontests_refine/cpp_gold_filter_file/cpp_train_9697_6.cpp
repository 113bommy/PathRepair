#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
long long POW(long long a, long long b, long long MMM = MOD) {
  long long ret = 1;
  for (; b; b >>= 1, a = (a * a) % MMM)
    if (b & 1) ret = (ret * a) % MMM;
  return ret;
}
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
int ddx[] = {-1, -2, 1, -2, 2, -1, 2, 1}, ddy[] = {-2, -1, -2, 1, -1, 2, 1, 2};
int a[200006];
int n, k;
long long cnt(int N, int t) {
  if (N == 0) return 1;
  if (t == 0) {
    long long ans = k;
    for (int(i) = (1); (i) <= (N - 1); (i) += (1)) ans = ans * (k - 1) % MOD;
    return ans;
  } else if (t == 1) {
    long long ans = 1;
    for (int(i) = (1); (i) <= (N); (i) += (1)) ans = ans * (k - 1) % MOD;
    return ans;
  }
  long long same = 1, dif = 0;
  for (int(i) = (1); (i) <= (N); (i) += (1)) {
    long long ns = dif * (k - 1) % MOD;
    long long nd = (same + dif * (k - 2)) % MOD;
    same = ns, dif = nd;
  }
  if (t == 2) return dif * (k - 1) % MOD;
  return (same + dif * (k - 2)) % MOD;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int(i) = (0); (i) <= (n - 1); (i) += (1)) scanf("%d", a + i);
  for (int(i) = (0); (i) <= (n - 3); (i) += (1)) {
    if (a[i] != -1 && a[i] == a[i + 2]) return !printf("0\n");
  }
  long long ans = 1;
  int pr = -2;
  for (int(i) = (0); (i) <= (n - 1); (i) += (2)) {
    if (a[i] != -1) {
      if (pr == -2) {
        ans = ans * cnt(i / 2, 1) % MOD;
      } else {
        int t = 2;
        if (a[i] != a[pr]) t = 3;
        ans = ans * cnt((i - pr) / 2 - 1, t) % MOD;
      }
      pr = i;
    }
  }
  if (pr == -2) {
    ans = cnt((n + 1) / 2, 0);
  } else {
    ans = ans * cnt((n - pr - 1) / 2, 1) % MOD;
  }
  pr = -2;
  for (int(i) = (1); (i) <= (n - 1); (i) += (2)) {
    if (a[i] != -1) {
      if (pr == -2) {
        ans = ans * cnt(i / 2, 1) % MOD;
      } else {
        int t = 2;
        if (a[i] != a[pr]) t = 3;
        ans = ans * cnt((i - pr) / 2 - 1, t) % MOD;
      }
      pr = i;
    }
  }
  if (pr == -2) {
    ans = ans * cnt(n / 2, 0) % MOD;
  } else {
    ans = ans * cnt((n - pr - 1) / 2, 1) % MOD;
  }
  printf("%lld\n", ans);
}
