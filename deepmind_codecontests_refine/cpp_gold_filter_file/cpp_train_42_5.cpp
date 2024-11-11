#include <bits/stdc++.h>
using namespace std;
inline void pisz(int n) { printf("%d\n", n); }
template <typename T, typename TT>
ostream& operator<<(ostream& s, pair<T, TT> t) {
  return s << "(" << t.first << "," << t.second << ")";
}
template <typename T>
ostream& operator<<(ostream& s, vector<T> t) {
  for (int(i) = 0; (i) < (((int)((t).size()))); ++(i)) s << t[i] << " ";
  return s;
}
vector<int> p[100007], q[100007];
long long ha(int x, int y) { return 100005LL * (x + 1) + y; }
int main() {
  int res = 0;
  int(n);
  scanf("%d", &(n));
  unordered_set<long long> pts;
  for (int(i) = 0; (i) < (n); ++(i)) {
    int(x), (y);
    scanf("%d %d", &(x), &(y));
    pts.insert(ha(x, y));
    p[x].push_back(y);
  }
  const int SQ = sqrt(n);
  for (int(x) = (0); (x) <= (100000); ++x) {
    sort(p[x].begin(), p[x].end());
    if (((int)((p[x]).size())) > SQ) {
      for (__typeof(p[x].begin()) y = p[x].begin(); y != p[x].end(); y++)
        q[*y].push_back(x);
    } else {
      for (int(i) = 0; (i) < (((int)((p[x]).size()))); ++(i))
        for (int(j) = (i + 1); (j) <= (((int)((p[x]).size())) - 1); ++j) {
          int y1 = p[x][i], y2 = p[x][j];
          int d = y2 - y1;
          if (pts.count(ha(x - d, y1)) && pts.count(ha(x - d, y2))) ++res;
          if (pts.count(ha(x + d, y1)) && pts.count(ha(x + d, y2))) ++res;
        }
      for (__typeof(p[x].begin()) y = p[x].begin(); y != p[x].end(); y++)
        pts.erase(ha(x, *y));
    }
  }
  for (int(y) = (0); (y) <= (100000); ++y) {
    sort(q[y].begin(), q[y].end());
    for (int(i) = 0; (i) < (((int)((q[y]).size()))); ++(i))
      for (int(j) = (i + 1); (j) <= (((int)((q[y]).size())) - 1); ++j) {
        int x1 = q[y][i], x2 = q[y][j];
        int d = x2 - x1;
        if (pts.count(ha(x1, y - d)) && pts.count(ha(x2, y - d))) ++res;
        if (pts.count(ha(x1, y + d)) && pts.count(ha(x2, y + d))) ++res;
      }
    for (__typeof(q[y].begin()) x = q[y].begin(); x != q[y].end(); x++)
      pts.erase(ha(*x, y));
  }
  pisz(res);
}
