#include <bits/stdc++.h>
using namespace std;
const int N = 255000;
const int SQRTN = 320;
const int LOGN = 20;
const long double PI = acos(-1);
int fp(int v, int p) {
  if (!p) return 1;
  int ret = fp(v, p >> 1);
  ret = (1ll * ret * ret) % 1000000007;
  if (p & 1) ret = (1ll * ret * v) % 1000000007;
  return ret;
}
struct Node {
  int val;
  bitset<301> fact;
  Node() { val = 1; }
  void mul(int val2, int x) { val = (1ll * val * fp(val2, x)) % 1000000007; }
  Node(int val) {
    this->val = val;
    for (int i = 2; i * i <= val; i++) {
      if (val % i) continue;
      fact[i] = 1;
      while (!(val % i)) val /= i;
    }
    if (val != 1) fact[val] = 1;
  }
  Node operator+(const Node& a) {
    Node ret = Node();
    ret.val = (1ll * val * a.val) % 1000000007;
    ret.fact = fact | a.fact;
    return ret;
  }
} seg[N * 5], lazy[N * 5], n1;
int n, q, a[N << 1], l, r, val, ans;
char s[1 << 5];
int invers[301];
int inv(int x) {
  if (invers[x]) return invers[x];
  return invers[x] = fp(x, 1000000007 - 2);
}
void build(int n, int s, int e) {
  if (s == e) {
    seg[n] = Node(a[s]);
    return;
  }
  int mid = s + e >> 1;
  build(n << 1, s, mid);
  build(n << 1 | 1, mid + 1, e);
  seg[n] = seg[n << 1] + seg[n << 1 | 1];
}
void push(int n, int s, int e) {
  seg[n].mul(lazy[n].val, e - s);
  seg[n] = seg[n] + lazy[n];
  if (s != e)
    lazy[n << 1] = lazy[n << 1] + lazy[n],
              lazy[n << 1 | 1] = lazy[n << 1 | 1] + lazy[n];
  lazy[n] = 1;
}
void update(int n, int s, int e) {
  if (lazy[n].val > 1) push(n, s, e);
  if (s > r || e < l) return;
  if (s <= l && e >= r) {
    lazy[n] = Node(val);
    push(n, s, e);
    return;
  }
  int mid = s + e >> 1;
  update(n << 1, s, mid);
  update(n << 1 | 1, mid + 1, e);
  seg[n] = seg[n << 1] + seg[n << 1 | 1];
}
Node get(int n, int s, int e) {
  if (lazy[n].val > 1) push(n, s, e);
  if (s > r || e < l) return n1;
  if (s >= l && e <= r) return seg[n];
  int mid = s + e >> 1;
  return get(n << 1, s, mid) + get(n << 1 | 1, mid + 1, e);
}
int main() {
  n1 = Node(1);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  build(1, 1, n);
  while (q--) {
    scanf(" %s %d %d", s, &l, &r);
    if (s[0] == 'M')
      scanf("%d", &val), update(1, 1, n);
    else {
      Node v = get(1, 1, n);
      ans = v.val;
      for (int i = 2; i < 301; i++)
        if (v.fact[i])
          ans = (1ll * ans * (i - 1)) % 1000000007,
          ans = (1ll * ans * inv(i)) % 1000000007;
      printf("%d\n", ans);
    }
  }
}
