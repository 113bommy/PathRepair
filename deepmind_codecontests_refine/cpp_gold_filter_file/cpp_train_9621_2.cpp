#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
struct nd {
  int v, c;
} a[N];
struct po {
  long long x, y;
};
struct li {
  int k;
  po p;
} b[N];
int top = 0, n;
long long s;
bool cmp(nd x, nd y) { return x.v < y.v; }
po getp(int x, int y) {
  po res;
  res.x = ((-b[x].k * b[x].p.x + b[x].p.y) + b[y].k * b[y].p.x - b[y].p.y) /
          (b[y].k - b[x].k);
  res.y = b[x].k * (res.x - b[x].p.x) + b[x].p.y;
  return res;
}
int main() {
  int i, j, k, l, r, mid, res;
  cin >> n >> s;
  for (i = 1; i <= n; i++) scanf("%d%d", &a[i].v, &a[i].c);
  sort(a + 1, a + n + 1, cmp);
  top = 0;
  for (i = 1; i <= n; i = j + 1) {
    j = i;
    a[++top] = a[i];
    while ((j < n) && (a[top].v == a[j + 1].v)) {
      j++;
      a[top].c = min(a[top].c, a[j].c);
    }
  }
  n = top;
  top = 0;
  for (i = 1; i <= n; i++) {
    while ((top) && (a[i].c <= a[top].c)) top--;
    a[++top] = a[i];
  }
  n = top;
  top = 1;
  b[1].p = (po){0, 0};
  b[1].k = a[1].v;
  for (i = 2; i <= n; i++) {
    l = 1;
    r = top - 1;
    res = top;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (getp(mid, mid + 1).y < a[i].c)
        l = mid + 1;
      else
        res = mid, r = mid - 1;
    }
    b[++top].p.x = b[res].p.x + (a[i].c - b[res].p.y + b[res].k - 1) / b[res].k;
    b[top].p.y = b[res].k * (b[top].p.x - b[res].p.x) + b[res].p.y - a[i].c;
    b[top].k = a[i].v;
    while ((top > 2) && (getp(top - 2, top - 1).x >= getp(top - 1, top).x))
      b[top - 1] = b[top--];
  }
  while ((top > 1) && (getp(top - 1, top).y >= s)) top--;
  long long ans = b[top].p.x + (s - b[top].p.y + b[top].k - 1) / b[top].k;
  cout << ans << endl;
  return 0;
}
