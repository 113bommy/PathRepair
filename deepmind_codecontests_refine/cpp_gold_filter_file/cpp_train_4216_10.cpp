#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
inline const int getint() {
  int r = 0, k = 1;
  char c = getchar();
  for (; c < '0' || c > '9'; c = getchar())
    if (c == '-') k = -1;
  for (; c >= '0' && c <= '9'; c = getchar()) r = r * 10 + c - '0';
  return k * r;
}
using namespace std;
const int maxn = 1e6 + 10;
char s[maxn];
char p[maxn];
int y[maxn], ed[maxn], f[maxn];
void getfail(int len) {
  f[0] = 0, f[1] = 0;
  int i;
  for (i = (1); i <= (len - 1); i++) {
    int j = f[i];
    while (j && p[i] != p[j]) j = f[j];
    if (p[i] == p[j])
      f[i + 1] = j + 1;
    else
      f[i + 1] = 0;
  }
}
const long long mod = 1e9 + 7;
long long pow(long long x, long long r) {
  if (r == 0) return 1;
  long long ans = (long long)1;
  while (r) {
    if (r & 1) ans = ans * x % mod;
    x = x * x % mod;
    r >>= 1;
  }
  return ans;
}
bool has[maxn];
int len;
void dfs(int k) {
  if (k == 0) {
    return;
  }
  has[k] = true;
  dfs(f[k]);
}
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    scanf("%s", p);
    int i;
    for (i = (1); i <= (m); i++) {
      scanf("%d", &y[i]);
    }
    if (m == 0) {
      long long ret = 1;
      for (i = (1); i <= (n); i++) {
        ret = ret * 26 % mod;
      }
      cout << ret << endl;
      continue;
    }
    memset(has, 0, sizeof(has));
    len = strlen(p);
    getfail(len);
    dfs(f[len]);
    int ans = y[1] - 1;
    ed[1] = y[1] + len - 1;
    int flag = 1;
    for (i = (2); i <= (m); i++) {
      if (y[i] - y[i - 1] < len) {
        if (!has[y[i - 1] + len - y[i]]) {
          flag = 0;
          break;
        }
      } else {
        ans += y[i] - y[i - 1] - len;
      }
    }
    ans += n - y[m] - len + 1;
    if (flag) {
      long long ret = 1;
      for (int i = 1; i <= ans; i++) {
        ret = ret * 26 % mod;
      }
      cout << ret << endl;
    } else
      cout << "0" << endl;
  }
  return 0;
}
