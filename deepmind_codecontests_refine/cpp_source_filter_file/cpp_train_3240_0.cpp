#include <bits/stdc++.h>
using namespace std;
pair<int, int> p[55];
int calc(int T, int n) {
  static pair<int, int> a[105], b[205];
  int tot = 0;
  for (int i = 1; i <= n; i++) {
    a[++tot] = pair<int, int>(p[i].first - T, i);
    a[++tot] = pair<int, int>(p[i].first + T + 1, -i);
  }
  sort(a + 1, a + tot + 1);
  int ans = 0, cnt = 0;
  for (int i = 1, j = 0; i <= tot; i = j + 1) {
    while (a[j + 1].first == a[i].first) j++;
    for (int k = i; k <= j; k++) {
      int t = abs(a[k].second);
      if (a[k].second > 0) {
        b[++cnt] = pair<int, int>(p[t].second - T, 1);
        b[++cnt] = pair<int, int>(p[t].second + T + 1, -1);
      } else {
        b[++cnt] = pair<int, int>(p[t].second - T, -1);
        b[++cnt] = pair<int, int>(p[t].second + T + 1, 1);
      }
    }
    sort(b + 1, b + cnt + 1);
    int s = 0, val = 0;
    for (int k = 1; k <= cnt; k++) {
      if (val) s += b[k].first - b[k - 1].first;
      val += b[k].second;
    }
    ans = (ans + (long long)s * (a[j + 1].first - a[i].first)) % 998244353;
  }
  return ans;
}
inline long long S1(long long n) {
  return n * (n + 1) % 998244353 * 499122177 % 998244353;
}
inline long long S2(long long n) {
  return n * (n + 1) % 998244353 * (2LL * n + 1) % 998244353 * 166374059 %
         998244353;
}
int getsum(int l, int r, int n) {
  if (r - l < 3) {
    int ans = 0;
    for (int i = l; i <= r; i++) ans = (ans + calc(i, n)) % 998244353;
    return ans;
  } else {
    long long s1 = calc(l, n), s2 = calc(l + 1, n), s3 = calc(l + 2, n);
    long long v0 = s1,
              v2 = ((s3 - s1 + 998244353) * 499122177 -
                    (s2 - s1 + 998244353) % 998244353 + 998244353) %
                   998244353,
              v1 = ((s2 - v0 - v2) % 998244353 + 998244353) % 998244353;
    return (v0 * (r - l + 1) + v1 * S1(r - l) + v2 * S2(r - l)) % 998244353;
  }
}
int a[2505];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    p[i] = pair<int, int>(x, y);
  }
  int cnt = 0;
  a[++cnt] = 0;
  a[++cnt] = m;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      int x = max((abs(p[i].first - p[j].first) + 1) >> 1,
                  (abs(p[i].second - p[j].second) + 1) >> 1);
      if (x < m) a[++cnt] = x;
    }
  sort(a + 1, a + cnt + 1);
  cnt = unique(a + 1, a + cnt + 1) - a - 1;
  int ans = (long long)m * calc(m, n) % 998244353;
  for (int i = 1; i < cnt; i++)
    ans = (ans - getsum(a[i], a[i + 1] - 1, n) + 998244353) % 998244353;
  printf("%d\n", ans);
  return 0;
}
