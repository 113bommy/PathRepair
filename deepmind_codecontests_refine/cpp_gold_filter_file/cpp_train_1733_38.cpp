#include <bits/stdc++.h>
using namespace std;
int lis[20], ln;
void split(int x) {
  ln = 0;
  int m = sqrt(x);
  for (int i = 2; i <= m; i++) {
    if (x % i == 0) {
      while (x % i == 0) x /= i;
      lis[++ln] = i;
    }
  }
  if (x > 1) lis[++ln] = x;
}
int calc(int n, int m) {
  int ans = 0;
  for (int s = 0; s < 1 << ln; s++) {
    int mu = 1, cnt = 0;
    for (int i = 1; i <= ln; i++) {
      if (s & (1 << (i - 1))) {
        mu *= lis[i];
        cnt++;
      }
    }
    if (cnt & 1)
      ans -= n / mu - m / mu;
    else
      ans += n / mu - m / mu;
  }
  return ans;
}
int binary(int k, int w) {
  int l = 1, r = 1e7;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (calc(m, w) < k)
      l = m + 1;
    else
      r = m - 1;
  }
  return l;
}
int T;
int main() {
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    int x, p, k;
    scanf("%d%d%d", &x, &p, &k);
    split(p);
    cout << binary(k, x) << '\n';
  }
  return 0;
}
