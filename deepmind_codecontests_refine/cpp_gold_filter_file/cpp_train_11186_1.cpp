#include <bits/stdc++.h>
using namespace std;
inline void __CIN__() {
  ios::sync_with_stdio(false);
  cin.tie(0);
}
char buf;
inline int xint() {
  while (buf = getchar(), buf < '0' || buf > '9')
    ;
  int x = buf - '0';
  for (; buf = getchar(), buf >= '0' && buf <= '9'; x = x * 10 + buf - '0')
    ;
  return x;
}
inline long long xll() {
  while (buf = getchar(), buf < '0' || buf > '9')
    ;
  long long x = buf - '0';
  for (; buf = getchar(), buf >= '0' && buf <= '9'; x = x * 10 + buf - '0')
    ;
  return x;
}
inline string xstring() {
  while (buf = getchar(), buf == ' ' || buf == '\n')
    ;
  string x = "";
  for (x += buf; buf = getchar(), buf != ' ' && buf != '\n'; x += buf)
    ;
  return x;
}
const int MAXN = 2e5 + 5, MAXM = 26;
int sz = 0, canWin[MAXN], canLose[MAXN];
int g[MAXN][MAXM], q[MAXN * MAXM];
string s[MAXN];
string ans[2] = {"Second", "First"};
inline void pre(string x) {
  int l = x.length();
  int st = 0;
  for (int i = 0; i < l; ++i) {
    if (g[st][x[i] - 'a'] == 0) {
      g[st][x[i] - 'a'] = ++sz;
      ++q[st];
    }
    st = g[st][x[i] - 'a'];
  }
  return;
}
void dfs(int st) {
  if (!q[st]) {
    canWin[st] = 0;
    canLose[st] = 1;
  }
  for (int i = 0; i < MAXM; ++i)
    if (g[st][i]) {
      dfs(g[st][i]);
      canWin[st] |= !canWin[g[st][i]];
      canLose[st] |= !canLose[g[st][i]];
    }
}
int main() {
  int n = xint(), k = xint();
  for (int i = 0; i < n; ++i) {
    s[i] = xstring();
    pre(s[i]);
  }
  dfs(0);
  cout << ans[canWin[0] && (canLose[0] || (!canLose[0] && k % 2 == 1))] << endl;
}
