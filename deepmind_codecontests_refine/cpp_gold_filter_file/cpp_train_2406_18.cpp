#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, base = 37, mod = 998244353;
char lx[N];
int a[N], ha[N], len;
int pw[N];
int mul(int x, int y) { return 1ll * x * y % mod; }
int add(int x, int y) { return (x += y) >= mod ? x - mod : x; }
void Add(int &x, int y) { x = add(x, y); }
int sub(int x, int y) { return (x -= y) < 0 ? x + mod : x; }
void Sub(int &x, int y) { x = sub(x, y); }
int gao(int l, int r) { return sub(ha[r], mul(ha[l - 1], pw[r - l + 1])); }
struct data {
  int h[N], a[N], len;
  bool Gao(int l, int len) { return h[len] == gao(l, l + len - 1); }
  int check(int nl, int nr) {
    int l = 1, r = nr - nl + 1, ans = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (Gao(nl, mid))
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    return ans;
  }
} L, R;
void init() {
  pw[0] = 1;
  for (int i = 1; i < N; ++i) pw[i] = mul(pw[i - 1], base);
  scanf("%s", lx + 1);
  len = strlen(lx + 1);
  for (int i = 1; i <= len; ++i) {
    a[i] = lx[i] - '0';
    ha[i] = add(mul(ha[i - 1], base), a[i]);
  }
  scanf("%s", lx + 1);
  L.len = strlen(lx + 1);
  for (int i = 1; i <= L.len; ++i) L.a[i] = lx[i] - '0';
  scanf("%s", lx + 1);
  R.len = strlen(lx + 1);
  for (int i = 1; i <= R.len; ++i) R.a[i] = lx[i] - '0';
  for (int i = 1; i <= L.len; ++i) L.h[i] = add(mul(L.h[i - 1], base), L.a[i]);
  for (int i = 1; i <= R.len; ++i) R.h[i] = add(mul(R.h[i - 1], base), R.a[i]);
}
bool judge(int l, int r) {
  if (l > r) return false;
  int p1 = 1, p2 = 1;
  if (r - l + 1 == L.len) {
    int s = L.check(l, r) + 1;
    if (s <= L.len && a[s + l - 1] < L.a[s]) p1 = 0;
  } else if (r - l + 1 < L.len)
    p1 = 0;
  if (r - l + 1 == R.len) {
    int s = R.check(l, r) + 1;
    if (s <= R.len && a[s + l - 1] > R.a[s]) p2 = 0;
  } else if (r - l + 1 > R.len)
    p2 = 0;
  return p1 && p2;
}
int f[N];
int main() {
  init();
  f[0] = 1;
  int sum = 0;
  for (int i = 1; i <= len; ++i) {
    int l = i - R.len, r = i - L.len;
    if (i >= L.len) {
      if (judge(i - L.len + 1, i)) {
        Add(sum, f[i - L.len]);
      }
    }
    if (i > L.len) {
      if (!judge(i - L.len, i - 1) && judge(i - L.len, i)) {
        Add(sum, f[i - L.len - 1]);
      }
    }
    if (i > R.len) {
      if (judge(i - R.len, i - 1)) {
        Sub(sum, f[i - R.len - 1]);
      }
    }
    if (i >= R.len) {
      int k = i - R.len;
      if (judge(k + 1, k + R.len - 1) && !judge(k + 1, k + R.len)) {
        Sub(sum, f[k]);
      }
    }
    f[i] = sum;
    if (!a[i]) {
      if (judge(i, i)) {
        Sub(sum, f[i - 1]);
      }
      f[i - 1] = 0;
    }
  }
  printf("%d\n", f[len]);
  return 0;
}
