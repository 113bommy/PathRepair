#include <bits/stdc++.h>
using namespace std;
const int inf = 2147483647;
const int mod = 1e9 + 7;
const int N = 200001;
int _max(int x, int y) { return x > y ? x : y; }
int _min(int x, int y) { return x < y ? x : y; }
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  return x * f;
}
void put(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) put(x / 10);
  putchar(x % 10 + '0');
}
int L[N], R[N];
int p[N], q[N];
int add(int x, int y) {
  x += y;
  return x >= mod ? x - mod : x;
}
int dec(int x, int y) {
  x -= y;
  return x < 0 ? x + mod : x;
}
int pow_mod(int a, int k) {
  int ans = 1;
  while (k) {
    if (k & 1) ans = (long long)ans * a % mod;
    a = (long long)a * a % mod, k /= 2;
  }
  return ans;
}
int gao(int i) {
  int s = (long long)_max(0, _min(R[i], _min(R[i - 1], R[i + 1])) -
                                 _max(L[i], _min(L[i - 1], L[i + 1]))) *
          pow_mod(R[i] - L[i], mod - 2) % mod *
          pow_mod(R[i - 1] - L[i - 1], mod - 2) % mod *
          pow_mod(R[i + 1] - L[i + 1], mod - 2) % mod;
  return add(dec(mod + 1 - p[i], p[i + 1]), s);
}
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) L[i] = read();
  for (int i = 1; i <= n; i++) R[i] = read() + 1;
  for (int i = 2; i <= n; i++) {
    p[i] = (long long)_max(0, _min(R[i - 1], R[i]) - _max(L[i - 1], L[i])) *
           pow_mod(R[i - 1] - L[i - 1], mod - 2) % mod *
           pow_mod(R[i] - L[i], mod - 2) % mod;
    q[i] = dec(1, p[i]);
  }
  q[1] = 1;
  int sum = 0, ans = 0;
  for (int i = 1; i <= n; i++) sum = add(sum, q[i]);
  for (int i = 1; i <= n; i++) {
    ans = add(ans, q[i]);
    ans = add(ans, (long long)dec(dec(dec(sum, q[i]), q[i - 1]), q[i + 1]) *
                       q[i] % mod);
  }
  ans = add(ans, 2LL * p[2] % mod);
  for (int i = 2; i < n; i++) ans = add(ans, 2LL * gao(i) % mod);
  put(ans), puts("");
  return 0;
}
