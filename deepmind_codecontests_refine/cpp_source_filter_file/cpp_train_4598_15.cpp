#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
void f(long long a[], long long n) {
  long long i, j;
  for (i = 1; i <= n; i++) a[i] = 1;
  for (i = 2; i * i <= n; i++) {
    if (a[i]) {
      for (j = 2 * i; j <= n; j += i) a[j] = 0;
    }
  }
}
long long getprime(long long n) {
  if (n == 1) return 0;
  for (long long i = 2; i <= n / i; i++)
    if (n % i == 0) return 1;
  return 0;
}
const int MAXN = 5e5 + 54;
char s[MAXN];
int cnt[MAXN];
int a[MAXN], pos[MAXN], maxv[MAXN], pos2[MAXN], minv[MAXN];
int main() {
  int n, x;
  scanf("%d%d", &n, &x);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    maxv[i] = max(maxv[i - 1], a[i]);
    pos[a[i]] = i;
  }
  for (int i = n; i >= 1; i--) {
    pos2[a[i]] = i;
    if (i == n)
      minv[i] = a[i];
    else
      minv[i] = min(minv[i + 1], a[i]);
  }
  int high;
  for (high = x; high >= 2; high--) {
    if (maxv[pos[high]] > high) {
      break;
    }
  }
  long long cnt = x - high + 1;
  for (int i = 1; i <= x; i++) {
    if (minv[pos2[i]] < i && pos2[i] != 0) break;
    high = max(high, i);
    high = max(high, maxv[pos[i]]);
    cnt += x - high + 1 - (i == high);
  }
  printf("%lld\n", cnt);
}
