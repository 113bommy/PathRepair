#include <bits/stdc++.h>
const bool debug = false;
using namespace std;
long long powmod(long long a, long long b, long long MOD) {
  long long res = 1;
  a %= MOD;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
  }
  return res;
}
void buginfo(const char* f, ...) {
  if (!debug) return;
  va_list al;
  va_start(al, f);
  vprintf(f, al);
  va_end(al);
}
const int maxn = 1e5 + 10;
int n, m;
struct Node {
  double x, y;
} a[maxn], b[maxn];
double cross(Node a, Node b, Node c) {
  return (b.x - a.x) * (c.y - a.y) * 1.0 - (b.y - a.y) * (c.x - a.x) * 1.0;
}
bool check(Node x) {
  if (cross(a[0], a[n - 1], x) <= 0) return false;
  if (cross(a[0], a[1], x) >= 0) return false;
  int l = 0, r = n;
  while (l < r) {
    int mid = (l + r) / 2;
    if (cross(a[0], a[mid], x) <= 0)
      l = mid + 1;
    else
      r = mid;
  }
  if (cross(x, a[l], a[l - 1]) <= 0) return false;
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d%d", &a[i].x, &a[i].y);
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) scanf("%d%d", &b[i].x, &b[i].y);
  for (int i = 0; i < m; ++i)
    if (!check(b[i])) return 0 * printf("NO\n");
  printf("YES\n");
  return 0;
}
