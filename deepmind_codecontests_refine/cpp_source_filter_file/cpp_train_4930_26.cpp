#include <bits/stdc++.h>
using namespace std;
struct plank {
  int dt, where;
};
plank a[1000010];
int cmp(const plank &a, const plank &b) { return a.dt > b.dt; }
struct dsu {
  int p[1000010];
  dsu() {
    for (int i = (0); i <= (1000010 - 1); i++) p[i] = i;
  }
  int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
  }
  void merge(int x, int y) { p[find(x)] = find(y); }
};
dsu dl, dr;
long long s[1000010], d[1000010], final[1000010];
void addseqend(int l, long long a0, long long delta) {
  s[l] += a0;
  d[l] += delta;
}
void addseq(int l, int r, long long a0, long long delta) {
  if (l > r) return;
  addseqend(l, a0, delta);
  addseqend(r + 1, -(a0 + delta * (r - l + 1)), -delta);
}
void solve(int l, int r, int k, long long dt) {
  if (k * 2 >= l + r) {
    addseq(1, r - k, dt, dt);
    addseq(r - k + 1, k - l, dt * (r - k), 0);
    addseq(k - l + 1, r - l - 1, dt * (r - k - 1), -dt);
  } else {
    addseq(1, k - l, dt, dt);
    addseq(k - l + 1, r - k, dt * (k - l), 0);
    addseq(r - k + 1, r - l + 1, dt * (k - l - 1), -dt);
  }
}
void lemon() {
  int n;
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++) scanf("%d", &a[i].dt), a[i].where = i;
  sort(a + 1, a + n + 1, cmp);
  memset(s, 0, sizeof s);
  memset(d, 0, sizeof d);
  for (int i = (1); i <= (n); i++) {
    int k = a[i].where;
    dl.merge(k, k - 1);
    dr.merge(k, k + 1);
    int l = dl.find(k), r = dr.find(k);
    solve(l, r, k, a[i].dt);
  }
  final[0] = 0;
  long long delta = 0;
  for (int i = (1); i <= (n); i++) {
    final[i] = final[i - 1] + s[i] + delta;
    delta += d[i];
  }
  int m;
  scanf("%d", &m);
  for (int i = (1); i <= (m); i++) {
    int x;
    scanf("%d", &x);
    printf("%.20lf\n", double(final[x]) / (n - x + 1));
  }
}
int main() {
  lemon();
  return 0;
}
