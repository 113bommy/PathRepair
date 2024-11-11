#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void rread(T& num) {
  num = 0;
  T f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') num = num * 10 + ch - '0', ch = getchar();
  num *= f;
}
const long long inf = 1e16;
const int maxn = 2e5 + 10, mod = 1e9 + 7;
const long double PI = acos(-1.0);
long long gcd(long long a, long long b) { return (a ? gcd(b % a, a) : b); }
void exgcd(long long a, long long b, long long& d, long long& x, long long& y) {
  if (!b) {
    d = a;
    x = 1;
    y = 0;
  } else {
    exgcd(b, a % b, d, y, x);
    y -= x * (a / b);
  }
}
long long power(long long a, long long n) {
  long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
    }
    n >>= 1;
    a *= a;
  }
  return p;
}
long long power(long long a, long long n, long long mod) {
  long long p = 1;
  while (n > 0) {
    if (n % 2) {
      p = p * a;
      p %= mod;
    }
    n >>= 1;
    a *= a;
    a %= mod;
  }
  return p % mod;
}
int n, m;
int a[maxn], b[maxn], c[maxn];
struct node {
  int r, l;
  int sum;
} se[maxn << 2];
void build(int tr, int l, int s) {
  se[tr].r = s;
  se[tr].l = l;
  int mid = (s + l) / 2;
  if (s == l) {
    se[tr].sum = 1;
    return;
  }
  build(tr * 2, l, mid);
  build(tr * 2 + 1, mid + 1, s);
  se[tr].sum = se[tr << 1].sum + se[tr << 1 | 1].sum;
  return;
}
void inse(int tr, int i) {
  if (se[tr].l == se[tr].r) {
    se[tr].sum = 0;
    return;
  }
  int mid = (se[tr].r + se[tr].l) / 2;
  if (i <= mid)
    inse(tr * 2, i);
  else
    inse(tr * 2 + 1, i);
  se[tr].sum = se[tr << 1].sum + se[tr << 1 | 1].sum;
  return;
}
int querysum(int tr, int i, int j) {
  if (se[tr].l >= i && se[tr].r <= j) {
    return se[tr].sum;
  }
  int mid = (se[tr].r + se[tr].l) >> 1;
  int s1 = 0, s2 = 0;
  if (j <= mid)
    return querysum(tr << 1, i, j);
  else if (i > mid)
    return querysum(tr << 1 | 1, i, j);
  else
    return querysum(tr << 1, i, j) + querysum(tr << 1 | 1, i, j);
}
int queryk(int tr, int i) {
  if (se[tr].l == se[tr].r) {
    se[tr].sum = 0;
    return se[tr].l;
  }
  int mid = se[tr].l + se[tr].r >> 1;
  int s = 0;
  if (se[tr << 1].sum >= i)
    s = queryk(tr << 1, i);
  else
    s = queryk(tr << 1 | 1, i - se[tr].sum);
  se[tr].sum = se[tr << 1].sum + se[tr << 1 | 1].sum;
  return s;
}
int main() {
  while (cin >> n) {
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i]++;
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]), b[i]++;
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
      int d = querysum(1, 1, a[i]);
      d--;
      inse(1, a[i]);
      a[i] = d;
    }
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
      int d = querysum(1, 1, b[i]);
      d--;
      inse(1, b[i]);
      b[i] = d;
    }
    int f = 0;
    for (int i = n; i >= 1; i--) {
      c[i] = a[i] + b[i] + f;
      if (c[i] > n - i)
        f = 1, c[i] -= n - i + 1;
      else
        f = 0;
    }
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
      int d = queryk(1, c[i] + 1);
      cout << d - 1 << " ";
    }
    cout << endl;
  }
  return 0;
}
