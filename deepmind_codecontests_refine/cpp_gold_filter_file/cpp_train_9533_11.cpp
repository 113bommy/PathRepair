#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1000050;
int Len, n, dif, d;
char str[MaxN];
string s[MaxN];
int L[MaxN], dfn;
bool used[MaxN];
vector<string> ans[MaxN];
string sub(int l, int r) {
  string ret = "";
  for (int i = l; i <= r; ++i) ret += str[i];
  return ret;
}
int num(int l, int r) {
  int ret = 0;
  for (int i = l; i <= r; ++i) ret = ret * 10 + str[i] - '0';
  return ret;
}
void dfs(int x, int lvl) {
  used[x] = true;
  ans[lvl].push_back(s[x]);
  for (int i = 1; i <= L[x]; ++i) dfs(++dfn, lvl + 1);
}
int main() {
  scanf("%s", str + 1);
  Len = strlen(str + 1);
  for (int i = 1; i <= Len; ++i) {
    for (int j = 0; j <= Len; ++j) {
      if (i + j == Len || str[i + j] == ',') {
        if (dif % 2 == 0)
          s[++n] = sub(i, i + j - 1);
        else
          L[n] = num(i, i + j - 1);
        i = i + j;
        ++dif;
        break;
      }
    }
  }
  for (int i = 1; i <= n; ++i)
    if (!used[i]) {
      ++dfn;
      dfs(i, 1);
    }
  for (int i = 1; i <= n + 1; ++i)
    if (!ans[i].size()) {
      d = i;
      break;
    }
  printf("%d\n", d - 1);
  for (int i = 1; i <= d - 1; ++i) {
    for (int j = 0; j <= ans[i].size() - 1; ++j) cout << ans[i][j] << ' ';
    cout << endl;
  }
  return 0;
}
