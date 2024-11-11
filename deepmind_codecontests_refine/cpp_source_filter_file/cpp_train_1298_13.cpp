#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int s = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) s = s * 10 + ch - '0', ch = getchar();
  return s;
}
const int N = 1e5 + 5;
int n, m, k, p;
int h[N], a[N], c[N];
inline bool check(long long x) {
  memset(c, 0, sizeof(c));
  priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                 greater<pair<long long, int>>>
      q;
  for (int i = 1; i <= n; i++)
    if (x - a[i] * m < h[i]) q.push({x / a[i], i});
  for (int i = 1; i <= m && !q.empty(); i++)
    for (int j = 1; j <= k && !q.empty(); j++) {
      auto u = q.top();
      q.pop();
      if (u.first < i) return 0;
      c[u.second]++;
      if (x + c[u.second] * p - a[u.second] * m < h[u.second])
        q.push({(x + c[u.second] * p) / a[u.second], u.second});
    }
  return q.empty();
}
int main() {
  n = read(), m = read(), k = read(), p = read();
  for (int i = 1; i <= n; i++) h[i] = read(), a[i] = read();
  long long l = 0, r = 1e16, ans = 0;
  for (int i = 1; i <= 60; i++) {
    long long mid = (l + r) >> 1;
    if (check(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%lld", ans);
  return 0;
}
