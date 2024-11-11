#include <bits/stdc++.h>
using namespace std;
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "RDLU";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int &x, int y, int mod) {
  x += y;
  if (x >= mod) x -= mod;
}
void et() {
  puts("-1");
  exit(0);
}
int t[200105];
long double pre[200105], sum[200105], rev[200105];
long double dp[200105][55];
struct Line {
  long double a, b;
  long double get(long double x) { return a * x + b; }
};
struct ConvexHull {
  int size;
  Line *hull;
  ConvexHull(int maxSize) {
    hull = new Line[++maxSize];
    size = 0;
  }
  void clear() { size = 0; }
  bool is_bad(int curr, int prev, int next) {
    Line c = hull[curr], p = hull[prev], n = hull[next];
    return (c.b - n.b) * (c.a - p.a) <= (p.b - c.b) * (n.a - c.a);
  }
  void add_line(long double a, long double b) {
    hull[size++] = (Line){a, b};
    while (size > 2 && is_bad(size - 2, size - 3, size - 1)) {
      hull[size - 2] = hull[size - 1];
      size--;
    }
  }
  long double query(long double x) {
    int l = -1, r = size - 1;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (hull[m].get(x) <= hull[m + 1].get(x))
        l = m;
      else
        r = m;
    }
    long double z = hull[r].get(x);
    return z;
  }
};
void fmain() {
  scanf("%d%d", &n, &k);
  for (int(i) = 1; (i) <= (int)(n); (i)++) scanf("%d", t + i);
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    sum[i] = sum[i - 1] + t[i];
    rev[i] = rev[i - 1] + (long double)1 / t[i];
    pre[i] = pre[i - 1] + sum[i] / t[i];
    dp[i][1] = pre[i];
  }
  ConvexHull ch = ConvexHull(n);
  for (int j = 2; j <= k; j++) {
    ch.clear();
    for (int i = j, l = j - 1; i <= n; i++) {
      dp[i][j] = (1LL << 60);
      while (l < i) {
        ch.add_line((sum[l]), -(dp[l][j - 1] - pre[l] + rev[l] * sum[l]));
        l++;
      }
      dp[i][j] = min(dp[i][j], -ch.query(rev[i]) + pre[i]);
    }
  }
  printf("%.10Lf\n", dp[n][k]);
}
int main() {
  fmain();
  return 0;
}
