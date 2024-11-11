#include <bits/stdc++.h>
char get() {
  char ch;
  ch = getchar();
  if (ch == 'L' || ch == 'R') return ch;
  return get();
}
int n;
long long m, t, f[300005], opt[300005], ans[300005], s[300005];
int rk[300005];
std::pair<long long, int> p[300005];
int main() {
  scanf("%d%lld%lld", &n, &m, &t);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &f[i]);
    --f[i];
    opt[i] = (get() == 'L' ? -1 : 1);
    p[i] = std::make_pair(f[i], i);
  }
  for (int i = 1; i <= n; i++) ans[i] = ((f[i] + opt[i] * t) % m + m) % m;
  std::sort(p + 1, p + n + 1);
  for (int i = 1; i <= n; i++) rk[i] = p[i].second;
  std::sort(ans + 1, ans + n + 1);
  for (int i = 1; i <= n; i++) ++ans[i];
  long long fst = 1;
  for (int i = 1; i <= n; i++) {
    long long now = f[i] + opt[i] * t;
    if (opt[i] == 1)
      fst = (fst - now / m) % n;
    else if (opt[i] == -1) {
      if (now >= 0) continue;
      fst = (fst + ((-now - 1) / m + 1)) % n;
    }
  }
  fst = fst + n;
  fst = (fst - 1) % n + 1;
  long long now = fst - 1;
  for (int i = 1; i <= n; i++) {
    ++now;
    if (now > n) now = now - n;
    s[rk[now]] = ans[i];
  }
  for (int i = 1; i <= n; i++) printf("%lld ", s[i]);
  puts("");
  return 0;
}
