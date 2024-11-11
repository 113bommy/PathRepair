#include <bits/stdc++.h>
using namespace std;
int read() {
  char c = getchar();
  int x = 0;
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
  return x;
}
const int N = 1e5 + 10;
long long a[N], h[N], n, m, k, p;
struct NUM {
  int ed;
  long long v;
  int id, st;
  bool operator<(const NUM &a) const { return ed > a.ed; }
  NUM(int _a = 0, long long _b = 0, int _c = 0, int _d = 0) {
    ed = _a, v = _b, id = _c, st = _d;
  }
};
priority_queue<NUM> q;
bool check(long long x) {
  while (q.size()) q.pop();
  for (int i = 1; i <= n; ++i) {
    if (x - m * a[i] >= h[i]) continue;
    q.push(NUM(x / a[i], x, i, 0));
  }
  for (int i = 1; i <= m; ++i) {
    long long res = m - i;
    for (int j = 1; j <= k; ++j) {
      if (q.empty()) return 1;
      NUM now = q.top();
      q.pop();
      if (now.ed < i) return 0;
      long long v = now.v - 1ll * (i - now.st) * a[now.id] + p;
      if (v - res * a[now.id] >= h[i]) continue;
      q.push(NUM(max((long long)i, i + v / a[now.id]), v, now.id, i));
    }
  }
  if (q.empty()) return 1;
  return 0;
}
int main() {
  n = read(), m = read(), k = read(), p = read();
  for (int i = 1; i <= n; ++i) h[i] = read(), a[i] = read();
  long long l = 1, r = 1e15;
  long long ans = 0;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  cout << ans << endl;
  return 0;
}
