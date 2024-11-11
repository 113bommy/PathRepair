#include <bits/stdc++.h>
using namespace std;
template <class T>
bool minimize(T &x, const T &y) {
  if (x > y)
    x = y;
  else
    return false;
  return true;
}
template <class T>
bool maximize(T &x, const T &y) {
  if (x < y)
    x = y;
  else
    return false;
  return true;
}
const int N = 1e5 + 10;
int n, curtime = 0;
set<pair<int, int> > st[4][N];
set<pair<int, int> >::iterator it[4], it1;
int a[4][N], Max[4];
void Add(int x, int cur) {
  for (int i = 0; i < 4; i++)
    st[i][cur].insert({(i & 1 ? -1 : 1) * a[i][x], x});
}
void Del(int x, int cur) {
  for (int i = 0; i < 4; i++) st[i][cur].erase({(i & 1 ? -1 : 1) * a[i][x], x});
}
bool DaC(int cur) {
  int m = st[0][cur].size();
  if (m <= 2) return true;
  for (int i = 0; i < 4; i++) it[i] = st[i][cur].begin();
  Max[0] = Max[2] = 0;
  Max[1] = Max[3] = (int)1e9;
  for (int i = 1; i * 2 <= m; i++)
    for (int j = 0; j < 4; j++) {
      int k = j + (j & 1 ? -1 : 1);
      if (j & 1)
        minimize(Max[j], a[k][(*it[j]).second]);
      else
        maximize(Max[j], a[k][(*it[j]).second]);
      it[j]++;
      if ((j & 1 ? a[j][(*it[j]).second] <= Max[j]
                 : a[j][(*it[j]).second] >= Max[j])) {
        curtime++;
        for (it1 = st[j][cur].begin(); it1 != it[j]; it1++)
          Add((*it1).second, curtime);
        for (it1 = st[j][curtime].begin(); it1 != st[j][curtime].end(); it1++)
          Del((*it1).second, cur);
        if (!DaC(curtime)) return false;
        return DaC(cur);
      }
    }
  return false;
}
int main() {
  if (fopen("exam.inp", "r"))
    freopen("exam.inp", "r", stdin), freopen("exam.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d%d", &a[0][i], &a[2][i], &a[1][i], &a[3][i]);
    Add(i, 0);
  }
  puts(DaC(0) ? "YES" : "NO");
}
