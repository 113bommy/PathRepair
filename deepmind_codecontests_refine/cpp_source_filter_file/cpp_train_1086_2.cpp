#include <bits/stdc++.h>
using namespace std;
template <class T>
T sqr(T x) {
  return x * x;
}
int f[110000], a[110000];
long long s[110000];
struct sb {
  int x, y, z;
};
sb b[110000];
int n, m;
long long ans;
bool cmp(sb a, sb b) { return a.z > b.z; }
int find(int x) {
  if (f[x] == x) return x;
  f[x] = find(f[x]);
  return f[x];
}
int main() {
  int i, x, y;
  sb t;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%d", a + i);
  for (i = 1; i <= n; i++) f[i] = i, s[i] = 1;
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &t.x, &t.y);
    t.z = min(a[t.x], a[t.y]);
    b[i] = t;
  }
  sort(b + 1, b + m + 1, cmp);
  for (i = 1; i <= n; i++) {
    x = find(b[i].x);
    y = find(b[i].y);
    if (x != y) {
      ans += s[x] * s[y] * b[i].z;
      f[x] = y;
      s[y] += s[x];
    }
  }
  printf("%lf\n", 1.0 * ans / n / (n - 1) * 2);
}
