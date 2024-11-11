#include <bits/stdc++.h>
int inp() {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  int sum = 0;
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum;
}
struct Node {
  int l;
  int r;
  int id;
} s[200010];
int a[200010];
long long cnt[1000010], ans, res[200010];
bool cmp(Node a, Node b) {
  if ((a.l / 450) == (b.l / 450)) {
    if ((a.l / 450) & 1) return a.r < b.r;
    return a.r > b.r;
  }
  return a.l < b.l;
}
void add(long long x) {
  x = a[x];
  ans -= (cnt[x] * cnt[x]) * x;
  cnt[x]++;
  ans += (cnt[x] * cnt[x]) * x;
}
void del(long long x) {
  x = a[x];
  ans -= (cnt[x] * cnt[x]) * x;
  cnt[x]--;
  ans += (cnt[x] * cnt[x]) * x;
}
int main() {
  int n = inp();
  int m = inp();
  for (int i = 1; i <= n; i++) a[i] = inp();
  for (int i = 1; i <= m; i++) {
    s[i].l = inp();
    s[i].r = inp();
    s[i].id = i;
  }
  std::sort(s + 1, s + m + 1, cmp);
  int l = 1;
  int r = 0;
  for (int i = 1; i <= m; i++) {
    while (l > s[i].l) add(--l);
    while (r < s[i].r) add(++r);
    while (l < s[i].l) del(l++);
    while (r > s[i].r) del(r--);
    res[s[i].id] = ans;
  }
  for (int i = 1; i <= m; i++) printf("%lld\n", res[i]);
}
