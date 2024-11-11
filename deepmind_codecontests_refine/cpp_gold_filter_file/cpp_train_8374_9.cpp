#include <bits/stdc++.h>
using namespace std;
int n, k, i, f[100005 << 2];
long long ans;
struct node {
  int x, y, z;
} a[100005];
int find(int x) {
  if (f[x] != x) f[x] = find(f[x]);
  return f[x];
}
inline bool cmp(node aa, node bb) {
  return aa.y - aa.x == bb.y - bb.x ? aa.x < bb.x : aa.y - aa.x > bb.y - bb.x;
}
inline long long ksm(long long x, long long y) {
  long long ret = 1;
  for (; y; y >>= 1, x = x * x % 1000000007)
    if (y & 1) ret = ret * x % 1000000007;
  return ret;
}
void merge(int x, int y) { f[find(x)] = find(y); }
void add(int x, int y, int z) {
  if (z) {
    if (find(x) == find(y) || find(x + n) == find(y + n)) cout << 0, exit(0);
    if (find(x) != find(y + n))
      merge(x, y + n), merge(y, x + n), (ans *= 500000004) %= 1000000007;
  } else {
    if (find(x) == find(y + n) || find(x + n) == find(y)) cout << 0, exit(0);
    if (find(x) != find(y))
      merge(x, y), merge(x + n, y + n), (ans *= 500000004) %= 1000000007;
  }
}
int X, Y, las;
char s[10];
int main() {
  scanf("%d%d", &n, &k);
  if (n == 1) {
    if (k == 0) cout << 2;
    cout << 1;
    return 0;
  }
  ans = ksm(2, n);
  for (i = 1; i <= k; ++i) {
    scanf("%d%d%s", &X, &Y, s), a[i].z = s[0] == 'o';
    if (X + Y > n + 1) X = n + 1 - X, Y = n + 1 - Y, swap(X, Y);
    if (X > Y) swap(X, Y);
    a[i].x = X, a[i].y = Y;
  }
  sort(a + 1, a + k + 1, cmp);
  for (i = 2; i <= k; ++i) {
    if (a[i].x == a[i - 1].x && a[i].y == a[i - 1].y && a[i].z != a[i - 1].z) {
      return cout << 0, 0;
    }
  }
  for (i = 0; i <= (n + 1 >> 1); ++i) f[i] = i, f[i + n] = i + n;
  a[k + 1].y = -1e9;
  for (las = i = 1; i <= k; ++i) {
    if (((a[i].y - a[i].x) & 1) &&
        (a[i].y - a[i].x != a[i + 1].y - a[i + 1].x)) {
      while (((a[las].y - a[las].x) & 1) == 0) {
        ++las;
      }
      X = (a[las].x + a[las].y) >> 1;
      add((a[las].y - a[las].x) >> 1, X, a[las].z);
      while (las < i) {
        ++las;
        Y = (a[las].x + a[las].y) >> 1;
        add(X, Y, a[las].z ^ a[las - 1].z);
        X = Y;
      }
      ++las;
    }
  }
  for (i = 0; i <= (n + 1 >> 1); ++i)
    if (find(i) == find(i + n)) return cout << 0, 0;
  for (i = 0; i <= (n >> 1); ++i) f[i] = i, f[i + n] = i + n;
  a[k + 1].x = 1;
  for (las = i = 1; i <= k; ++i) {
    if (((a[i].y - a[i].x) & 1) == 0 &&
        (a[i].y - a[i].x != a[i + 1].y - a[i + 1].x)) {
      while (((a[las].y - a[las].x) & 1)) {
        ++las;
      }
      X = (a[las].x + a[las].y) >> 1;
      add((a[las].y - a[las].x) >> 1, X, a[las].z);
      while (las < i) {
        ++las;
        Y = (a[las].x + a[las].y) >> 1;
        add(X, Y, a[las - 1].z ^ a[las].z);
        X = Y;
      }
      ++las;
    }
  }
  for (i = 1; i <= (n >> 1); ++i)
    if (find(i) == find(i + n)) return cout << 0, 0;
  cout << ans;
}
