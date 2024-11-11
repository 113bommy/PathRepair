#include <bits/stdc++.h>
using namespace std;
long long n, tot, Now, h[3005], e[3005], b[3005], s[3005], f[3005];
struct Point {
  long long v, p, x, y;
} p[3005];
int cmp1(const Point &a, const Point &b) {
  long long ax = a.x - p[Now].x, ay = a.y - p[Now].y;
  long long bx = b.x - p[Now].y, by = b.y - p[Now].y;
  return (ax * by - ay * bx) > 0;
}
int cmp2(const Point &a, const Point &b) { return (a.p < b.p); }
void Add(long long x, long long y) {
  b[++tot] = y;
  e[tot] = h[x];
  h[x] = tot;
}
void Dfs(long long x) {
  s[x] = 1;
  for (long long go = h[x]; go; go = e[go])
    if (f[x] != b[go]) f[b[go]] = x, Dfs(b[go]), s[x] += s[b[go]];
}
void Rec(long long x, long long l, long long r) {
  long long pos = l;
  for (long long i = l + 1; i <= r; i++)
    if (p[i].y < p[pos].y) pos = i;
  swap(p[pos], p[l]);
  p[l].v = x;
  pos = l + 1;
  Now = l;
  sort(p + l + 1, p + r + 1, cmp1);
  for (int go = h[x]; go; go = e[go])
    if (b[go] != f[x]) {
      Rec(b[go], pos, pos + s[b[go]] - 1);
      pos += s[b[go]];
    }
}
int main() {
  cin >> n;
  long long a, b;
  for (long long i = 1; i < n; i++) {
    cin >> a >> b;
    Add(--a, --b);
    Add(b, a);
  }
  Dfs(0);
  for (long long i = 0; i < n; i++) cin >> p[i].x >> p[i].y, p[i].p = i;
  Rec(0, 0, n - 1);
  sort(p, p + n, cmp2);
  for (long long i = 0; i < n; i++) cout << p[i].v + 1 << ' ';
  return 0;
}
