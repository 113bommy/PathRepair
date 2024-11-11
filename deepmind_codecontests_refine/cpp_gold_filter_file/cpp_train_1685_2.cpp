#include <bits/stdc++.h>
using namespace std;
const unsigned long long hash1 = 201326611;
const int inf = 0x3f3f3f3f;
const int _inf = 0xc0c0c0c0;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long _INF = 0xc0c0c0c0c0c0c0c0;
const long long mod = (int)1e9 + 7;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long ksm(long long a, long long b, long long mod) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}
long long inv2(long long a, long long mod) { return ksm(a, mod - 2, mod); }
void exgcd(long long a, long long b, long long &x, long long &y, long long &d) {
  if (!b) {
    d = a;
    x = 1;
    y = 0;
  } else {
    exgcd(b, a % b, y, x, d);
    y -= x * (a / b);
  }
}
inline int read() {
  int date = 0, m = 1;
  char ch = 0;
  while (ch != '-' && (ch<'0' | ch> '9')) ch = getchar();
  if (ch == '-') {
    m = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    date = date * 10 + ch - '0';
    ch = getchar();
  }
  return date * m;
}
const int MAX_N = 150025;
int C[MAX_N << 1], arr[MAX_N], b[MAX_N];
void add(int x, int v) {
  for (; x < MAX_N; x += x & (-x)) C[x] += v;
}
int get(int x) {
  int res = 0;
  for (; x; x -= x & (-x)) res += C[x];
  return res;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n + 2; ++i) C[i] = 0;
    for (int i = 1; i <= n; ++i) scanf("%d", &arr[i]), b[i] = arr[i];
    sort(b + 1, b + 1 + n);
    int sz = unique(b + 1, b + 1 + n) - b - 1;
    int ans = 0;
    for (int i = n; i >= 1; --i) {
      arr[i] = lower_bound(b + 1, b + 1 + sz, arr[i]) - b;
      ans += min(get(arr[i]), 1);
      add(arr[i] + 1, 1);
    }
    printf("%d\n", ans);
  }
  return 0;
}
