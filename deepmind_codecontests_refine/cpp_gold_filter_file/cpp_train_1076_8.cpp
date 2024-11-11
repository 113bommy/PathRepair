#include <bits/stdc++.h>
using namespace std;
template <typename T>
void get_int(T &x) {
  char t = getchar();
  bool neg = false;
  x = 0;
  for (; (t > '9' || t < '0') && t != '-'; t = getchar())
    ;
  if (t == '-') neg = true, t = getchar();
  for (; t <= '9' && t >= '0'; t = getchar()) x = x * 10 + t - '0';
  if (neg) x = -x;
}
template <typename T>
void print_int(T x) {
  if (x < 0) putchar('-'), x = -x;
  short a[20] = {}, sz = 0;
  while (x > 0) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
const int inf = 0x3f3f3f3f;
const long long Linf = 1ll << 61;
const double pi = acos(-1.0);
const unsigned long long base = 3333331;
int n, s[100111];
unsigned long long power[100111], hs[100111];
unsigned long long calhash(int x, int y) {
  return (hs[y] - hs[x - 1]) * power[n - x];
}
int lcp(int x, int y) {
  int l = 0, r = min(n - x + 1, n - y + 1) + 1, mid;
  while (l < r - 1) {
    mid = (l + r) >> 1;
    if (calhash(x, x + mid - 1) == calhash(y, y + mid - 1))
      l = mid;
    else
      r = mid;
  }
  return l;
}
int lcs(int x, int y) {
  int l = 0, r = min(x, y) + 1, mid;
  while (l < r - 1) {
    mid = (l + r) >> 1;
    if (calhash(x - mid + 1, x) == calhash(y - mid + 1, y))
      l = mid;
    else
      r = mid;
  }
  return l;
}
int pre[100111], p[100111];
vector<int> v;
int main() {
  power[0] = 1;
  for (int i = 1; i < 100111; i++) power[i] = power[i - 1] * base;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", s + i);
  v.push_back(-1);
  for (int i = 1; i <= n; i++) v.push_back(s[i]);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (int i = 1; i <= n; i++)
    s[i] = lower_bound(v.begin(), v.end(), s[i]) - v.begin();
  for (int i = 1; i <= n; i++) hs[i] = hs[i - 1] + power[i] * s[i];
  for (int len = 1; len + len <= n; len++) {
    bool fg = 0;
    for (int i = len; i + len <= n; i += len) {
      int j = i + len, l1 = lcs(i, j), l2 = lcp(i + 1, j + 1);
      if (l1 + l2 < len || l1 == 0) continue;
      int l = i - min(len, l1) + 1, r = i - max(1, len - l2) + 1;
      fg = 1;
      p[l]++;
      p[r + 1]--;
    }
    if (fg) {
      for (int i = 1; i <= n; i++) p[i] += p[i - 1];
      for (int i = 1, j; i <= n; i++) {
        if (p[i] == 0) continue;
        for (j = i; j <= n && p[j] > 0; j++)
          ;
        j--;
        pre[i]++;
        pre[(j - i) / len * len + i + len]--;
        i = j + 1;
      }
      int cur = 0, nn = 0, last = 0;
      for (int i = 1; i <= n; i++) {
        cur += pre[i];
        if (cur) last = i + 1;
      }
      for (int i = last; i <= n; i++) s[++nn] = s[i];
      n = nn;
      memset(pre, 0, sizeof(pre));
      memset(p, 0, sizeof(p));
      for (int i = 1; i <= n; i++) hs[i] = hs[i - 1] + power[i] * s[i];
    }
  }
  printf("%d\n", n);
  for (int i = 1; i <= n; i++) printf("%d ", v[s[i]]);
  return 0;
}
