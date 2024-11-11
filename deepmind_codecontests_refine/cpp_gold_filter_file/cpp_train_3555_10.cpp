#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 5;
long long read() {
  long long s = 0;
  char c = getchar(), lc = '+';
  while (c < '0' || '9' < c) lc = c, c = getchar();
  while ('0' <= c && c <= '9') s = s * 10 + c - '0', c = getchar();
  return lc == '-' ? -s : s;
}
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x < 10)
    putchar(x + '0');
  else
    write(x / 10), putchar(x % 10 + '0');
}
void print(long long x = -1, char c = '\n') {
  write(x);
  putchar(c);
}
struct node {
  long long u, v, w;
};
vector<node> ans;
long long st[N], top = 0;
long long a[N], s[N], t[N], p[N], d[N];
bool cmp(long long x, long long y) { return a[x] < a[y]; }
signed main(signed Recall, char *_902_[]) {
  (void)Recall, (void)_902_;
  long long n = read(), sum = 0;
  for (long long i = 1; i <= n; i++) a[i] = read();
  for (long long i = 1; i <= n; i++) p[i] = i;
  sort(p + 1, p + 1 + n, cmp);
  for (long long i = 1; i <= n; i++) s[i] = a[p[i]];
  for (long long i = 1; i <= n; i++) t[i] = read();
  sort(t + 1, t + 1 + n);
  for (long long i = 1; i <= n; i++) d[i] = t[i] - s[i];
  for (long long i = 1; i <= n; i++)
    if ((sum += d[i]) < 0) return puts("NO") * 0;
  if (sum) return puts("NO") * 0;
  for (long long i = 1; i <= n; i++)
    if (d[i] > 0)
      st[++top] = i;
    else if (d[i] < 0) {
      long long now = -d[i];
      while (now) {
        long long tmp = min(d[st[top]], now);
        ans.push_back((node){i, st[top], tmp});
        d[st[top]] -= tmp;
        now -= tmp;
        if (d[st[top]] == 0) top--;
      }
    }
  puts("YES");
  print(ans.size());
  for (node i : ans) print(p[i.v], ' '), print(p[i.u], ' '), print(i.w);
  return 0;
}
