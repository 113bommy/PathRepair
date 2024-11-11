#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const long long ooo = 9223372036854775807ll;
const int _cnt = 1000 * 1000 + 7;
const int _p = 1000 * 1000 * 1000 + 7;
const int N = 100005;
const double PI = acos(-1.0);
const double eps = 1e-9;
int o(int x) { return x % _p; }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
void file_put() {
  string s = "/home/jslijin/jslijin/code/";
  freopen((s + "code.in").c_str(), "r", stdin);
  freopen((s + "code.out").c_str(), "w", stdout);
}
struct Seg {
  int x, abcde, y2, v;
} S[N];
int n, m, k, Y[N], last = 0, ans = 0, tag[N << 2], t[N << 2], x1, abcde, x2, y2,
                   cnt = 0, len;
bool cmp(const Seg &a, const Seg &b) { return a.x < b.x; }
int h(int x) { return lower_bound(Y + 1, Y + n + 1, x) - Y; }
void update(int k, int l, int r, int L, int R, int v) {
  if (L <= l && r <= R) {
    tag[k] += v;
    if (tag[k]) {
      t[k] = Y[l - 1] ^ Y[r];
      return;
    }
    if (l == r) {
      t[k] = 0;
      return;
    }
    t[k] = t[k << 1] ^ t[k << 1 | 1];
    return;
  }
  int mid = l + r >> 1;
  if (L <= mid) update(k << 1, l, mid, L, R, v);
  if (R > mid) update(k << 1 | 1, mid + 1, r, L, R, v);
  if (!tag[k]) t[k] = t[k << 1] ^ t[k << 1 | 1];
}
void work() {
  for (int i = (1); i <= (m); ++i) {
    int x = S[i].x, abcde = h(S[i].abcde), y2 = h(S[i].y2);
    ans ^= (x ^ last) & t[1], last = x;
    update(1, 1, n, abcde + 1, y2, S[i].v);
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &k), n = 0;
  for (int i = (1); i <= (m); ++i) {
    scanf("%d%d%d%d", &x1, &abcde, &x2, &y2);
    S[++cnt] = Seg{x1 - 1, abcde - 1, y2, 1};
    S[++cnt] = Seg{x2, abcde - 1, y2, -1};
    Y[++n] = abcde - 1, Y[++n] = y2;
  }
  sort(S + 1, S + cnt + 1, cmp);
  sort(Y + 1, Y + n + 1), n = unique(Y + 1, Y + n + 1) - Y - 1;
  work();
  for (len = 1; len <= k; len <<= 1)
    ;
  printf("%s\n", ans & (len - 1) ? "Hamed" : "Malek");
  return 0;
}
