#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  char ch = getchar();
  bool f = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
  x = f ? -x : x;
}
const int N = 1e6 + 8, P = 1e9 + 7;
int n, k;
int y[N];
int pre[N], suf[N];
int inv[N], minv[N];
int qw(int a, int b) {
  int ans = 1;
  for (; b; a = (long long)a * a % P, b >>= 1)
    (b & 1) && (ans = (long long)ans * a % P);
  return ans;
}
int add(int x, int y) {
  x += y;
  return x >= P ? x - P : x;
}
int sub(int x, int y) {
  x -= y;
  return x < 0 ? x + P : x;
}
signed main() {
  read(n);
  read(k);
  if (!k) {
    cout << n;
    return 0;
  }
  for (int i = (1), _ = (k + 2); i <= _; ++i) y[i] = add(y[i - 1], qw(i, k));
  if (n <= k + 2) {
    cout << y[n];
    return 0;
  }
  pre[1] = 1;
  for (int i = (2), _ = (k + 2); i <= _; ++i)
    pre[i] = (long long)pre[i - 1] * sub(n, i - 1) % P;
  suf[k + 2] = 1;
  for (int i = (k + 1), _ = (1); i >= _; --i)
    suf[i] = (long long)suf[i + 1] * sub(n, i + 1) % P;
  int mul = 1;
  for (int i = (1), _ = (k + 2); i <= _; ++i) mul = (long long)mul * i % P;
  inv[k + 2] = qw(mul, P - 2);
  for (int i = (k + 1), _ = (0); i >= _; --i)
    inv[i] = (long long)inv[i + 1] * (i + 1) % P;
  mul = 1;
  for (int i = (1), _ = (k + 2); i <= _; ++i)
    mul = (long long)mul * (P - i) % P;
  minv[k + 2] = qw(mul, P - 2);
  for (int i = (k + 1), _ = (0); i >= _; --i)
    minv[i] = (long long)minv[i + 1] * (P - i - 1) % P;
  int ans = 0;
  for (int i = (1), _ = (k + 2); i <= _; ++i)
    ans = add(ans, (long long)y[i] * pre[i] % P * suf[i] % P * minv[k + 2 - i] %
                       P * inv[i - 1] % P);
  cout << ans << endl;
  return 0;
}
