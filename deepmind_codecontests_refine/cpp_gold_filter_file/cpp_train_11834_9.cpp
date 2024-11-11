#include <bits/stdc++.h>
using namespace std;
void readi(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
void readll(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
void readc(char &x) {
  char c;
  while ((c = getchar()) == ' ')
    ;
  x = c;
}
void writes(string s) { puts(s.c_str()); }
void writeln() { writes(""); }
void writei(int x) {
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
void writell(long long x) {
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
inline long long inc(int &x) { return ++x; }
inline long long inc(long long &x) { return ++x; }
inline long long inc(int &x, long long y) { return x += y; }
inline long long inc(long long &x, long long y) { return x += y; }
inline double inc(double &x, double y) { return x += y; }
inline long long dec(int &x) { return --x; }
inline long long dec(long long &x) { return --x; }
inline long long dec(int &x, long long y) { return x -= y; }
inline long long dec(long long &x, long long y) { return x -= y; }
inline double dec(double &x, double y) { return x -= y; }
inline long long mul(int &x) { return x = ((long long)x) * x; }
inline long long mul(long long &x) { return x = x * x; }
inline long long mul(int &x, long long y) { return x *= y; }
inline long long mul(long long &x, long long y) { return x *= y; }
inline double mul(double &x, double y) { return x *= y; }
inline long long divi(const int &x) {
  long long ans, l, r, mid;
  ans = 0;
  l = 0;
  r = 0x3fffffff;
  while (l < r) {
    mid = (l + r) / 2;
    if (mid * mid <= x) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid;
  }
  return ans;
}
inline long long divi(const long long &x) {
  long long ans, l, r, mid;
  ans = 0;
  l = 0;
  r = 0x3fffffff;
  while (l < r) {
    mid = (l + r) / 2;
    if (mid * mid <= x) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid;
  }
  return ans;
}
inline long long divi(int &x, long long y) { return x /= y; }
inline long long divi(long long &x, long long y) { return x /= y; }
inline double divi(double &x, double y) { return x /= y; }
inline long long mod(int &x, long long y) { return x %= y; }
inline long long mod(long long &x, long long y) { return x %= y; }
int n, m, i, j, ct[100005], x, y, vis[100005];
vector<int> e[100005];
struct vt {
  int id, deg;
} a[100005];
bool cmp(vt x, vt y) { return x.deg > y.deg; }
bool dfs(int x) {
  if (vis[x] == 1) return 1;
  if (vis[x] == 2) return 0;
  vis[x] = 1;
  for (__typeof((e[x]).begin()) it = (e[x]).begin(); it != (e[x]).end(); it++)
    if (dfs(*it)) return 1;
  vis[x] = 2;
  return 0;
}
bool check(int x) {
  memset(vis, 0, sizeof(vis));
  vis[x] = 2;
  int i;
  for (i = 1; i <= n; i++) {
    if (!vis[i] && dfs(i)) {
      for (i = 1; i <= n; i++)
        if (vis[i] != 1) ct[i] = 1;
      return 0;
    }
  }
  return 1;
}
int main() {
  double st = clock();
  ios_base::sync_with_stdio(false);
  ;
  cin >> n >> m;
  if ((1) <= ((m)))
    for (((i)) = (1); ((i)) <= ((m)); ((i))++) {
      cin >> x >> y;
      e[x].push_back(y);
    }
  if ((1) <= ((n)))
    for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
      a[i].id = i;
      a[i].deg = e[i].size();
    }
  stable_sort(a + 1, a + n + 1, cmp);
  if ((1) <= ((n)))
    for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
      if ((clock() - st) / CLOCKS_PER_SEC > 0.9) break;
      x = a[i].id;
      if (ct[x] || !check(x)) continue;
      cout << x;
      return 0;
    }
  cout << "-1";
  return 0;
}
