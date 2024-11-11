#include <bits/stdc++.h>
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (((a * b) / gcd(a, b))); }
long long phi(long long n) {
  long long result = n;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      result -= result / i;
    }
  }
  if (n > 1) result -= result / n;
  return result;
}
long long binpow(long long a, long long n, long long c) {
  long long res = 1;
  while (n) {
    if (n & 1) res *= a;
    res %= c;
    a *= a;
    a %= c;
    n >>= 1;
  }
  res = (res + c) % c;
  return res;
}
int nxi(int n) {
  bool min = 0;
  char c;
  n = 0;
  while ((c = getc(stdin)) && c <= 32)
    ;
  if (c == '-')
    min = 1;
  else
    n = c - 48;
  while ((c = getc(stdin)) && c > 32) n = (n << 3) + (n << 1) + c - 48;
  if (min) n = -n;
  return n;
}
void prl(int n) {
  if (n == 0) {
    puts("0");
    return;
  }
  if (n < 0) {
    putchar('-');
    n = -n;
  }
  static int s[10];
  int top = 0;
  while (n > 0) s[top++] = n % 10, n /= 10;
  while (top--) putchar(s[top] + 48);
  puts("");
}
using namespace std;
const int nmax = 300010;
int n, m, l, r, type, val, pos[nmax], s[nmax], a[nmax], v;
vector<int> g[nmax];
int t[2][nmax];
int dep[nmax];
int pp = 1;
void dfs(int v, int p = -1, int h = 0) {
  pos[v] = pp;
  dep[v] = h;
  pp++;
  s[v] = 1;
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    if (to == p) continue;
    dfs(to, v, h ^ 1);
    s[v] += s[to];
  }
}
void update(int l, int val, int *t) {
  for (int i = l; i < nmax; i = (i | (i + 1))) t[i] += val;
}
int get(int l, int *t) {
  int s = 0;
  for (int i = l; i >= 0; i = (i & (i + 1)) - 1) s += t[i];
  return s;
}
int get2(int l, int *t) { return get(l, t); }
int main() {
  srand(time(0));
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d %d", &l, &r);
    g[l].push_back(r);
    g[r].push_back(l);
  }
  dfs(1, -1, 0);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &type, &v);
    if (type == 1) {
      scanf("%d", &val);
      update(pos[v], val, t[dep[v]]);
      update(pos[v] + s[v], -val, t[dep[v]]);
    } else {
      printf("%d\n",
             a[v] + get2(pos[v], t[dep[v]]) - get2(pos[v], t[1 - dep[v]]));
    }
  }
  return 0;
}
