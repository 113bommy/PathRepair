#include <bits/stdc++.h>
using namespace std;
const int MX = 300005;
long long n, m, k;
struct node {
  int id;
  long long pos;
  long long dir;
} no[MX];
int now[MX];
int ans[MX];
bool cmp(node a, node b) {
  if (a.pos < b.pos) return true;
  return false;
}
int main() {
  char ss[5];
  scanf("%I64d%I64d%I64d", &n, &m, &k);
  long long p = 0;
  for (int i = 0; i < n; i++) {
    scanf("%I64d%s", &no[i].pos, ss);
    --no[i].pos;
    no[i].id = i;
    no[i].dir = 1;
    if (ss[0] == 'L') no[i].dir = -1;
    if (ss[0] == 'R')
      p += (k + no[i].pos) / m;
    else
      p -= (k + m - 1 - no[i].pos) / m;
    p %= m;
    now[i] = ((no[i].pos + no[i].dir * k) % m + m) % m;
  }
  sort(no, no + n, cmp);
  sort(now, now + n);
  for (int i = 0; i < n; i++) {
    ans[no[((i - p) % n + n) % n].id] = now[i] + 1;
  }
  for (int i = 0; i < n; i++) {
    printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
  }
  return 0;
}
