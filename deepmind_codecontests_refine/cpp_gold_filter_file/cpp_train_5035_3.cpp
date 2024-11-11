#include <bits/stdc++.h>
using namespace std;
const int maxn = 2050;
bool pc = 1;
int root, ndtot, n, cnt;
vector<int> son[maxn];
char s[maxn];
int a[maxn][maxn], req[maxn], num[maxn][4], bel[maxn], Q[maxn], rk[maxn];
inline void dfs(int x) {
  num[x][0] = num[x][1] = num[x][2] = 0;
  if (x <= n) {
    bel[x] = req[x];
    num[x][bel[x]]++;
    return;
  }
  int emp = 1, ful = 1;
  for (int(i) = (0); (i) < (son[x].size()); (i)++) {
    dfs(son[x][i]);
    if (bel[son[x][i]]) emp = 0;
    if (bel[son[x][i]] != 1) ful = 0;
    num[x][bel[son[x][i]]]++;
  }
  if (emp)
    bel[x] = 0;
  else if (ful)
    bel[x] = 1;
  else
    bel[x] = 2;
}
inline int get(int x, vector<int> &L) {
  if (num[x][2] > 1) return 0;
  if (Q[x]) {
    if (num[x][1] && bel[son[x][0]] != 1 || !num[x][1] && bel[son[x][0]] != 2)
      reverse(son[x].begin(), son[x].end());
    for (int(i) = (0); (i) < (num[x][1]); (i)++) {
      if (bel[son[x][i]] != 1) return 0;
      L.push_back(son[x][i]);
    }
    int k = num[x][1];
    if (num[x][2] && bel[son[x][k]] != 2) return 0;
    if (num[x][2]) {
      if (!get(son[x][k], L)) return 0;
      k++;
    }
    for (int(i) = (k); (i) < (son[x].size()); (i)++) L.push_back(son[x][i]);
  } else {
    if (num[x][1]) {
      int t1 = ++ndtot;
      for (int(i) = (0); (i) < (son[x].size()); (i)++)
        if (bel[son[x][i]] == 1) son[t1].push_back(son[x][i]);
      if (son[t1].size() == 1) t1 = son[t1][0];
      L.push_back(t1);
    }
    for (int(i) = (0); (i) < (son[x].size()); (i)++)
      if (bel[son[x][i]] == 2)
        if (!get(son[x][i], L)) return 0;
    if (num[x][0]) {
      int t2 = ++ndtot;
      for (int(i) = (0); (i) < (son[x].size()); (i)++)
        if (!bel[son[x][i]]) son[t2].push_back(son[x][i]);
      if (son[t2].size() == 1) t2 = son[t2][0];
      L.push_back(t2);
    }
  }
  return 1;
}
inline int getr(int x, vector<int> &L) {
  int sz = L.size();
  if (get(x, L)) {
    reverse(L.begin() + sz, L.end());
    return 1;
  }
  return 0;
}
inline int getl(int x, vector<int> &L) { return get(x, L); }
inline int calc(int x) {
  if (x <= n) return 1;
  if (num[x][1] + num[x][2] == 1)
    for (int(i) = (0); (i) < (son[x].size()); (i)++)
      if (bel[son[x][i]]) return calc(son[x][i]);
  if (num[x][2] > 2) return 0;
  vector<int> tmp;
  tmp.clear();
  if (Q[x]) {
    int Nm = 0, Ed = 0;
    for (int(i) = (0); (i) < (son[x].size()); (i)++) {
      if (Ed && bel[son[x][i]]) return 0;
      if (Nm && !bel[son[x][i]]) Ed = 1;
      if (bel[son[x][i]] == 2) {
        if (!Nm) {
          if (!getr(son[x][i], tmp)) return 0;
        } else if (!getl(son[x][i], tmp))
          return 0;
      } else
        tmp.push_back(son[x][i]);
      if (bel[son[x][i]]) Nm = 1;
    }
  } else {
    int t1 = ++ndtot;
    Q[t1] = 1;
    for (int(i) = (0); (i) < (son[x].size()); (i)++)
      if (bel[son[x][i]] == 2) {
        if (!getr(son[x][i], son[t1])) return 0;
        break;
      }
    if (num[x][1]) {
      int t2 = ++ndtot;
      for (int(i) = (0); (i) < (son[x].size()); (i)++)
        if (bel[son[x][i]] == 1) son[t2].push_back(son[x][i]);
      if (son[t2].size() == 1) t2 = son[t2][0];
      son[t1].push_back(t2);
    }
    int ars = 0;
    for (int(i) = (0); (i) < (son[x].size()); (i)++)
      if (bel[son[x][i]] == 2) {
        if (!ars)
          ars = 1;
        else if (!getl(son[x][i], son[t1]))
          return 0;
      }
    if (son[t1].size() == 1) t1 = son[t1][0];
    tmp.push_back(t1);
    for (int(i) = (0); (i) < (son[x].size()); (i)++)
      if (!bel[son[x][i]]) tmp.push_back(son[x][i]);
  }
  son[x] = tmp;
  return 1;
}
inline void getres(int x) {
  if (x <= n) {
    rk[++cnt] = x;
    return;
  }
  for (int(i) = (0); (i) < (son[x].size()); (i)++) getres(son[x][i]);
}
int main() {
  scanf("%d", &n);
  root = ndtot = n + 1;
  for (int(i) = (1); (i) <= (n); (i)++) son[root].push_back(i);
  for (int(i) = (1); (i) <= (n); (i)++) {
    scanf("%s", s);
    for (int(j) = (1); (j) <= (n); (j)++) {
      req[j] = s[j - 1] - '0';
      a[i][j] = req[j];
    }
    dfs(root);
    if (!calc(root)) {
      pc = 0;
      puts("NO");
      break;
    }
  }
  if (pc) {
    puts("YES");
    getres(root);
    for (int(i) = (1); (i) <= (n); (i)++) {
      for (int(j) = (1); (j) <= (n); (j)++) printf("%d", a[i][rk[j]]);
      puts("");
    }
  }
  return 0;
}
