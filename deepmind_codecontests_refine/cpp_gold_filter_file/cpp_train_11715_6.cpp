#include <bits/stdc++.h>
using namespace std;
template <class T>
void in(T &x) {
  x = 0;
  bool f = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = 1;
    c = getchar();
  }
  while ('0' <= c && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  if (f) x = -x;
}
char pre[2000010];
long long lst[1000];
long long n, m, k;
priority_queue<long long> q;
long long g[2000010];
signed main() {
  in(n), in(k);
  scanf("%s", pre + 1);
  m = strlen(pre + 1);
  g[0] = 1;
  for (register long long i = 1; i <= m; ++i) {
    g[i] = ((g[i - 1] + g[i - 1] - (lst[pre[i]] ? g[lst[pre[i]] - 1] : 0)) %
                1000000007 +
            1000000007) %
           1000000007;
    lst[pre[i]] = i;
  }
  for (register long long i = 'a', j = 1; j <= k; ++j, ++i) {
    q.push(-lst[i]);
  }
  for (register long long i = m + 1; i <= m + n; ++i) {
    long long x = -q.top();
    q.pop();
    g[i] =
        ((g[i - 1] + g[i - 1] - (x ? g[x - 1] : 0)) % 1000000007 + 1000000007) %
        1000000007;
    q.push(-i);
  }
  printf("%lld", g[n + m]);
  return 0;
}
