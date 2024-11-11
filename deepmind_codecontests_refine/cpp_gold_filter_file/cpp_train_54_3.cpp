#include <bits/stdc++.h>
using namespace std;
int maxa, maxb, w;
inline int rev(int x) {
  int nowans = 0;
  for (; x;) nowans = nowans * 10 + x % 10, x /= 10;
  return nowans;
}
int re[200010];
inline int gcd(int a, int b) { return (!b) ? a : gcd(b, a % b); }
int dex[200010], tot = 1;
struct node {
  int ed, before;
} g[500010];
inline void add(int x, int y) {
  g[++tot].ed = y;
  g[tot].before = dex[x];
  dex[x] = tot;
}
int H;
map<pair<int, int>, int> mp;
int father[200010];
int sum[200010];
int newx, newy;
int main() {
  scanf("%d%d%d", &maxa, &maxb, &w);
  int N = max(maxa, maxb);
  for (int i = 1; i <= N; i++) re[i] = rev(i);
  for (int i = 1; i <= N; i++) {
    int x = i, y = re[i], k = gcd(x, y);
    x /= k, y /= k;
    if (mp.find(make_pair(x, y)) == mp.end()) mp[make_pair(x, y)] = ++H;
    k = mp[make_pair(x, y)];
    add(k, i);
    if (mp.find(make_pair(y, x)) == mp.end()) mp[make_pair(y, x)] = ++H;
    k = mp[make_pair(y, x)];
    father[i] = k;
  }
  long long ans = LLONG_MAX;
  int B = maxb + 1;
  int tmp = 0;
  for (int A = 1; A <= maxa; A++) {
    for (int j = dex[father[A]]; j; j = g[j].before) {
      int v = g[j].ed;
      if (v <= maxb && v <= B) {
        sum[v]++, tmp++;
      }
    }
    for (; tmp - sum[B] >= w; tmp -= sum[B], B--)
      ;
    if (tmp >= w) {
      if (ans >= 1ll * A * B) {
        ans = 1ll * A * B;
        newx = A, newy = B;
      }
    }
  }
  if (ans == LLONG_MAX)
    printf("-1\n");
  else
    printf("%d %d\n", newx, newy);
}
