#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int maxk = 101;
int n, k, Mod;
int f[maxn][maxk][2];
int pw10[maxn], pwk[maxn];
int read() {
  int x = 0;
  char ch = getchar();
  bool positive = 1;
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') positive = 0;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return positive ? x : -x;
}
void input() {
  n = read();
  k = read();
  Mod = read();
}
void init() {
  pw10[0] = pwk[0] = 1;
  for (int i = (1), _b = (n); i <= _b; i++)
    pw10[i] = (pw10[i - 1] * 10) % Mod, pwk[i] = (pwk[i - 1] * 10) % k;
}
int cal(int i, int rem, int change) {
  if (rem == 0 && change) return (i == n ? 1 : (pw10[n - i - 1] * 9ll)) % Mod;
  if (i == n) return 0;
  int &tmp = f[i][rem][change];
  if (tmp != -1) return tmp;
  tmp = 0;
  for (int j = (0), _b = (10); j < _b; j++)
    tmp =
        (tmp + cal(i + 1, (rem + j * 1ll * pwk[i]) % k, change |= j > 0)) % Mod;
  return tmp;
}
void solve() {
  memset(f, -1, sizeof(f));
  printf("%d", cal(0, 0, 0));
}
int main() {
  clock_t timestart, timeend;
  timestart = clock();
  input();
  init();
  solve();
  timeend = clock();
  return 0;
}
