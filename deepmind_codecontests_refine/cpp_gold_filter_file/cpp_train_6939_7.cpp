#include <bits/stdc++.h>
using namespace std;
long long n, wn, hn;
long long aa, bb, cc, dd, tot, ans;
struct node {
  long long w, h, c, ww, hh;
} s[2000005];
map<long long, long long> a[2000005];
void init() { freopen("e.in", "r", stdin); }
bool cmp1(const node &a, const node &b) { return a.w < b.w; }
bool cmp2(const node &a, const node &b) { return a.h < b.h; }
long long gcd(long long x, long long y) {
  if (!y)
    return x;
  else
    return gcd(y, x % y);
}
int main() {
  scanf("%I64d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d%I64d%I64d", &s[i].w, &s[i].h, &s[i].c);
    if (i == 1)
      tot = s[i].c;
    else
      tot = gcd(tot, s[i].c);
  }
  sort(s + 1, s + n + 1, cmp1);
  for (int i = 1; i <= n; i++) {
    if (s[i].w == s[i - 1].w)
      s[i].ww = s[i - 1].ww;
    else
      s[i].ww = s[i - 1].ww + 1;
  }
  for (int i = 1; i <= n; i++)
    if (s[i].w != s[i - 1].w) wn++;
  sort(s + 1, s + n + 1, cmp2);
  for (int i = 1; i <= n; i++) {
    if (s[i].h == s[i - 1].h)
      s[i].hh = s[i - 1].hh;
    else
      s[i].hh = s[i - 1].hh + 1;
  }
  for (int i = 1; i <= n; i++)
    if (s[i].h != s[i - 1].h) hn++;
  if (wn * hn != n) {
    printf("0");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    a[s[i].ww][s[i].hh] = s[i].c;
  }
  for (int i = 1; i <= hn - 1; i++) {
    for (int j = 1; j <= wn - 1; j++) {
      aa = a[j][i];
      bb = a[j][i + 1];
      cc = a[j + 1][i];
      dd = a[j + 1][i + 1];
      if (aa * dd != bb * cc) {
        printf("0");
        return 0;
      }
    }
  }
  for (int i = 1; i <= trunc(sqrt(tot)); i++) {
    if (tot % i == 0) {
      ans++;
      if (tot / i != i) ans++;
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
