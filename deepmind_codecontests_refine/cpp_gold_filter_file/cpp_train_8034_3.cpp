#include <bits/stdc++.h>
const long long int MOD = 1e9 + 7;
using namespace std;
constexpr int mul(int a, int b) { return 1LL * a * b % MOD; }
template <typename... T>
constexpr int mul(int a, int b, T... t) {
  return mul(mul(a, b), t...);
}
template <class T>
inline T Min(const T &a, const T &b) {
  return a < b ? a : b;
}
template <class T>
inline T Max(const T &a, const T &b) {
  return a < b ? b : a;
}
inline void inc(int &x, int &v, int &mod) {
  x += v;
  if (x >= mod) x -= mod;
}
inline void dec(int &x, int &v, int &mod) {
  x -= v;
  if (x < 0) x += mod;
}
inline int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline long long int readl() {
  char ch = getchar();
  long long int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int T[200010 << 2][9], MIN[200010 << 2][9], minsum[200010 << 2][9];
int a[200010];
int res1, res2;
void pushup(int now, int k) {
  T[now][k] = T[now << 1][k] + T[now << 1 | 1][k];
  MIN[now][k] = Min(MIN[now << 1][k], MIN[now << 1 | 1][k]);
  minsum[now][k] = Min(minsum[now << 1][k], minsum[now << 1 | 1][k]);
  if (T[now << 1][k] != 0 && T[now << 1 | 1][k] != 0)
    minsum[now][k] =
        Min(minsum[now][k], MIN[now << 1][k] + MIN[now << 1 | 1][k]);
}
void build(int l, int r, int now, int k) {
  if (l == r) {
    int tmp = a[l];
    for (int i = 0; i < k; i++) {
      tmp /= 10;
    }
    minsum[now][k] = MIN[now][k] = 2e9;
    if (tmp % 10 != 0) {
      MIN[now][k] = a[l];
      T[now][k] = 1;
    } else
      T[now][k] = 0;
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, now << 1, k);
  build(mid + 1, r, now << 1 | 1, k);
  pushup(now, k);
}
int query(int L, int R, int l, int r, int now, int k) {
  if (L <= l && r <= R) {
    return T[now][k];
  }
  int mid = (l + r) >> 1;
  int ans = 0;
  if (L <= mid) ans += query(L, R, l, mid, now << 1, k);
  if (mid < R) ans += query(L, R, mid + 1, r, now << 1 | 1, k);
  return ans;
}
int query2(int L, int R, int l, int r, int now, int k) {
  if (L <= l && r <= R) {
    if (MIN[now][k] < res1) {
      res2 = res1;
      res1 = MIN[now][k];
    } else if (MIN[now][k] < res2) {
      res2 = MIN[now][k];
    }
    return minsum[now][k];
  }
  int mid = (l + r) >> 1;
  int ans1 = 2e9, ans2 = 2e9;
  if (L <= mid) ans1 = query2(L, R, l, mid, now << 1, k);
  if (mid < R) ans2 = query2(L, R, mid + 1, r, now << 1 | 1, k);
  return Min(ans1, ans2);
}
void update(int pos, int C, int l, int r, int now, int k) {
  if (l == r) {
    int tmp = C;
    for (int i = 0; i < k; i++) tmp /= 10;
    minsum[now][k] = MIN[now][k] = 2e9;
    if (tmp % 10 != 0) {
      MIN[now][k] = C;
      T[now][k] = 1;
    } else
      T[now][k] = 0;
    return;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid)
    update(pos, C, l, mid, now << 1, k);
  else
    update(pos, C, mid + 1, r, now << 1 | 1, k);
  pushup(now, k);
}
int main() {
  int n = read(), q = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 0; i < 9; i++) {
    build(1, n, 1, i);
  }
  while (q--) {
    int op = read(), a = read(), b = read();
    if (op == 1) {
      for (int i = 0; i < 9; i++) update(a, b, 1, n, 1, i);
    } else {
      bool tag = true;
      int sum = 2e9;
      for (int i = 0; i < 9; i++) {
        int cnt = query(a, b, 1, n, 1, i);
        if (cnt > 1) {
          res1 = res2 = 1e9;
          sum = Min(Min((res1 + res2), sum), query2(a, b, 1, n, 1, i));
          tag = false;
        }
      }
      if (tag) {
        printf("-1\n");
      } else {
        printf("%d\n", sum);
      }
    }
  }
  return 0;
}
