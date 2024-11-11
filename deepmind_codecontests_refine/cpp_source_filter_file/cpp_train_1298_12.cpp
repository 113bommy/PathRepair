#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long f = 1, ans = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + c - '0';
    c = getchar();
  }
  return f * ans;
}
const long long MAXN = 100001;
priority_queue<pair<long long, long long> > que;
long long a[MAXN], N, M, k, p, h[MAXN];
long long Ans[MAXN], cnt = 0;
bool check(long long Lim) {
  while (!que.empty()) que.pop();
  memset(Ans, 0, sizeof(Ans));
  cnt = 0;
  for (long long i = 1; i <= N; i++)
    if (Lim - a[i] * M < h[i]) que.push(make_pair(-(Lim / a[i]), i));
  for (long long i = 1; i <= M; i++) {
    bool ff = 0;
    for (long long j = 1; j <= k; j++) {
      if (que.empty()) {
        ff = 1;
        continue;
      }
      long long res = -que.top().first, id = que.top().second;
      que.pop();
      if (res < i) return 0;
      Ans[id]++;
      long long w = (Lim + p * Ans[id]) / a[id];
      if (w < M) que.push(make_pair(-w, id));
      ++cnt;
    }
    if (ff) break;
  }
  for (long long i = 1; i <= N; i++) {
    long long w = Lim + p * Ans[i] - M * a[i];
    if (w >= h[i]) continue;
    cnt += ((h[i] - w - 1) / p) + 1;
  }
  return cnt <= M * k;
}
signed main() {
  N = read(), M = read(), k = read(), p = read();
  for (long long i = 1; i <= N; i++) h[i] = read(), a[i] = read();
  long long l = 0, r = 1e9, res;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid))
      res = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%lld\n", res);
  return 0;
}
