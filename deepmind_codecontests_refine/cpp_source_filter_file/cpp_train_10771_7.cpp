#include <bits/stdc++.h>
using namespace std;
const double PI = acos(0) * 2;
const double EPS = 1e-8;
const long long MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int oo = 1e9;
const double foo = 1e30;
template <class T>
int getbit(T s, int i) {
  return (s >> i) & 1;
}
template <class T>
T onbit(T s, int i) {
  return s | (T(1) << i);
}
template <class T>
T offbit(T s, int i) {
  return s & (~(T(1) << i));
}
template <class T>
int cntbit(T s) {
  return __builtin_popcounll(s);
}
template <class T>
T sqr(T x) {
  return x * x;
}
inline void addmod(int& a, int val, int p = MOD) {
  if ((a = (a + val)) >= p) a -= p;
}
inline void submod(int& a, int val, int p = MOD) {
  if ((a = (a - val)) < 0) a += p;
}
inline int mult(int a, int b, int p = MOD) { return (long long)a * b % p; }
int T[MAXN + 5], n, a[MAXN], b[MAXN], pa[MAXN], push_back[MAXN], pc[MAXN],
    ans[MAXN];
void update(int u, int val) {
  if (u == 0) return;
  while (u < MAXN) {
    T[u] += val;
    u += (u & -u);
  }
}
int getres(int u) {
  int res = 0;
  while (u) {
    res += T[u];
    u -= (u & -u);
  }
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]), a[i]++;
  for (int i = 0; i < n; i++) scanf("%d", &b[i]), b[i]++;
  for (int i = n - 1; i >= 0; i--) {
    int cur = getres(a[i]);
    pa[i] = cur;
    update(a[i] + 1, 1);
  }
  memset(T, 0, sizeof(T));
  for (int i = n - 1; i >= 0; i--) {
    int cur = getres(b[i]);
    push_back[i] = cur;
    update(b[i] + 1, 1);
  }
  int nho = 0;
  int now = 1;
  for (int i = n - 1; i >= 0; i--) {
    int S = pa[i] + push_back[i] + nho;
    if (S >= now)
      nho = S / now;
    else
      nho = 0;
    S %= now;
    pc[i] = S;
    now++;
  }
  memset(T, 0, sizeof(T));
  for (int i = 1; i <= n; i++) update(i, 1), pc[i - 1]++;
  for (int i = 0; i < n; i++) {
    int l = 1, r = n, find = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      int cur = getres(mid);
      if (cur >= pc[i]) {
        find = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    ans[i] = find - 1;
    update(find, -1);
  }
  for (int i = 0; i < n; i++) printf("%d ", ans[i]);
  return 0;
}
