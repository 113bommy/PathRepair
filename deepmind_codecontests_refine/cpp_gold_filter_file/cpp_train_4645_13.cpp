#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, o = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch == '-' ? o = -1 : 0, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return o * x;
}
int dep[500000], anc[500000][30];
inline void init(int x, int fa) {
  dep[x] = dep[fa] + 1, anc[x][0] = fa;
  for (register int i = 1; i <= (int)(log(dep[x]) / log(2) + 1); i++)
    anc[x][i] = anc[anc[x][i - 1]][i - 1];
}
int LCA(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  for (int i = (int)(log(dep[x] - dep[y]) / log(2) + 1); i >= 0; i--)
    if (dep[anc[x][i]] >= dep[y]) x = anc[x][i];
  for (int i = (int)(log(dep[x]) / log(2) + 1); i >= 0; i--)
    if (anc[x][i] != anc[y][i]) x = anc[x][i], y = anc[y][i];
  return (x == y) ? x : anc[x][0];
}
inline int getDist(const int &x, const int &y) {
  return (dep[x] + dep[y] - (dep[LCA(x, y)] << 1));
}
vector<int> s1, s2;
int main() {
  int n = read() + 1;
  init(1, 0);
  s1.push_back(1);
  int maxd = 0;
  for (int i = 2; i <= n; i++) {
    init(i, read());
    int d1 = s1.empty() ? 0 : getDist(i, s1[0]);
    int d2 = s2.empty() ? 0 : getDist(i, s2[0]);
    if (max(d1, d2) > maxd) {
      maxd = max(d1, d2);
      if (maxd == d1) {
        for (register int j = 0; j < s2.size(); j++)
          if (getDist(s2[j], i) == d1) s1.push_back(s2[j]);
        s2.clear();
      } else {
        for (register int j = 0; j < s1.size(); j++)
          if (getDist(s1[j], i) == d2) s2.push_back(s1[j]);
        s1.clear();
      }
    }
    if (max(d1, d2) == maxd) {
      if (maxd == d1)
        s2.push_back(i);
      else
        s1.push_back(i);
    }
    cout << (s1.size() + s2.size()) << endl;
  }
  return 0;
}
