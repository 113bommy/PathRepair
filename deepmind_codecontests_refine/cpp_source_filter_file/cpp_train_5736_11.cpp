#include <bits/stdc++.h>
using namespace std;
char buf[25];
const int maxn = 200010;
int a[maxn], cnt[maxn];
int n, m;
int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return f ? -x : x;
}
void write(long long x) {
  if (!x) {
    putchar('0');
    return;
  }
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  int cnt = 0;
  while (x) {
    buf[++cnt] = '0' + x % 10;
    x /= 10;
  }
  for (int i = cnt; i >= 1; --i) putchar(buf[i]);
}
long long solve(int x) {
  for (int i = 0; i <= n * 2; ++i) cnt[i] = 0;
  cnt[n] = 1;
  int s = n;
  long long sum = 0, ans = 0;
  if (a[1] <= x) {
    ++sum;
    ++ans;
    ++cnt[++s];
  } else
    ++cnt[--s];
  for (int i = 2; i <= n; ++i) {
    if (a[i] <= x)
      sum += cnt[++s];
    else
      sum -= cnt[s--];
    ans += sum;
    ++cnt[s];
  }
  return ans;
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  write(solve(m) - solve(m - 1));
  putchar('\n');
  return 0;
}
