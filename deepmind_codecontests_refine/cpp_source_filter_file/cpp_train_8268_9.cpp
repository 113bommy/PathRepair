#include <bits/stdc++.h>
using namespace std;
template <class T>
T Bitcnt(T a) {
  int sum = 0;
  while (a) {
    if (a & 1) sum++;
    a /= 2;
  }
  return sum;
}
template <class T>
T Max3(T a, T b, T c) {
  return max(a, max(b, c));
}
template <class T>
T Lcm(T a, T b) {
  T tmp = __gcd(a, b);
  return (a / tmp) * b;
}
template <class T>
T Pow(T a, T b) {
  T ans = 1;
  T base = a;
  while (b) {
    if (b & 1) ans = (ans * base);
    base = (base * base);
    b /= 2;
  }
  return ans;
}
long long Bigmod(long long a, long long b) {
  long long res = 1;
  long long pw = a % 1000000007LL;
  while (b > 0) {
    if (b & 1) res = (res * pw) % 1000000007LL;
    pw = (pw * pw) % 1000000007LL;
    b /= 2;
  }
  return res;
}
int a_x[] = {1, -1, 0, 0};
int a_y[] = {0, 0, 1, -1};
long long X, Y;
void extend_euclid(long long a, long long b) {
  if (b == 0) {
    X = a;
    Y = 0;
    return;
  }
  extend_euclid(b, a % b);
  long long x, y;
  x = Y;
  y = X - (a / b) * Y;
  X = x;
  Y = y;
}
long long inverse_modulo(long long a, long long b) {
  extend_euclid(a, b);
  return (X + 1000000007LL) % 1000000007LL;
}
int arr[1005][1005];
int up[1005][1005], d[1005][1005], seq[1005], L[1005][1005], R[1005][1005];
int b[1005];
struct Ds {
  int f[1005];
  void init(int n) {
    for (int i = 0; i <= n + 1; i++) f[i] = i;
  }
  int Find(int x) { return f[x] = (f[x] == x) ? x : Find(f[x]); }
  void merge(int x, int y) { f[Find(x)] = Find(y); }
} lf, rf;
bool cmp(int x, int y) { return b[x] < b[y]; }
int calc(int n, int x) {
  for (int i = 1; i <= n; i++) seq[i] = i;
  sort(seq + 1, seq + n + 1, cmp);
  lf.init(n);
  rf.init(n);
  int ret = 0;
  for (int i = n; i > 0; i--) {
    int l = lf.Find(seq[i] - 1) + 1;
    int r = rf.Find(seq[i] + 1) - 1;
    if (l <= x && x <= r) ret = max(ret, b[seq[i]] * (r - l + 1));
    lf.merge(seq[i], seq[i] - 1);
    rf.merge(seq[i], seq[i] + 1);
  }
  return ret;
}
int main() {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &arr[i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (arr[i][j])
        up[i][j] = up[i - 1][j] + 1;
      else
        up[i][j] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (arr[i][j])
        L[i][j] = L[i][j - 1] + 1;
      else
        L[i][j] = 0;
  for (int i = n; i >= 1; i--)
    for (int j = m; j >= 1; j--)
      if (arr[i][j])
        d[i][j] = d[i + 1][j] + 1;
      else
        d[i][j] = 0;
  for (int i = n; i >= 1; i--)
    for (int j = m; j >= 1; j--)
      if (arr[i][j])
        R[i][j] = R[i][j + 1] + 1;
      else
        R[i][j] = 0;
  int type;
  int x, y;
  while (q--) {
    scanf("%d", &type);
    scanf("%d %d", &x, &y);
    if (type == 1) {
      arr[x][y] ^= 1;
      for (int i = x; i <= n; i++)
        if (arr[i][y])
          up[i][y] = up[i - 1][y] + 1;
        else
          up[i][y] = 0;
      for (int i = x; i >= 1; i--)
        if (arr[i][y])
          d[i][y] = d[i + 1][y];
        else
          d[i][y] = 0;
      for (int j = y; j <= m; j++)
        if (arr[x][j])
          L[x][j] = L[x][j - 1] + 1;
        else
          L[x][j] = 0;
      for (int j = y; j >= 1; j--)
        if (arr[x][j])
          R[x][j] = R[x][j + 1] + 1;
        else
          R[x][j] = 0;
    } else {
      int ans = 0;
      for (int i = 1; i <= m; i++) b[i] = up[x][i];
      ans = max(ans, calc(m, y));
      for (int i = 1; i <= m; i++) b[i] = d[x][i];
      ans = max(ans, calc(m, y));
      for (int i = 1; i <= n; i++) b[i] = L[i][y];
      ans = max(ans, calc(n, x));
      for (int i = 1; i <= n; i++) b[i] = R[i][y];
      ans = max(ans, calc(n, x));
      printf("%d\n", ans);
    }
  }
  return 0;
}
