#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
int ra = 1, rb = 1;
int sb[100005], db[100005];
pair<int, int> sa[100005];
int search(int x) {
  int l = 0, r = n + 1;
  while (r - l > 1) {
    int md = (l + r) >> 1;
    if (1LL * x * a < 1LL * b * sa[md].first)
      r = md;
    else
      l = md;
  }
  return r;
}
double dis(double x, double y) { return sqrt(x * x + y * y); }
void t(int ta, int tb) {
  if (ta <= 0 || ta > n) return;
  double tt = dis(a, sa[ta].first) + dis(b - a, sb[tb] - sa[ta].first) + db[tb];
  double rr = dis(a, sa[ra].first) + dis(b - a, sb[rb] - sa[ra].first) + db[rb];
  if (tt < rr) {
    ra = ta;
    rb = tb;
  }
  return;
}
int main() {
  scanf("%d %d", &n, &m);
  scanf("%d %d", &a, &b);
  for (int i = (1); i <= (n); i++) {
    scanf("%d", &sa[i].first);
    sa[i].second = i;
  }
  sort(sa + 1, sa + n + 1);
  for (int i = (1); i <= (m); i++) scanf("%d", &sb[i]);
  for (int i = (1); i <= (m); i++) {
    scanf("%d", &db[i]);
    int p = search(db[i]);
    for (int j = (-1); j <= (1); j++) t(p + j, i);
  }
  printf("%d %d\n", sa[ra].second, rb);
  return 0;
}
