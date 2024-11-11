#include <bits/stdc++.h>
using namespace std;
template <class T, class first>
inline bool getbit(T a, first i) {
  T t = 1;
  return ((a & (t << i)) > 0);
}
template <class T, class first>
inline T setbit(T a, first i) {
  T t = 1;
  return (a | (t << i));
}
template <class T, class first>
inline T resetbit(T a, first i) {
  T t = 1;
  return (a & (~(t << i)));
}
template <class T, class first>
inline T togglebit(T a, first i) {
  T t = 1;
  return (a ^ (t << i));
}
template <typename T>
T POW(T B, T P) {
  if (P == 0) return 1;
  if (P & 1)
    return B * POW(B, P - 1);
  else
    return (POW(B, P / 2) * POW(B, P / 2));
}
template <typename T>
T BIGMOD(T b, T p, T m) {
  if (p == 0)
    return 1;
  else if (!(p & 1))
    return (Bigmod(b, p / 2, m) * Bigmod(b, p / 2, m)) % m;
  else
    return ((b % m) * Bigmod(b, p - 1, m)) % m;
}
template <typename T>
T Bigmod(T base, T power, T mod) {
  T ret = 1;
  while (power) {
    if (power & 1) ret = (ret * base) % mod;
    base = (base * base) % mod;
    power >>= 1;
  }
  return ret;
}
template <typename T>
T ModInverse(T number, T mod) {
  return Bigmod(number, mod - 2, mod);
}
template <typename T>
T GCD(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
template <typename T>
T LCM(T a, T b) {
  if (a < 0) return lcm(-a, b);
  if (b < 0) return lcm(a, -b);
  return a * (b / gcd(a, b));
}
template <typename T>
T EUCLIDE(T a, T b, T &x, T &y) {
  if (a < 0) {
    T d = euclide(-a, b, x, y);
    x = -x;
    return d;
  }
  if (b < 0) {
    T d = euclide(a, -b, x, y);
    y = -y;
    return d;
  }
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  } else {
    T d = euclide(b, a % b, x, y);
    T t = x;
    x = y;
    y = t - (a / b) * y;
    return d;
  }
}
template <typename T>
T ABS(T a) {
  if (a < 0)
    return -a;
  else
    return a;
}
double DEG(double x) { return (180.0 * x) / ((2.0 * acos(0.0))); }
double RAD(double x) { return (x * (double)(2.0 * acos(0.0))) / (180.0); }
template <typename T>
T DIS(T x1, T y1, T x2, T y2) {
  return sqrt((double)((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}
template <typename T>
T ANGLE(T x1, T y1, T x2, T y2) {
  return atan(double(y1 - y2) / double(x1 - x2));
}
template <typename T>
long long isLeft(T a, T b, T c) {
  return (c.x - a.x) * (b.y - a.y) - (b.x - a.x) * (c.y - a.y);
}
void P_ARR(int *ar, int a, int b) {
  if (a > b) swap(a, b);
  if (a <= b) cout << ar[a];
  for (int i = a + 1; i <= b; i++) cout << " " << ar[i];
  cout << endl;
}
int src[200007];
int des[200007];
int tree[3][4 * 200007];
int cov[200007];
void build(int id, int idx, int s, int e) {
  if (s == e) {
    tree[id][idx] = src[s + 1] + des[s + 1];
    return;
  }
  int mid = (s + e) >> 1, l = (idx << 1), r = (l | 1);
  build(id, l, s, mid);
  build(id, r, mid + 1, e);
  tree[id][idx] = max(tree[id][l], tree[id][r]);
}
void update(int id, int idx, int s, int e, int pos, int val) {
  if (s == e) {
    tree[id][idx] = val;
    return;
  }
  int mid = (s + e) >> 1, l = (idx << 1), r = l | 1;
  if (pos <= mid)
    update(id, l, s, mid, pos, val);
  else
    update(id, r, mid + 1, e, pos, val);
  tree[id][idx] = max(tree[id][l], tree[id][r]);
}
int query(int id, int idx, int s, int e, int x, int y) {
  if (s == x && e == y) return tree[id][idx];
  int mid = (s + e) >> 1, l = (idx << 1), r = (l | 1);
  if (y <= mid)
    return query(id, l, s, mid, x, y);
  else if (x > mid)
    return query(id, r, mid + 1, e, x, y);
  else {
    int a = query(id, l, s, mid, x, mid);
    int b = query(id, r, mid + 1, e, mid + 1, y);
    return max(a, b);
  }
}
int n;
int mx;
int cap[200007];
int sum[200007];
int dp[200007];
int find(int s, int e) {
  int low = s;
  int high = e;
  int ret = e;
  int mid;
  while (low <= high) {
    mid = (low + high) / 2;
    int cov = query(1, 1, 0, n - 1, low - 1, mid - 1);
    if (cov + 1 >= e)
      ret = mid, high = mid - 1;
    else
      low = mid + 1;
  }
  return ret;
}
int main() {
  scanf("%d", &(n));
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &(src[i]), &(des[i]));
  }
  build(0, 1, 0, n - 1);
  for (int i = n; i >= 1; i--) {
    update(1, 1, 0, n - 1, i - 1, i - 1);
    int cover = upper_bound(src + 1, src + n + 1, src[i] + des[i]) - src - 1;
    int last = query(1, 1, 0, n - 1, i - 1, cover - 1) + 1;
    update(1, 1, 0, n - 1, i - 1, last - 1);
    if (last == n)
      dp[i] = 0;
    else
      dp[i] = src[last + 1] - (query(0, 1, 0, n - 1, i - 1, last - 1)) +
              dp[last + 1];
  }
  int(q);
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    int s = x;
    int e = find(x, y);
    cout << dp[s] - dp[e] << endl;
  }
  return 0;
}
