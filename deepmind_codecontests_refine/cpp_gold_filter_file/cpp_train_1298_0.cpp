#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int maxm = 3e4 + 10;
int h[maxn];
int a[maxn];
int now[maxn];
queue<int> qu[maxm];
int n, m, k, p;
bool pd(register long long mid) {
  for (register int i = 1; i <= m; i++)
    while (!qu[i].empty()) qu[i].pop();
  for (register int i = 1; i <= n; i++) {
    now[i] = 0;
    if (a[i] > mid) return 0;
    if (m - mid / a[i] + 1 <= 1) continue;
    qu[m - mid / a[i] + 1].push(i);
  }
  register int nowk = 0;
  for (register int i = m; i >= 1; i--) {
    nowk += k;
    while (nowk && !qu[i].empty()) {
      register int x = qu[i].front();
      qu[i].pop();
      now[x]++;
      if (m - (1ll * p * now[x] + mid) / a[x] + 1 > 1)
        qu[m - ((1ll * p * now[x] + mid) / a[x]) + 1].push(x);
      nowk--;
    }
    if (!qu[i].empty()) return 0;
  }
  for (register int i = 1; i <= n; i++) {
    register long long tmp = h[i] + 1ll * m * a[i] - 1ll * now[i] * p;
    if (tmp - mid <= 0) continue;
    tmp -= mid;
    tmp = (tmp - 1) / p + 1;
    if (tmp > nowk)
      return 0;
    else
      nowk -= tmp;
  }
  return 1;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &p);
  register long long r = 0;
  register long long l = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &h[i], &a[i]);
    r = max(r, h[i] + 1ll * a[i] * m);
    l = max(l, (long long)a[i]);
  }
  while (l <= r) {
    register long long mid = (l + r) / 2;
    if (pd(mid))
      r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%lld", l);
  return 0;
}
