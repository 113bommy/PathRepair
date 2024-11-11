#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigmod(T p, T e, T M) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
template <class T>
inline T lcm(T a, T b) {
  a = abs(a);
  b = abs(b);
  return (a / gcd(a, b)) * b;
}
template <class T, class X>
inline bool getbit(T a, X i) {
  T t = 1;
  return ((a & (t << i)) > 0);
}
template <class T, class X>
inline T setbit(T a, X i) {
  T t = 1;
  return (a | (t << i));
}
template <class T, class X>
inline T resetbit(T a, X i) {
  T t = 1;
  return (a & (~(t << i)));
}
inline long long getnum() {
  char c = getchar();
  long long num, sign = 1;
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') sign = -1;
  for (num = 0; c >= '0' && c <= '9';) {
    c -= '0';
    num = num * 10 + c;
    c = getchar();
  }
  return num * sign;
}
inline long long power(long long a, long long b) {
  long long multiply = 1;
  for (int i = (0); i < (b); i++) {
    multiply *= a;
  }
  return multiply;
}
long long a[100002], b[100002], c[2 * 100002], d[2 * 100002];
long long Tree[8 * 100002], Lazy[8 * 100002];
int n;
void build(int node, int l, int r) {
  Lazy[node] = 0;
  if (l == r) {
    Tree[node] = d[l];
    return;
  }
  int mid = (l + r) / 2;
  build(((node) << 1), l, mid);
  build(((node) << 1 | 1), mid + 1, r);
  Tree[node] = min(Tree[((node) << 1)], Tree[((node) << 1 | 1)]);
}
void pushdown(int node) {
  if (Lazy[node] == 0) return;
  Lazy[((node) << 1)] += Lazy[node];
  Lazy[((node) << 1 | 1)] += Lazy[node];
  Tree[((node) << 1)] += Lazy[node];
  Tree[((node) << 1 | 1)] += Lazy[node];
  Lazy[node] = 0;
}
void update(int node, int l, int r, int x, int y, long long val) {
  if (x > r || y < l) return;
  if (x <= l && r <= y) {
    Tree[node] += val;
    Lazy[node] += val;
    return;
  }
  if (l != r) pushdown(node);
  int mid = (l + r) / 2;
  update(((node) << 1), l, mid, x, y, val);
  update(((node) << 1 | 1), mid + 1, r, x, y, val);
  Tree[node] = min(Tree[((node) << 1)], Tree[((node) << 1 | 1)]);
}
long long query(int node, int l, int r, int x, int y) {
  if (x > r || y < l) return 1e18;
  if (x <= l && r <= y) {
    return Tree[node];
  }
  if (l != r) pushdown(node);
  int mid = (l + r) / 2;
  long long q1 = query(((node) << 1), l, mid, x, y);
  long long q2 = query(((node) << 1 | 1), mid + 1, r, x, y);
  return min(q1, q2);
}
set<int> ans;
int main() {
  int test, cases = 1;
  scanf("%d", &n);
  for (int i = (1); i < (n + 1); i++) scanf("%lld", &a[i]);
  for (int i = (1); i < (n + 1); i++) scanf("%lld", &b[i]);
  for (int i = (1); i < (2 * n + 1); i++) {
    if (i <= n)
      c[i] = a[i] - b[i];
    else
      c[i] = c[i - n];
  }
  for (int i = (1); i < (2 * n + 1); i++) d[i] = d[i - 1] + c[i];
  build(1, 1, 2 * n);
  for (int i = (1); i < (n + 1); i++) {
    long long out = query(1, 1, 2 * n, i, i + n - 1);
    if (out >= 0) ans.insert(i);
    update(1, 1, 2 * n, i, 2 * n, -c[i]);
  }
  for (int i = (1); i < (2 * n + 1); i++) {
    if (i <= n) {
      if (i > 1)
        c[i] = a[i] - b[i - 1];
      else
        c[i] = a[i] - b[n];
    } else
      c[i] = c[i - n];
  }
  reverse(c + 1, c + 1 + 2 * n);
  for (int i = (1); i < (2 * n + 1); i++) d[i] = d[i - 1] + c[i];
  build(1, 1, 2 * n);
  for (int i = (1); i < (n + 1); i++) {
    long long out = query(1, 1, 2 * n, i, i + n - 1);
    if (out >= 0) ans.insert(n - i + 1);
    update(1, 1, 2 * n, i, 2 * n, -c[i]);
  }
  cout << ans.size() << "\n";
  if (ans.size()) {
    for (auto it : ans) cout << it << " ";
    cout << "\n";
  }
  return 0;
}
