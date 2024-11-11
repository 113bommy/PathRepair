#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
ostream& operator<<(ostream& os, __int128 a) {
  char c[40], tot = 0;
  if (a < 0) os.put('-'), a = -a;
  while (a) c[tot++] = a % 10, a /= 10;
  while (tot) os.put(c[--tot] + 48);
  return os;
}
istream& operator>>(istream& is, __int128& a) {
  register char c = is.get(), f = 0;
  if (c == '-') f = 1, c = is.get();
  for (a = 0; 47 < c && c < 58; c = is.get()) a = (a << 3) + (a << 1) + c - 48;
  f && (a = -a);
  return is;
}
template <typename T>
inline void _debug(const char* names, T&& t) {
  (cerr << names << " = " << t << '\n').flush();
}
template <typename T1, typename... T>
inline void _debug(const char* names, T1&& t1, T&&... t) {
  const char* comma = strchr(names, ',');
  (cerr.write(names, comma - names) << " = " << t1 << ", ").flush();
  _debug(comma + 1, t...);
}
const int inf = 0x3f3f3f3f;
const long long lnf = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-5, PI = acos(-1.0);
const int mod1 = 1000000007, mod2 = 558244353;
bool solve(const int& CASENUM);
signed main() {
  cerr << "Program by H~S~C: \n";
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(12);
  solve(1);
  return 0;
}
const char ch[3][15] = {"AAA.A.A....A", ".A..A.AAAAAA", ".A.AAAA....A"};
int n, m, sp, ans;
char w[10][10], a[10][10];
void dfs(int x, int y, int now) {
  if (x >= n - 2) {
    if (now > ans) {
      ans = now;
      memcpy(w, a, sizeof w);
    }
    return;
  }
  if (y >= m - 2) return dfs(x + 1, 0, now);
  if (sp / 5 + now <= ans) return;
  sp -= (a[x][y] == '.');
  for (int g = 0; g < 12; g += 3) {
    bool flag = true;
    for (int i = 0; i < (3); ++i)
      for (int j = 0; j < (3); ++j)
        if (ch[i][j + g] == 'A' && a[x + i][y + j] != '.') flag = 0;
    if (flag) {
      for (int i = 0; i < (3); ++i)
        for (int j = 0; j < (3); ++j)
          if (ch[i][j + g] == 'A') a[x + i][y + j] = now + 'A';
      sp -= 5;
      dfs(x, y + 1, now + 1);
      sp += 5;
      for (int i = 0; i < (3); ++i)
        for (int j = 0; j < (3); ++j)
          if (ch[i][j + g] == 'A') a[x + i][y + j] = '.';
    }
  }
  dfs(x, y + 1, now);
  sp += (a[x][y] == '.');
}
bool solve(const int& CASENUM) {
  scanf("%d %d", &n, &m), sp = n * m;
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (m); ++j) a[i][j] = w[i][j] = '.';
  dfs(0, 0, 0);
  printf("%d\n", ans);
  for (int i = 0; i < (n); ++i) puts(w[i]);
  return false;
}
