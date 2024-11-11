#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long num = 0, neg = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') neg = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    num = (num << 3) + (num << 1) + c - '0';
    c = getchar();
  }
  return num * neg;
}
long long deg[300010], ans, n, k, tmp[300010];
bool cmp1(long long x, long long y) { return deg[x] > deg[y]; }
inline void solve() {
  for (long long i = 1; i <= n; i++)
    for (long long j = 2; i * j <= n; j++) deg[i * j]++;
  for (long long i = 1; i <= n; i++) ans += deg[i];
  if (ans < k) {
    printf("No\n");
    return;
  }
  if (k == 0) {
    printf("Yes\n");
    printf("1\n1");
    return;
  }
  long long m = n, cnt = 0;
  while (ans - deg[m] >= k) ans -= deg[m], m--;
  set<long long> res;
  for (long long i = m; i > m / 2; i--) tmp[++cnt] = i;
  for (long long i = 1; i <= m; i++) res.insert(i);
  sort(tmp + 1, tmp + cnt + 1, cmp1);
  for (long long i = 1; i <= cnt; i++) {
    if (ans - deg[tmp[i]] >= k) {
      ans -= deg[tmp[i]], res.erase(tmp[i]);
    }
  }
  set<long long>::iterator it = res.begin();
  if (ans == k) {
    printf("Yes\n");
    printf("%d\n", res.size());
    for (; it != res.end(); ++it) printf("%lld ", *it);
  } else
    printf("No\n");
}
signed main() {
  n = read(), k = read();
  solve();
  return 0;
}
