#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const int INF = 0x3f3f3f3f;
const double esp = 1e-6;
const int maxn = 1e6 + 5;
const int MAXN = 50005;
const int MAX = 1 << 22;
const int MOD = 1e9 + 7;
const int mod = 1e9 + 7;
int dir[5][2] = {0, 1, 0, -1, 1, 0, -1, 0};
long long inv[maxn * 2];
inline void ex_gcd(long long a, long long b, long long &d, long long &x,
                   long long &y) {
  if (!b) {
    x = 1;
    y = 0;
    d = a;
  } else {
    ex_gcd(b, a % b, d, y, x);
    y -= x * (a / b);
  };
}
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline long long exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  long long ans = exgcd(b, a % b, x, y);
  long long temp = x;
  x = y;
  y = temp - a / b * y;
  return ans;
}
inline long long lcm(long long a, long long b) { return b / gcd(a, b) * a; }
inline long long qpow(long long x, long long n) {
  long long res = 1;
  for (; n; n >>= 1) {
    if (n & 1) res = (res * x) % MOD;
    x = (x * x) % MOD;
  }
  return res;
}
inline long long inv_exgcd(long long a, long long n) {
  long long d, x, y;
  ex_gcd(a, n, d, x, y);
  return d == 1 ? (x + n) % n : -1;
}
inline long long inv1(long long b) {
  return b == 1 ? 1 : (MOD - MOD / b) * inv1(MOD % b) % MOD;
}
inline long long inv2(long long b) { return qpow(b, MOD - 2); }
int b[maxn];
int vis[maxn];
struct math_tree {
  int n;
  int a[MAX], Max[MAX], Min[MAX];
  int tree[MAX];
  void init(int N) {
    n = N;
    for (int i = 0; i <= N; i++) Max[i] = -(Min[i] = INF);
  }
  void update(int k, int num) {
    a[k] = num;
    while (k <= n) {
      tree[k] += num;
      Min[k] = Max[k] = a[k];
      int lk = k & (-k);
      for (int i = 1; i < lk; i <<= 1) {
        Max[k] = max(Max[k], Max[k - i]);
        Min[k] = min(Min[k], Min[k - i]);
      }
      k += k & (-k);
    }
  }
  int Sum(int k) {
    int sum = 0;
    while (k) {
      sum += tree[k];
      k -= k & -k;
    }
    return sum;
  }
  int Get_Sum(int x, int y) { return Sum(y) - Sum(x - 1); }
  int Qmax(int x, int y) {
    int ans = -INF;
    while (y >= x) {
      ans = max(a[y], ans);
      y--;
      for (; y - (y & -y) >= x; y -= (y & -y)) ans = max(Max[y], ans);
    }
    return ans;
  }
  int Qmin(int x, int y) {
    int ans = INF;
    while (y >= x) {
      ans = min(a[y], ans);
      y--;
      for (; y - (y & -y) >= x; y -= (y & -y)) ans = min(ans, Min[y]);
    }
    return ans;
  }
} A;
int main() {
  int n;
  while (~scanf("%d", &n)) {
    int x;
    A.init(n);
    for (int i = 1; i <= n; i++) {
      scanf("%d", &x);
      if (i - x < 0)
        b[i] = 1;
      else
        b[i] = i - x;
      A.update(i, b[i]);
    }
    int ans = 1;
    for (int i = n - 1; i >= 1; i--) {
      if (i < A.Qmin(i + 1, n)) {
        ans++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
