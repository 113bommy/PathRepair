#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10ll + c - '0';
    c = getchar();
  }
  return x * f;
}
const int maxn = 100010;
long long F(long long x, long long y) { return x - 3ll * y * y + 3ll * y - 1; }
long long n, k, a[maxn], L = 9e18, R = -9e18, ans[maxn], pos[maxn], minn = 9e18;
priority_queue<pair<long long, long long>, vector<pair<long long, long long> >,
               greater<pair<long long, long long> > >
    Q;
bool judge(long long index) {
  long long sum = 0;
  for (long long i = 1; i <= n; i++) {
    long long left = 0, right = a[i];
    while (right - left > 1) {
      long long mid = left + right >> 1ll;
      if (F(a[i], mid) >= index)
        left = mid;
      else
        right = mid;
    }
    if (F(a[i], left) >= index)
      pos[i] = left;
    else
      pos[i] = right;
    sum += pos[i];
  }
  if (sum - k < minn && sum >= k) {
    minn = sum - k;
    for (long long i = 1; i <= n; i++) ans[i] = pos[i];
  }
  return sum < k;
}
int main() {
  n = read();
  k = read();
  for (long long i = 1; i <= n; i++)
    a[i] = read(), L = min(L, F(a[i], a[i])), R = max(R, a[i]);
  while (R - L > 1) {
    long long mid = L + R >> 1ll;
    if (judge(mid))
      R = mid;
    else
      L = mid;
  }
  judge(L);
  judge(R);
  for (int i = 1; i <= n; i++)
    if (ans[i]) Q.push(make_pair(F(a[i], ans[i]), i));
  if (Q.empty()) {
    printf("������ %lld\n", L);
    return 0;
  }
  while (minn--) {
    pair<long long, long long> now = Q.top();
    Q.pop();
    ans[now.second]--;
    if (ans[now.second])
      Q.push(make_pair(F(a[now.second], ans[now.second]), now.second));
  }
  for (int i = 1; i < n; i++) printf("%lld ", ans[i]);
  printf("%lld\n", ans[n]);
  return 0;
}
