#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const double pi = acos(-1.0), eps = 1e-6;
void File() {
  freopen("D:\\in.txt", "r", stdin);
  freopen("D:\\out.txt", "w", stdout);
}
template <class T>
inline void read(T &x) {
  char c = getchar();
  x = 0;
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
}
long long mod = 1e9 + 7;
const int maxn = 1600010;
int n, k;
long long f[maxn], a[maxn];
struct X {
  int L, R;
} s[maxn];
int c[maxn], b[maxn], sz;
long long ans[maxn];
int lowbit(int x) { return x & (-x); }
int sum(int x) {
  int res = 0;
  while (x > 0) res = res + c[x], x = x - lowbit(x);
  return res;
}
void update(int x, int v) {
  while (x <= 800000) c[x] = c[x] + v, x = x + lowbit(x);
}
long long extend_gcd(long long a, long long b, long long &x, long long &y) {
  if (a == 0 && b == 0) return -1;
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long d = extend_gcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}
long long mod_reverse(long long a, long long n) {
  long long x, y;
  long long d = extend_gcd(a, n, x, y);
  if (d == 1)
    return (x % n + n) % n;
  else
    return -1;
}
int get(int x) {
  int L = 0, R = sz - 1, pos = 0;
  while (L <= R) {
    int mid = (L + R) / 2;
    if (b[mid] < x)
      L = mid + 1;
    else if (b[mid] == x)
      pos = mid, R = mid - 1;
    else
      R = mid - 1;
  }
  return pos + 1;
}
bool cmp(X a, X b) { return a.L < b.L; }
int main() {
  scanf("%d%d", &n, &k);
  f[0] = 1;
  for (int i = 1; i <= 400000; i++) f[i] = i * f[i - 1] % mod;
  for (int i = k; i <= 400000; i++) {
    long long fz = f[i] % mod, fm = f[k] * f[i - k] % mod;
    long long ni = mod_reverse(fm, mod);
    a[i] = fz * ni % mod;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &s[i].L, &s[i].R);
    b[sz++] = s[i].L, b[sz++] = s[i].R;
    b[sz++] = s[i].L - 1;
    b[sz++] = s[i].L + 1;
    b[sz++] = s[i].R - 1;
    b[sz++] = s[i].R + 1;
  }
  sort(b, b + sz);
  sort(s + 1, s + 1 + n, cmp);
  int h = 1;
  for (int i = 1; i <= sz; i++) {
    while (h <= n && get(s[h].L) == i) {
      update(get(s[h].R), 1);
      h++;
    }
    ans[i] = a[sum(800000) - sum(i - 1)];
  }
  long long Ans = 0;
  for (int i = 0; i < sz;) {
    int pos = -1;
    for (int j = i; j < sz; j++) {
      if (b[j] > b[i]) {
        pos = j;
        break;
      }
    }
    if (pos == -1) {
      Ans = (Ans + ans[i + 1]) % mod;
      break;
    }
    Ans = (Ans + (b[pos] - b[i]) * ans[i + 1] % mod) % mod;
    i = pos;
  }
  printf("%lld\n", Ans);
  return 0;
}
