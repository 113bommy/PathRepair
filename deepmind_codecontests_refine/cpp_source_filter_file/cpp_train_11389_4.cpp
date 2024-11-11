#include <bits/stdc++.h>
using namespace std;
char a[50010], b[50010];
long long p[50010], _p[50010], fac[50010], _fac[50010];
int l[50010], r[50010], n;
void calc() {
  int n2 = 0;
  for (int now = r[0]; now <= n; now = r[now]) b[++n2] = a[now];
  for (int i = 1; i <= n2; ++i) a[i] = b[i];
  n = n2;
  p[0] = _p[0] = 0;
  for (int i = 1; i <= n; ++i)
    p[i] = (p[i - 1] * 27 + a[i] - 'a' + 1) % 1000000007,
    _p[i] = (_p[i - 1] * 27 + a[i] - 'a' + 1) % 233333333;
  for (int i = 1; i <= n; ++i) l[i] = i - 1, r[i] = i + 1;
  r[0] = 1;
}
bool check(int x1, int y1, int x2, int y2) {
  int len = y1 - x1 + 1;
  int tmp1, tmp2;
  tmp1 = p[y1] - (p[x1 - 1] * fac[len]) % 1000000007, tmp1 %= 1000000007,
  tmp1 += 1000000007, tmp1 %= 1000000007;
  tmp2 = p[y2] - (p[x2 - 1] * fac[len]) % 1000000007, tmp2 %= 1000000007,
  tmp2 += 1000000007, tmp2 %= 1000000007;
  if (tmp1 != tmp2) return false;
  tmp1 = _p[y1] - (_p[x1 - 1] * _fac[len]) % 233333333, tmp1 %= 233333333,
  tmp1 += 233333333, tmp1 %= 233333333;
  tmp2 = _p[y2] - (_p[x2 - 1] * _fac[len]) % 233333333, tmp2 %= 233333333,
  tmp2 += 233333333, tmp2 %= 233333333;
  if (tmp1 != tmp2) return false;
  return true;
}
int lcs(int x, int y) {
  if (x < 1 || y > n) return 0;
  int l = 0, r = x, ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(x - mid + 1, x, y - mid + 1, y))
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  return ans;
}
int lcp(int x, int y) {
  if (x < 1 || y > n) return 0;
  int l = 0, r = n - y + 1, ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(x, x + mid - 1, y, y + mid - 1))
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  return ans;
}
bool jud(int x) {
  for (int i = x; i <= n; i += x) {
    int tmp = lcs(i - x, i) + lcp(i, i + x);
    if (tmp >= x) return true;
  }
  return false;
}
void del(int len) {
  for (int now = len * 2; now <= n; ++now)
    if (check(now - 2 * len + 1, now - len, now - len + 1, now)) {
      l[now - len + 1] = l[now - 2 * len + 1],
                    r[l[now - 2 * len + 1]] = now - len + 1;
      now += len - 1;
    }
}
void solve() {
  int st = strlen(a + 1);
  n = st;
  fac[0] = _fac[0] = 1;
  for (int i = 1; i <= n; ++i)
    fac[i] = (fac[i - 1] * 27) % 1000000007,
    _fac[i] = (_fac[i - 1] * 27) % 233333333;
  for (int i = 1; i <= st; ++i) l[i] = i - 1, r[i] = i + 1;
  r[0] = 1, calc();
  for (int i = 1; i <= n; ++i)
    if (jud(i)) {
      del(i), calc();
    }
  for (int i = 1; i <= n; ++i) printf("%c", a[i]);
  printf("\n");
}
int main() {
  scanf("%s", a + 1);
  solve();
  return 0;
}
