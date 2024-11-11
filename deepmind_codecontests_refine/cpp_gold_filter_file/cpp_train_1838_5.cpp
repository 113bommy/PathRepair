#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long mod = 1000000007;
const double e = 2.718281828459;
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long gcd1(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long pow_mod(long long a, long long b, long long c) {
  long long ans = 1;
  a = a % c;
  while (b > 0) {
    if (b % 2 == 1) ans = (ans * a) % c;
    b = b / 2;
    a = (a * a) % c;
  }
  return ans;
}
int pow_int(int a, int b) {
  int ans = 1;
  while (b > 0) {
    if (b % 2 == 1) ans = ans * a;
    b = b / 2;
    a = a * a;
  }
  return ans;
}
long long pow_llong(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b % 2 == 1) ans = ans * a;
    b = b / 2;
    a = a * a;
  }
  return ans;
}
const int dx[9] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
const int dy[9] = {0, 1, 0, -1, -1, -1, 0, 1, 1};
int Scan() {
  int res = 0, flag = 0;
  char ch;
  if ((ch = getchar()) == '-') {
    flag = 1;
  } else if (ch >= '0' && ch <= '9') {
    res = ch - '0';
  }
  while ((ch = getchar()) >= '0' && ch <= '9') {
    res = res * 10 + (ch - '0');
  }
  return flag ? -res : res;
}
void Out(int a) {
  if (a < 0) {
    putchar('-');
    a = -a;
  }
  if (a >= 10) {
    Out(a / 10);
  }
  putchar(a % 10 + '0');
}
long long jc_mod(long long a, long long b, long long mod) {
  long long ans = 1;
  b = max(b, a - b);
  for (long long i = a; i > b; i--) {
    ans *= i;
    ans %= mod;
  }
  return ans;
}
double lg(double a) { return (log(a) / log(10.0)); }
int lowbit(int x) { return x & -x; }
inline int read() {
  int f = 1, x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
void lisan(int *x, int n) {
  int data[100010];
  for (int i = 1; i <= n; i++) data[i] = x[i];
  sort(data + 1, data + 1 + n);
  int o = unique(data + 1, data + 1 + n) - data - 1;
  for (int i = 1; i <= n; i++)
    x[i] = lower_bound(data + 1, data + 1 + o, x[i]) - data;
}
void qmain() {
  freopen("in.txt", "w", stdout);
  cout << 100000 << " " << 99999 << endl;
  for (int i = 1; i <= 99999; i++) {
    printf("1 %d\n", i + 1);
  }
}
int a[2005], dp[2005];
int n;
int bsearch(int len, int x) {
  int l = 0, r = len - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (x >= dp[mid - 1] && x < dp[mid])
      return mid;
    else if (x < dp[mid - 1])
      r = mid - 1;
    else
      l = mid + 1;
  }
  return l;
}
int LIS() {
  dp[0] = a[0];
  int len = 1;
  int j;
  for (int i = 1; i < n; i++) {
    if (a[i] < dp[0])
      j = 0;
    else if (a[i] >= dp[len - 1])
      j = len++;
    else
      j = bsearch(len, a[i]);
    dp[j] = a[i];
  }
  return len;
}
long long yu[1000000];
long long ans[1000000];
int main() {
  int q = 1;
  long long p;
  long long k;
  scanf("%I64d", &p);
  scanf("%I64d", &k);
  if (k > p) {
    printf("1\n%I64d\n", p);
    return 0;
  }
  yu[0] = p % k;
  p = p / k;
  p = -p;
  ans[0] = p;
  while (p >= k || p < 0) {
    if (p < 0) {
      long long y = p % k;
      if (y < 0) y += k;
      yu[q] = y;
      p = (y - p) / k;
    } else {
      yu[q] = p % k;
      p /= k;
      p = -p;
    }
    ans[q] = p;
    q++;
  }
  printf("%d\n", q + 1);
  for (int i = 0; i <= q - 1; i++) printf("%I64d ", yu[i]);
  printf("%I64d\n", p);
}
