#include <bits/stdc++.h>
using namespace std;
void read(int &x) {
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
void read(long long &x) {
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
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
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
  if (x < 0) {
    putchar('-');
    x = abs(x);
  }
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
int n, m, i, j, dis[305], cnt, x, y, a[305], mp[305][305], vis[305], lk[305], s;
struct ed {
  int fr, to, c, re, id;
} e[90005];
vector<int> bi[305];
void init() {
  int i;
  cnt = 0;
  for (i = 1; i <= n; i++) bi[i].clear();
}
bool bfs(int st, int ed) {
  int i;
  queue<int> qx;
  memset(dis, -1, sizeof(dis));
  dis[st] = 0;
  qx.push(st);
  while (!qx.empty()) {
    int x = qx.front();
    qx.pop();
    for (i = 0; i < bi[x].size(); i++) {
      if (e[bi[x][i]].to != st && e[bi[x][i]].c > 0 &&
          dis[e[bi[x][i]].to] == -1) {
        dis[e[bi[x][i]].to] = dis[x] + 1;
        qx.push(e[bi[x][i]].to);
      }
    }
  }
  if (dis[ed] == -1) return 0;
  return 1;
}
int dfs(int x, int ed, int flw) {
  if (x == ed) {
    return flw;
  }
  int i, res = 0;
  for (i = 0; i < bi[x].size(); i++) {
    if (dis[x] + 1 == dis[e[bi[x][i]].to] && e[bi[x][i]].c > 0) {
      int t = dfs(e[bi[x][i]].to, ed, min(e[bi[x][i]].c, flw));
      e[bi[x][i]].c -= t;
      e[e[bi[x][i]].re].c += t;
      flw -= t;
      res += t;
      if (flw < 1) break;
    }
  }
  if (res == 0) dis[x] = -123456;
  return res;
}
int maxflow(int st, int ed) {
  int ans = 0;
  while (bfs(st, ed)) ans += dfs(st, ed, 0x22222222);
  return ans;
}
void add(int x, int y, int sz, int id = 0) {
  cnt += 2;
  e[cnt - 1] = {x, y, sz, cnt, id};
  e[cnt] = {y, x, 0, cnt - 1, id};
  bi[x].push_back(cnt - 1);
  bi[y].push_back(cnt);
}
bool cynthia(int x) {
  if (vis[x]) return 0;
  vis[x] = 1;
  int i;
  for (i = 1; i <= n; i++)
    if (mp[x][i]) {
      if (!lk[i] || cynthia(lk[i])) {
        lk[i] = x;
        return 1;
      }
    }
  return 0;
}
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    int x, y;
    cin >> x;
    while (x--) {
      cin >> y;
      mp[i][y] = 1;
    }
  }
  for (i = 1; i <= n; i++) {
    memset(vis, 0, sizeof(vis));
    cynthia(i);
  }
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = -a[i];
    if (a[i] >= 0) {
      s += a[i];
      add(0, i, a[i]);
    } else
      add(i, n + 1, abs(a[i]));
  }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      if (mp[i][j]) add(i, lk[j], 0x3bbbbbbb);
  cout << maxflow(0, n + 1) - s;
  return 0;
}
