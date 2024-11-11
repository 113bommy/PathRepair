#include <bits/stdc++.h>
const int MAXN = 1e6 + 5;
int n, q, a[MAXN];
int f[MAXN];
int main() {
  scanf("%d%d", &n, &q);
  long long s = 0;
  for (int i = 0; i <= n - 1; ++i) scanf("%d", a + i), s += a[i];
  while (q--) {
    long long b;
    scanf("%lld", &b);
    if (s <= b) {
      puts("1");
      continue;
    }
    long long sm = 0, t = 0;
    for (int i = 0; i <= n - 1; ++i) {
      while (sm + a[(i + t) % n] <= b) sm += a[(i + t) % n], ++t;
      f[i] = t;
      sm -= a[i];
      t--;
    }
    sm = 0;
    int now = 0;
    int mn = 1e9, ps = -1;
    while (sm < n) {
      if (mn > f[now]) {
        mn = f[now];
        ps = now;
      }
      sm += f[now];
      (now += f[now]) %= n;
    }
    int ans = 1e9;
    for (int i = 0; i <= f[ps]; ++i) {
      int t = (ps + i) % n;
      auto work = [&](int x) {
        int ans = 0, sm = 0;
        while (sm < n) {
          ans++;
          sm += f[x];
          (x += f[x]) %= n;
        }
        return ans;
      };
      ans = std::min(ans, work(t));
    }
    printf("%d\n", ans);
  }
  return 0;
}
