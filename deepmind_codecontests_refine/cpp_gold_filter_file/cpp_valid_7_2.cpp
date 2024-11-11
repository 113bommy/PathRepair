#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int maxm = 1e6 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-10;
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
mt19937 rnd(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
int n;
long long a[maxn], d[maxn];
long long gcd(long long a, long long b) {
  if (!b)
    return a;
  else
    return gcd(b, a % b);
}
struct node {
  long long gcd;
} tree[maxn << 2];
void push_up(int rt) {
  tree[rt].gcd = abs(gcd(tree[rt << 1].gcd, tree[rt << 1 | 1].gcd));
}
void build(int rt, int l, int r) {
  if (l == r) {
    tree[rt].gcd = d[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(rt << 1, l, mid);
  build(rt << 1 | 1, mid + 1, r);
  push_up(rt);
}
void update(int rt, long long c, int l, int r, int pow) {
  if (l == r) {
    tree[rt].gcd += c;
    return;
  }
  int mid = (l + r) >> 1;
  if (pow <= mid)
    update(rt << 1, c, l, mid, pow);
  else
    update(rt << 1 | 1, c, mid + 1, r, pow);
  push_up(rt);
}
long long query(int rt, int l, int r, int L, int R) {
  if (L <= l && r <= R) return tree[rt].gcd;
  int mid = (l + r) >> 1;
  long long g = 0;
  if (L <= mid) g = abs(gcd(g, query(rt << 1, l, mid, L, R)));
  if (R > mid) g = abs(gcd(g, query(rt << 1 | 1, mid + 1, r, L, R)));
  return g;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n == 1)
      cout << 1 << endl;
    else {
      for (int i = 2; i <= n; i++) d[i - 1] = abs(a[i] - a[i - 1]);
      build(1, 1, n - 1);
      int miao = 0;
      for (int i = 1; i <= n - 1; i++) {
        int l = i, r = n - 1;
        int ans = 0;
        while (l <= r) {
          int mid = (l + r) >> 1;
          if (query(1, 1, n - 1, i, mid) > 1) {
            l = mid + 1;
            ans = mid;
          } else
            r = mid - 1;
        }
        miao = max(miao, ans - i + 2);
      }
      cout << miao << endl;
    }
  }
  return ~~(0 - 0);
}
