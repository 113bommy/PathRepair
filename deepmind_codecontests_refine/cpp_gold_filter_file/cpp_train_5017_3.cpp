#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-6;
const int inf = 0x3f3f3f3f;
const double INF = 1e20;
const int maxn = 100000 + 10;
const int maxm = 100000 + 10;
const int mod = 1000000000 + 7;
int gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline long long read() {
  char ch = getchar();
  long long x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n;
int a[maxn], b[maxn];
int ans[maxn];
bool vis[maxn];
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) vis[i] = false;
  for (int i = 1; i <= n; ++i) a[i] = read();
  for (int i = 1; i <= n; ++i) b[i] = read();
  int now = 1;
  int p = 1;
  int res = 0;
  for (int i = 1; i <= n && now <= n; ++i) {
    if (vis[a[i]]) continue;
    while (b[p] != a[i]) {
      vis[b[p]] = true;
      p++;
    }
    vis[b[p]] = true;
    res += p - now;
    now = p + 1;
  }
  printf("%d\n", res);
}
