#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int w = 0, x = 0;
  char c = getchar();
  while (!isdigit(c)) w |= c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = getchar();
  return w ? -x : x;
}
namespace star {
const int maxn = 1e7 + 10;
int n, p[maxn / 10], tot, phi[maxn], mp[maxn], s[maxn];
bool mark[maxn];
inline void work() {
  n = read();
  phi[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!mark[i]) p[++tot] = i, phi[i] = i - 1, mp[i] = i;
    for (int tmp, j = 1; j <= tot and (tmp = i * p[j]) <= n; j++) {
      mark[tmp] = true, mp[tmp] = p[j];
      if (i % p[j] == 0) {
        phi[tmp] = phi[i] * p[j];
        break;
      }
      phi[tmp] = phi[i] * phi[p[j]];
    }
    s[mp[i]]++;
  }
  for (int i = 1; i <= n; i++) s[i] += s[i - 1];
  int cntp = 0;
  for (int i = 2; i <= n; i++) cntp += phi[i] - 1;
  long long ans1 = (n - 1ll) * (n - 2ll) / 2 - cntp, ans3 = 0, ans4 = 0;
  for (int i = 1; i <= tot; i++) {
    int sx = s[p[i]] - s[p[i] - 1];
    ans3 += 1ll * sx * max(s[n / 2] - s[max(p[i], n / p[i])], 0);
    ans4 += 1ll * sx * max(s[n] - s[max(p[i], n / 2)], 0);
  }
  printf("%lld\n", ans1 + (cntp - ans3 - ans4) * 2 + ans3 * 3);
}
}  // namespace star
signed main() {
  star::work();
  return 0;
}
