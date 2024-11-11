#include <bits/stdc++.h>
using namespace std;
template <typename T>
void maxtt(T& t1, T t2) {
  t1 = max(t1, t2);
}
template <typename T>
void mintt(T& t1, T t2) {
  t1 = min(t1, t2);
}
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "URDL";
const long long MOD2 = (long long)1000000007 * (long long)1000000007;
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int& x, int y, int mod = 1000000007) {
  assert(y >= 0);
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et(int x = -1) {
  printf("%d\n", x);
  exit(0);
}
long long fastPow(long long x, long long y, int mod = 1000000007) {
  long long ans = 1;
  while (y > 0) {
    if (y & 1) ans = (x * ans) % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
long long gcd1(long long x, long long y) { return y ? gcd1(y, x % y) : x; }
char a[100035], b[100035];
int c[100035], ct[100035];
const int MN = 100035 * 10;
bitset<MN> ps;
void cal(int d) {
  for (int(i) = 0; (i) < (int)(d); (i)++) ct[i] = 0;
  for (int(i) = 1; (i) <= (int)(n); (i)++) ct[(i - 1) % d] += c[i];
  mt19937 ttrand((int)time(0));
  for (int z = m / d * d; z < MN; z += d) {
    int P = z + 1;
    if (P < m) continue;
    if (ps[P]) continue;
    for (int(zzz) = 0; (zzz) < (int)(100); (zzz)++) {
      int r0 = uniform_int_distribution<int>(2, P - 2)(ttrand);
      if (fastPow(r0, z / d, P) != 1) {
        r0 = fastPow(r0, z / d, P);
        int r = r0;
        for (int(i) = 1; (i) <= (int)(d); (i)++) {
          int ans = 0, x = 1;
          for (int(j) = 0; (j) < (int)(d); (j)++) {
            ans += (long long)ct[j] * x % P;
            ans %= P;
            x = (long long)x * r % P;
          }
          if (ans == 0) {
            printf("%d %d\n", P, r);
            exit(0);
          }
          r = (long long)r * r0 % P;
        }
        break;
      }
    }
  }
}
void fmain(int tid) {
  scanf("%d%d", &n, &m);
  scanf("%s%s", a + 1, b + 1);
  for (int(i) = 1; (i) <= (int)(n); (i)++) c[i] = a[i] - b[i];
  for (int i = 2; i < MN; i++)
    if (!ps[i]) {
      for (int j = i + i; j < MN; j += i) ps[j] = 1;
    }
  for (int i = 3; i < MN; i++)
    if (!ps[i]) cal(i);
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
