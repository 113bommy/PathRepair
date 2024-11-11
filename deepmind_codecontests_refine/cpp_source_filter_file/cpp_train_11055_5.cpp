#include <bits/stdc++.h>
using namespace std;
const int N = 666666, M = 11111111;
long long MOD = 998244353, inv2 = (MOD + 1) / 2;
long double eps = 1e-8;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
long double pi = acos(-1.0L);
int read() {
  int v = 0, f = 1;
  char c = getchar();
  while (c < 48 || 57 < c) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (48 <= c && c <= 57) v = (v << 3) + v + v + c - 48, c = getchar();
  return v * f;
}
long long readll() {
  long long v = 0, f = 1;
  char c = getchar();
  while (c < 48 || 57 < c) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (48 <= c && c <= 57) v = (v << 3) + v + v + c - 48, c = getchar();
  return v * f;
}
struct node {
  int t, a, b;
} a[N];
bool cmpt(node a, node b) { return a.t < b.t; }
int n, m, c, c0;
void init() {
  n = read(), m = read(), c = read(), c0 = read();
  for (int i = (int)1; i <= (int)n; i++)
    a[i].t = read(), a[i].a = read(), a[i].b = read();
}
void solve() {
  a[++n].t = m;
  a[n].a = a[n].b = 0;
  sort(a + 1, a + n + 1, cmpt);
  int flag = 1;
  int now = c0;
  long long ans = 0;
  map<int, int> mp;
  mp[0] = c0;
  for (int i = (int)1; i <= (int)n; i++) {
    int t = a[i].t - a[i - 1].t;
    while (!mp.empty() && t) {
      int tmp = min(t, mp.begin()->second);
      ans += 1ll * mp.begin()->first * tmp;
      t -= tmp;
      now -= tmp;
      mp.begin()->second -= tmp;
      if (mp.begin()->second == 0) mp.erase(mp.begin());
    }
    if (t) {
      flag = 0;
      break;
    }
    int add = min(c - now, a[i].a);
    now += add;
    while (!mp.empty() && add < a[i].a && mp.rbegin()->first > a[i].b) {
      if (a[i].a - add >= mp.rbegin()->second) {
        add += mp.rbegin()->second;
        mp.erase(--mp.end());
      } else {
        mp.rbegin()->second = a[i].a - add;
        add = a[i].a;
      }
    }
    mp[a[i].b] += a[i].a;
  }
  if (flag)
    printf("%I64d\n", ans);
  else
    printf("-1\n");
}
int main() {
  int cas = read();
  while (cas--) {
    init();
    solve();
  }
  return 0;
}
