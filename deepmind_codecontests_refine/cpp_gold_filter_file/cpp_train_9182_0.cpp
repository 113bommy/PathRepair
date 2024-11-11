#include <bits/stdc++.h>
using namespace std;
long long n;
const int N = 1000005;
int type[N], q[N], f[N];
int top, nd, id[N];
long long ans[N];
vector<int> e[N];
int getflow(int x) {
  f[x] = 0;
  if (type[x] == 0) f[x] = 1;
  if (type[x] == 1) {
    f[x] = 1ll << 30;
    for (int i = (int)(0); i <= (int)(e[x].size() - 1); i++)
      f[x] = min(f[x], getflow(e[x][i]));
  }
  if (type[x] == 2) {
    f[x] = 0;
    for (int i = (int)(0); i <= (int)(e[x].size() - 1); i++)
      f[x] += getflow(e[x][i]);
  }
  return f[x];
}
void updans(int x, long long val) {
  if (type[x] == 0) ans[id[x]] = val;
  if (type[x] == 1)
    for (int i = (int)(0); i <= (int)(e[x].size() - 1); i++)
      if (f[e[x][i]] == f[x]) return updans(e[x][i], val);
  if (type[x] == 2)
    for (int i = (int)(0); i <= (int)(e[x].size() - 1); i++)
      updans(e[x][i], val);
}
void solve() {
  *id = 0;
  long long n;
  cin >> n;
  string tmp;
  getline(cin, tmp);
  int top = 0, len = tmp.length();
  for (; nd; type[nd] = 0, e[nd].clear(), nd--)
    ;
  q[++top] = nd = 1;
  for (int i = (int)(0); i <= (int)(len - 1); i++) {
    if (tmp[i] == '(') q[++top] = ++nd;
    if (tmp[i] == ')') {
      e[q[top - 1]].push_back(q[top]);
      --top;
    }
    if (tmp[i] == '*') e[q[top]].push_back(++nd), id[nd] = ++*id;
    if (tmp[i] == 'S') type[q[top]] = 1;
    if (tmp[i] == 'P') type[q[top]] = 2;
  }
  type[1] = 1;
  for (int i = (int)(1); i <= (int)(*id); i++) ans[i] = 0;
  n *= getflow(1);
  updans(1, n);
  printf("REVOLTING");
  for (int i = (int)(1); i <= (int)(*id); i++) printf(" %lld", ans[i]);
  puts("");
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}
