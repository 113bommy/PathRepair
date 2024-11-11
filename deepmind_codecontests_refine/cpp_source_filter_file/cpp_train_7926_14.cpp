#include <bits/stdc++.h>
using namespace std;
int n, m, flag, cnt, res, i, p;
char str[1001];
int C[1001];
vector<pair<int, int>> V[2 * 1001];
void dfs(int i) {
  int j, sz, k, e;
  sz = V[i].size();
  for (j = 0; j < sz; j++) {
    k = V[i][j].first;
    e = V[i][j].second;
    if (C[k] == -1) {
      if (e == 0)
        C[k] = C[i];
      else
        C[k] = 1 - C[i];
      dfs(k);
    } else if ((e == 0 && C[i] != C[k]) || (e == 1 && C[i] == C[k]))
      flag = 1;
  }
}
int main() {
  scanf("%s", str);
  n = strlen(str);
  reverse(str, str + n);
  for (m = 1; m < n; m++) {
    for (i = 0; i < n + m + 2; i++) V[i].clear();
    V[n + m].push_back(make_pair(n + m + 1, 1));
    V[n + m + 1].push_back(make_pair(n + m, 1));
    for (i = 0; i < n - 1 - i; i++) {
      V[i].push_back(make_pair(n - 1 - i, 0));
      V[n - 1 - i].push_back(make_pair(i, 0));
    }
    V[n + m - 1].push_back(make_pair(n + m + 1, 0));
    V[n + m + 1].push_back(make_pair(n + m - 1, 0));
    for (i = 0; i < m - 1 - i; i++) {
      V[n + i].push_back(make_pair(n + m - 1 - i, 0));
      V[n + m - 1 - i].push_back(make_pair(n + i, 0));
    }
    for (i = 0; i < m; i++)
      if (str[i] == '1') {
        V[i].push_back(make_pair(n + i, 1));
        V[n + i].push_back(make_pair(i, 1));
      } else if (str[i] == '0') {
        V[i].push_back(make_pair(n + i, 0));
        V[n + i].push_back(make_pair(i, 0));
      }
    for (i = m; i < n; i++)
      if (str[i] == '1') {
        V[i].push_back(make_pair(n + m + 1, 0));
        V[n + m + 1].push_back(make_pair(i, 0));
      } else if (str[i] == '0') {
        V[i].push_back(make_pair(n + m, 0));
        V[n + m].push_back(make_pair(i, 0));
      }
    flag = 0;
    cnt = 0;
    memset(C, -1, sizeof C);
    for (i = 0; i < n + m + 2; i++)
      if (C[i] == -1) {
        C[i] = 0;
        dfs(i);
        cnt++;
      }
    if (!flag) {
      p = 1;
      for (i = 0; i + 1 < cnt; i++) p = 2 * p % 998244353;
      res = (res + p) % 998244353;
    }
  }
  printf("%d\n", res);
  return 0;
}
