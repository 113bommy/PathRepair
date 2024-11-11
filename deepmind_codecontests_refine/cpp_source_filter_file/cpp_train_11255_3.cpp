#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
const int N = 1010;
int n, a[N], vis[N];
char s[N][N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    --a[i];
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) s[i][j] = '.';
  int l = n, r = -1;
  for (int i = 0; i < n; i++)
    if (a[i] != i) {
      l = min(l, i);
      r = max(r, i);
    }
  if (l > r) {
    printf("%d\n", n);
    for (int i = 0; i < n; i++) puts(s[i]);
    return 0;
  }
  int row = 0;
  int pre = 0, nxt = a[r];
  for (int i = l; i < r + 1; i++)
    if (a[i] == r) pre = i;
  a[pre] = a[r];
  a[r] = r;
  for (int i = l; i < r; i++)
    if (!vis[i]) {
      if (a[i] == i) continue;
      int x = i;
      bool gor = 1;
      while (!vis[x]) {
        vis[x] = 1;
        if (gor) {
          if (a[x] > x) {
            s[row][x] = '/';
            ;
            s[row][a[x]] = '/';
          } else {
            s[row][x] = '/';
            s[row][r] = '/';
            ++row;
            s[row][r] = '\\';
            s[row][a[x]] = '\\';
            gor = 0;
          }
        } else {
          if (a[x] < x) {
            s[row][x] = '\\';
            s[row][a[x]] = '\\';
          } else {
            s[row][x] = '\\';
            s[row][l] = '\\';
            ++row;
            s[row][l] = '/';
            s[row][a[x]] = '/';
            gor = 1;
          }
        }
        x = a[x];
      }
      ++row;
    }
  s[row][nxt] = '/';
  s[row][r] = '/';
  printf("%d\n", n - 1);
  for (int i = n - 1; i >= 0; i--) puts(s[i]);
}
