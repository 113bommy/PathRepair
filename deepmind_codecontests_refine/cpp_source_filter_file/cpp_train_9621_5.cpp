#include <bits/stdc++.h>
long long inp() {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  long long sum = 0;
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum;
}
struct Node {
  long long v, c;
} s[200010];
long long f[200010], f2[200010];
struct Line {
  long long k, b;
  long long get2(long long x) { return k * x + b; }
  long long get(long long x) { return (x - b - 1) / k + 1; }
} st[200010];
int top = 0;
bool cmp(Node a, Node b) {
  if (a.v == b.v) return a.c > b.c;
  return a.v < b.v;
}
int main() {
  int n = inp();
  long long r = inp();
  for (int i = 1; i <= n; i++) {
    s[i].c = inp();
    s[i].v = inp();
    if (s[i].v >= r) {
      i--;
      n--;
    }
  }
  s[++n].v = r;
  int cnt = 0;
  std::sort(s + 1, s + n, cmp);
  for (int i = 2; i <= n; i++) {
    s[i] = s[i + cnt];
    if (i == n) break;
    if (s[i].c <= s[i - 1].c) {
      cnt++;
      i--;
      n--;
    }
  }
  st[1] = (Line){s[1].c, 0};
  top = 1;
  int pos = 1;
  for (int i = 2; i <= n; i++) {
    while (pos < top && st[pos].get2((st[pos + 1].b - st[pos].b) /
                                     (st[pos].k - st[pos + 1].k)) < s[i].v)
      pos++;
    f[i] = st[pos].get(s[i].v);
    f2[i] = st[pos].get2(f[i]) - s[i].v;
    Line x = (Line){s[i].c, f2[i] - (f[i] * s[i].c)};
    while (top > 2 && ((st[top - 1].k - st[top].k) * (x.b - st[top].b) <=
                       (x.k - st[top].k) * (st[top - 1].b - st[top].b)))
      top--;
    st[++top] = x;
  }
  printf("%lld\n", f[n]);
}
