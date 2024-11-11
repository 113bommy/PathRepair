#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn = 2e5 + 10;
inline int lowbit(int x) { return x & (-x); }
struct point {
  int x, v;
} p[maxn];
int v[maxn];
long long c1[maxn], c2[maxn];
bool comp(point a, point b) { return a.x < b.x; }
long long getnum(long long c[], int i) {
  long long res = 0LL;
  while (i > 0) {
    res += c[i];
    i -= lowbit(i);
  }
  return res;
}
void update(int i, int value) {
  while (i < n) {
    c1[i]++;
    c2[i] += value;
    i += lowbit(i);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i].x);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i].v);
    v[i] = p[i].v;
  }
  sort(p + 1, p + n + 1, comp);
  sort(v + 1, v + n + 1);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    int pos = lower_bound(v + 1, v + 1 + n, p[i].v) - v;
    ans += getnum(c1, pos) * p[i].x - getnum(c2, pos);
    update(pos, p[i].x);
  }
  printf("%lld", ans);
  return 0;
}
