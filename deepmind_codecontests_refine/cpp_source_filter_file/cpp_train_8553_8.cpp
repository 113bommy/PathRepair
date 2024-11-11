#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int _inf = 0xc0c0c0c0;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long _INF = 0xc0c0c0c0c0c0c0c0;
const long long mod = (int)1e9 + 7;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long ksm(long long a, long long b, long long mod) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}
long long inv2(long long a, long long mod) { return ksm(a, mod - 2, mod); }
void exgcd(long long a, long long b, long long &x, long long &y, long long &d) {
  if (!b) {
    d = a;
    x = 1;
    y = 0;
  } else {
    exgcd(b, a % b, y, x, d);
    y -= x * (a / b);
  }
}
const int MAX_N = 200025;
const int N = 200001;
namespace sgt {
int s[MAX_N << 2];
void update(int rt, int l, int r, int x) {
  if (l == r) {
    s[rt] = 1;
    return;
  }
  if (x <= ((l + r) >> 1))
    update(rt << 1, l, ((l + r) >> 1), x);
  else
    update(rt << 1 | 1, ((l + r) >> 1) + 1, r, x);
  s[rt] = s[rt << 1] + s[rt << 1 | 1];
}
int query(int rt, int l, int r, int x, int y) {
  if (x > y) return 0;
  if (x <= l && r <= y) {
    return s[rt];
  }
  if (x > ((l + r) >> 1))
    return query(rt << 1 | 1, ((l + r) >> 1) + 1, r, x, y);
  else if (y <= ((l + r) >> 1))
    return query(rt << 1, l, ((l + r) >> 1), x, y);
  else
    return query(rt << 1, l, ((l + r) >> 1), x, y) +
           query(rt << 1 | 1, ((l + r) >> 1) + 1, r, x, y);
}
}  // namespace sgt
struct node {
  int x, y;
  bool operator<(const node other) const & {
    if (y == other.y) return x < other.x;
    return y > other.y;
  }
} arr[MAX_N];
int b[MAX_N], c[MAX_N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d%d", &arr[i].x, &arr[i].y), b[i] = arr[i].x, c[i] = arr[i].y;
  sort(b + 1, b + 1 + n);
  sort(c + 1, c + 1 + n);
  int sz = unique(b + 1, b + 1 + n) - b - 1;
  int sz_ = unique(c + 1, c + 1 + n) - c - 1;
  for (int i = 1; i <= n; ++i)
    arr[i].x = lower_bound(b + 1, b + 1 + sz, arr[i].x) - b;
  for (int i = 1; i <= n; ++i)
    arr[i].y = lower_bound(c + 1, c + 1 + sz, arr[i].y) - c;
  sort(arr + 1, arr + 1 + n);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (i != n && arr[i].y == arr[i + 1].y) {
      sgt::update(1, 1, N, arr[i].x);
      int R = i + 1;
      while (R <= n && arr[R].y == arr[i].y) {
        sgt::update(1, 1, N, arr[R].x);
        R++;
      }
      int l = sgt::query(1, 1, N, 1, arr[i].x - 1);
      int r = sgt::query(1, 1, N, arr[i].x + 1, N);
      ans += 1ll * (l + 1) * (r + 1);
      for (int j = i + 1; j < R; ++j) {
        int l = sgt::query(1, 1, N, arr[j - 1].x + 1, arr[j].x - 1);
        int r = sgt::query(1, 1, N, arr[j].x + 1, N);
        ans += 1ll * (l + 1) * (r + 1);
      }
      i = R - 1;
    } else {
      int l = sgt::query(1, 1, N, 1, arr[i].x - 1);
      int r = sgt::query(1, 1, N, arr[i].x + 1, N);
      ans += 1ll * (l + 1) * (r + 1);
      sgt::update(1, 1, N, arr[i].x);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
