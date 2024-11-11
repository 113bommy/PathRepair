#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const int N = 100050;
const int Maxn = 100000;
int wi[4], tot;
char ai[N], bi[N];
long long ans, jie[N], inv[N];
inline long long C(int x, int y) {
  if (x < y) return 0;
  if (x == y) return 1;
  return jie[x] * inv[y] % mod * inv[x - y] % mod;
}
bool check(char* f) {
  int len = strlen(f), cnt[4];
  for (int i = 0; i < 4; i++) cnt[i] = 0;
  for (int i = 1; i < len; i++) cnt[((f[i - 1] - '0') << 1) | (f[i] - '0')]++;
  for (int i = 0; i < 4; i++)
    if (cnt[i] != wi[i]) return 0;
  return 1;
}
inline long long get_sum(int len, int* f, int b) {
  for (int i = 0; i < 4; i++)
    if (f[i] < 0) return 0;
  if (b) {
    swap(f[0], f[3]);
    swap(f[1], f[2]);
  }
  if (f[1] == f[2]) {
    int xd = f[1] + 1, yd = f[1];
    int xs = f[1] + f[0] + 1, ys = f[1] - 1 + f[3] + 1;
    if (!xs || xs + ys != len + 1) return 0;
    return C(xs - 1, xd - 1) * C(ys - 1, yd - 1) % mod;
  } else if (f[1] == f[2] + 1) {
    int xd = f[1], yd = f[1];
    int xs = f[2] + f[0] + 1, ys = f[2] + f[3] + 1;
    if (!xs || xs + ys != len + 1) return 0;
    return C(xs - 1, xd - 1) * C(ys - 1, yd - 1) % mod;
  }
  return 0;
}
inline long long sol(char* f) {
  int len = strlen(f), cnt[4];
  long long ret = 0;
  for (int i = 0; i < 4; i++) cnt[i] = wi[i];
  if (tot + 1 > len) return 0;
  if (tot + 1 < len) return get_sum(tot, cnt, 1);
  for (int i = 0; i < len; i++) {
    if (f[i] == '1') {
      if (i) cnt[(f[i - 1] - '0') << 1]--;
      ret = (ret + get_sum(len - i - 1, cnt, 0)) % mod;
      if (i) cnt[(f[i - 1] - '0') << 1]++;
    }
    if (i) cnt[((f[i - 1] - '0') << 1) | (f[i] - '0')]--;
  }
  return ret;
}
inline long long KSM(long long a, long long p) {
  long long ret = 1;
  while (p) {
    if (p & 1) ret = ret * a % mod;
    a = a * a % mod;
    p >>= 1;
  }
  return ret;
}
int main() {
  jie[0] = 1;
  for (int i = 1; i <= Maxn; i++) jie[i] = jie[i - 1] * i % mod;
  inv[Maxn] = KSM(jie[Maxn], mod - 2);
  for (int i = Maxn - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
  scanf("%s%s", ai, bi);
  for (int a = 0; a < 4; a++) scanf("%d", &wi[a]), tot += wi[a];
  ans = check(bi);
  ans += sol(bi) - sol(ai);
  ans = (ans % mod + mod) % mod;
  cout << ans << endl;
  return 0;
}
