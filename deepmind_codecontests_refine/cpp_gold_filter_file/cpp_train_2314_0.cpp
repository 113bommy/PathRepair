#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
long long n;
long long fa[1010000], lg[1010000];
long long cnt[1010000], maxx = 0;
long long a[1010000];
long long find(long long x) {
  if (x == fa[x]) return x;
  return fa[x] = find(fa[x]);
}
signed main() {
  n = read();
  long long ans = 0;
  for (long long i = 1; i <= n; i++)
    a[i] = read(), maxx = max(maxx, a[i]), ans -= a[i], cnt[a[i]]++;
  for (long long i = 1; i <= maxx; i++) fa[i] = i, lg[i] = lg[i >> 1] + 1;
  cnt[0]++;
  long long m = 1 << (lg[maxx] + 1);
  for (register long long i = m - 1; ~i; i--) {
    for (long long j = i; j * 2 > i; j = (j - 1) & i) {
      long long x = j, y = i ^ j;
      if (!cnt[x] || !cnt[y]) continue;
      x = find(x), y = find(y);
      if (x != y) {
        ans += i * (cnt[x] + cnt[y] - 1);
        fa[x] = y;
        cnt[y] = 1;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
