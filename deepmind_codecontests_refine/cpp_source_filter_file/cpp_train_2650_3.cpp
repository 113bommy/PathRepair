#include <bits/stdc++.h>
using namespace std;
long long l, r, k;
long long ans = 1e18;
long long ANS[10];
long long a[10];
bool vis[10];
long long sum;
void dfs(long long x) {
  if (x == r + 1) {
    long long now = 0;
    int cnt = 0;
    for (int i = 1; i <= r - l + 1; i++)
      if (vis[i]) {
        a[++cnt] = i + l - 1;
        now ^= (i + l - 1);
      }
    if (cnt > k || !cnt) return;
    if (now < ans) {
      ans = now;
      sum = cnt;
      for (int i = 1; i <= sum; i++) ANS[i] = a[i];
    }
    return;
  }
  for (int i = 0; i <= 1; i++) {
    vis[x - l + 1];
    dfs(x + 1);
  }
}
int main() {
  scanf("%lld%lld%lld", &l, &r, &k);
  if (r - l + 1 <= 4) {
    dfs(l);
    printf("%lld\n%lld\n", ans, sum);
    for (int i = 1; i <= sum; i++) printf("%lld ", ANS[i]);
    return 0;
  } else {
    if (k == 1) {
      printf("%lld\n%lld\n%lld\n", l, 1ll, l);
      return 0;
    }
    if (k == 2) {
      if (l & 1) l++;
      printf("%lld\n", 1ll);
      printf("%lld\n", 2ll);
      printf("%lld %lld\n", l, l + 1);
      return 0;
    }
    if (k >= 4) {
      if (l & 1) l++;
      printf("%lld\n", 0ll);
      printf("%lld\n", 4ll);
      printf("%lld %lld %lld %lld\n", l, l + 1, l + 2, l + 3);
      return 0;
    }
    if (k == 3) {
      long long mul = 1;
      while (mul <= l) mul *= 2;
      long long x = mul - 1;
      long long y = mul + mul / 2 - 1;
      long long z = mul + mul / 2;
      if (z <= r) {
        printf("%lld\n", 0ll);
        printf("%lld\n", 3ll);
        printf("%lld %lld %lld\n", x, y, z);
      } else {
        if (l & 1) l++;
        printf("%lld\n", 1ll);
        printf("%lld\n", 2ll);
        printf("%lld %lld\n", l, l + 1);
      }
      return 0;
    }
  }
  return 0;
}
