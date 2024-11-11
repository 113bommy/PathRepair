#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long exgcd(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long g = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return g;
}
void gg() {
  printf("-1\n");
  exit(0);
}
int p[6010], N;
long long A[6010], B[6010];
struct Eq {
  long long a, b, c;
} e[6010];
long long chu(long long a, long long b) { return (a + b - 1) / b; }
long long mmul(long long a, long long b, long long M) {
  a = (a % M + M) % M;
  b = (b % M + M) % M;
  long long ans = 0, t = a;
  while (b) {
    if (b & 1) ans = (ans + t) % M;
    t = (t + t) % M;
    b >>= 1;
  }
  return ans;
}
bool merge(int a, int b) {
  int cnt = 0;
  for (int i = 1; i <= N; i++) {
    int cnt1 = 0, cnt2 = 0;
    int t = a;
    while (t % p[i] == 0) t /= p[i], cnt1++;
    t = b;
    while (t % p[i] == 0) t /= p[i], cnt2++;
    if (!B[i] && !cnt2) {
      if (cnt1 != A[i]) gg();
      continue;
    }
    cnt++;
    e[cnt].a = B[i];
    e[cnt].b = -cnt2;
    e[cnt].c = cnt1 - A[i];
  }
  if (!cnt) return false;
  bool flag = false;
  for (int i = 1; i <= cnt && !flag; i++) {
    for (int j = i + 1; j <= cnt && !flag; j++)
      if (e[i].a * e[j].b != e[j].a * e[i].b) {
        swap(e[i], e[1]);
        swap(e[j], e[2]);
        flag = true;
      } else if (e[i].a * e[j].c != e[j].a * e[i].c ||
                 e[i].b * e[j].c != e[j].b * e[i].c)
        gg();
  }
  if (flag) {
    if (!e[1].a) swap(e[1], e[2]);
    long long g = gcd(e[1].a, e[2].a);
    long long m1 = e[2].a / g;
    long long m2 = e[1].a / g;
    long long dc = e[1].c * m1 - e[2].c * m2;
    long long db = e[1].b * m1 - e[2].b * m2;
    if (dc % db != 0) gg();
    long long y = dc / db;
    dc = e[1].c - e[1].b * y;
    if (dc % e[1].a != 0) gg();
    long long x = dc / e[1].a;
    for (int i = 1; i <= cnt; i++)
      if (x * e[i].a + y * e[i].b != e[i].c) gg();
    if (x < 0 || y < 0) gg();
    for (int i = 1; i <= N; i++) A[i] += B[i] * x;
    return true;
  } else {
    long long a = e[1].a, b = -e[1].b, c = e[1].c;
    if (a == 0) {
      if (c % b != 0) gg();
      if (c / b < 0) gg();
      for (int i = 1; i <= N; i++) {
        int cnt1 = 0, cnt2 = 0;
        int t = a;
        while (t % p[i] == 0) t /= p[i], cnt1++;
        t = b;
        while (t % p[i] == 0) t /= p[i], cnt2++;
        A[i] = cnt1 + cnt2 * (c / b);
      }
      return true;
    }
    if (b == 0) {
      if (c % a != 0) gg();
      if (c / a < 0) gg();
      for (int i = 1; i <= N; i++) A[i] += c / a * B[i];
      return true;
    }
    long long x, y;
    long long g = exgcd(a, b, x, y);
    if (c % g != 0) gg();
    x = mmul(x, c / g, b / g);
    y = -(c - x * a) / b;
    long long d = chu(max(0ll, -y), a / g);
    x += d * (b / g);
    for (int i = 1; i <= N; i++) {
      A[i] += B[i] * x;
      B[i] *= b / g;
    }
    return false;
  }
}
const int Mod = 1000000007;
int fpow(int a, long long b) {
  int ans = 1, t = a;
  while (b) {
    if (b & 1) ans = (long long)ans * t % Mod;
    t = (long long)t * t % Mod;
    b >>= 1;
  }
  return ans;
}
void work(int x) {
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) {
      p[++N] = i;
      while (x % i == 0) x /= i;
    }
  if (x > 1) p[++N] = x;
  return;
}
int a[110], b[110];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &a[i], &b[i]);
    work(a[i]);
    work(b[i]);
  }
  sort(p + 1, p + N + 1);
  N = unique(p + 1, p + N + 1) - p - 1;
  for (int i = 1; i <= N; i++) {
    int t = a[1];
    while (t % p[i] == 0) A[i]++, t /= p[i];
    t = b[1];
    while (t % p[i] == 0) B[i]++, t /= p[i];
  }
  int now = 2;
  while (now <= n && !merge(a[now], b[now])) now++;
  while (now <= n) {
    for (int i = 1; i <= N; i++) {
      int cnt1 = 0, cnt2 = 0;
      int t = a[now];
      while (t % p[i] == 0) t /= p[i], cnt1++;
      t = b[now];
      while (t % p[i] == 0) t /= p[i], cnt2++;
      if (!cnt2) {
        if (cnt1 != A[i]) gg();
      } else if (A[i] < cnt1 || A[i] % cnt2 != cnt1 % cnt2)
        gg();
    }
    now++;
  }
  int ans = 1;
  for (int i = 1; i <= N; i++) ans = (long long)ans * fpow(p[i], A[i]) % Mod;
  printf("%d\n", ans);
  return 0;
}
