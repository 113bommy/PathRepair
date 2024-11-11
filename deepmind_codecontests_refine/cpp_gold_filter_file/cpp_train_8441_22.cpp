#include <bits/stdc++.h>
using namespace std;
int a[4010];
struct node {
  long long x, y;
  double ang;
  node() {}
  node(long long x0, long long y0) : x(x0), y(y0) {}
  bool operator<(const node &a) const { return ang < a.ang; }
  node operator-(const node &a) const { return node(x - a.x, y - a.y); }
  node operator+(const node &a) const { return node(x + a.x, y + a.y); }
  long long operator^(const node &a) const { return x * a.y - y * a.x; }
} p[4010], Vec[4010];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d%I64d", &p[i].x, &p[i].y);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    long long tot = 0;
    for (int j = 1; j <= n; j++)
      if (i != j) {
        Vec[++tot] = p[j] - p[i];
        Vec[tot].ang = atan2(Vec[tot].y, Vec[tot].x);
      }
    sort(Vec + 1, Vec + 1 + tot);
    for (int j = 1; j <= tot; j++) Vec[j + tot] = Vec[j];
    long long t = 2;
    for (long long j = 1; j <= tot; j++) {
      if (t == j) t++;
      while (t < j + tot && (Vec[t] ^ Vec[j]) < 0) t++;
      ans += (t - j - 1ll) * (t - j - 2ll) / 2ll * (tot - t + j) *
             (tot - t + j - 1ll) / 2ll;
    }
  }
  printf("%I64d", ans / 2ll);
}
