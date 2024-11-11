#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int INF = 0x3f3f3f3f;
const int iinf = 1 << 30;
const long long linf = 2e18;
const int mod = 1000000007;
const double eps = 1e-7;
void douout(double x) { printf("%lf\n", x + 0.0000000001); }
template <class T>
void print(T a) {
  cout << a << endl;
  exit(0);
}
template <class T>
void chmin(T &a, T b) {
  if (a > b) a = b;
}
template <class T>
void chmax(T &a, T b) {
  if (a < b) a = b;
}
void add(int &a, int b) { a = a + b < mod ? a + b : a + b - mod; }
void sub(int &a, int b) { a = (a - b + mod) % mod; }
void mul(int &a, int b) { a = (long long)a * b % mod; }
int addv(int a, int b) { return (a += b) >= mod ? a -= mod : a; }
int subv(int a, int b) { return (a -= b) < 0 ? a += mod : a; }
int mulv(int a, int b) { return (long long)a * b % mod; }
int read() {
  int f = 1, x = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int pw(int a, int b) {
  int s = 1;
  for (; b; b >>= 1, a = (long long)a * a % mod)
    if (b & 1) s = (long long)s * a % mod;
  return s;
}
int n, ans;
int val[N] = {1}, ans1[N], ans2[N], ans3[N], p[N];
void dfs(int x) {
  if (val[x] == n && x == ans) {
    printf("%d\n", ans);
    for (int i = (0); i <= (ans - 1); i++)
      if (~ans2[i])
        printf("lea e%cx, [e%cx + %d*e%cx]\n", ans1[i] + 'a', ans2[i] + 'a',
               p[i], ans3[i] + 'a');
      else
        printf("lea e%cx, [%d*e%cx]\n", ans1[i] + 'a', p[i], ans3[i] + 'a');
    exit(0);
  }
  if (x == ans) return;
  for (int i = (0); i <= (x); i++)
    for (int j = (-1); j <= (x); j++)
      for (int k = 1; k < 9; k <<= 1) {
        if (j + 1)
          val[x + 1] = val[i] * k + val[j];
        else
          val[x + 1] = val[i] * k;
        ans1[x] = x + 1;
        ans2[x] = j;
        ans3[x] = i;
        p[x] = k;
        dfs(x + 1);
      }
}
signed main() {
  scanf("%d", &n);
  for (ans = 0; ans <= n; ans++) dfs(0);
  return 0;
}
