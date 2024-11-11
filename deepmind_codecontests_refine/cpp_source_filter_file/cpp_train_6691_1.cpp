#include <bits/stdc++.h>
using namespace std;
int p1 = 1000000, p2 = 0;
char buf[1000005], wb[1000005];
int getint() {
  int ret = 0, flag = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') flag = -1;
    c = getchar();
  }
  while (c <= '9' && c >= '0') {
    ret = (ret << 3) + (ret << 1) + c - '0';
    c = getchar();
  }
  return ret * flag;
}
void pc(char x) {
  if (p2 >= 1000000) fwrite(wb, 1, 1000000, stdout), p2 = 0;
  wb[p2++] = x;
}
void wrt(int x) {
  if (x < 0) pc('-'), x = -x;
  int c[24] = {0};
  if (!x) return pc('0'), void();
  while (x) c[++c[0]] = x % 10, x /= 10;
  while (c[0]) pc(c[c[0]--] + '0');
}
long long n, s, a[10005], id[10005];
bool cmp(int a, int b) { return id[a] > id[b]; }
int ansx[10005], ansy[10005], ans[10005];
int main() {
  int Ti = getint();
  while (Ti--) {
    s = 0;
    n = getint();
    for (int i = 1; i <= n; i++) s += (a[i] = getint()), id[i] = i;
    if (s % n)
      wrt(-1), pc('\n');
    else {
      s = s / n;
      ans[0] = 0;
      for (int i = 2; i <= n; i++) {
        if (a[i] % i != 0) {
          long long val = i - a[i] % i;
          ++ans[0];
          ansx[ans[0]] = 1;
          ansy[ans[0]] = i;
          ans[ans[0]] = val;
        }
        if (a[i]) {
          long long val = a[i] / i + (a[i] % i == 0 ? 0 : 1);
          ++ans[0];
          ansx[ans[0]] = i;
          ansy[ans[0]] = 1;
          ans[ans[0]] = val;
        }
      }
      for (int i = 2; i <= n; i++) {
        ++ans[0];
        ansx[ans[0]] = 1;
        ansy[ans[0]] = i;
        ans[ans[0]] = s;
      }
      wrt(ans[0]), pc('\n');
      for (int i = 1; i <= ans[0]; i++)
        wrt(ansx[i]), pc(' '), wrt(ansy[i]), pc(' '), wrt(ans[i]), pc('\n');
    }
  }
  fwrite(wb, 1, p2, stdout);
  return 0;
}
