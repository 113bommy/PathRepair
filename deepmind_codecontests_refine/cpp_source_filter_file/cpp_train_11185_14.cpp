#include <bits/stdc++.h>
using namespace std;
int NUM, AM;
char BUFFER[(1 << 16) + 1], *pNum = BUFFER;
template <class T>
void minimize(T &i, const T &j) {
  if (i > j) i = j;
}
template <class T>
void maximize(T &i, const T &j) {
  if (i < j) i = j;
}
int MAIN();
int main() { MAIN(); }
const int limit = 1000 + 5;
int a[limit][limit];
set<pair<int, int> > ngang[limit], doc[limit];
void merge(set<pair<int, int> > &d, int value) {
  auto ptren = d.lower_bound(pair<int, int>(value, value));
  auto pduoi = ptren;
  pair<int, int> duoi, tren, cc(pair<int, int>(value, value));
  if (pduoi != d.begin())
    pduoi--, duoi = *pduoi;
  else
    duoi = cc;
  if (ptren != d.end())
    tren = *ptren;
  else
    tren = cc;
  d.erase(tren);
  d.erase(duoi);
  if (duoi.second + 1 == cc.first)
    cc.first = duoi.first;
  else if (duoi.second < cc.first)
    d.insert(duoi);
  if (cc.second + 1 == tren.first)
    cc.second = tren.second;
  else if (tren.first > cc.second)
    d.insert(tren);
  d.insert(cc);
}
void split(set<pair<int, int> > &d, int value) {
  auto p = d.upper_bound(pair<int, int>(value, value));
  if (p == d.begin()) return;
  p--;
  auto duoi = pair<int, int>(p->first, value - 1);
  auto tren = pair<int, int>(value + 1, p->second);
  d.erase(p);
  if (duoi.first <= duoi.second) d.insert(duoi);
  if (tren.first <= tren.second) d.insert(tren);
}
void turnon(int x, int y) {
  merge(ngang[x], y);
  merge(doc[y], x);
}
void turnof(int x, int y) {
  split(ngang[x], y);
  split(doc[y], x);
}
void getvalue(set<pair<int, int> > &d, int value, int &Min, int &Max) {
  auto p = d.upper_bound(pair<int, int>(value, limit));
  if (p == d.begin()) {
    Min = Max + 1;
    return;
  }
  p--;
  if (p->first > value || p->second < value) {
    Min = Max + 1;
    return;
  }
  Min = max(Min, p->first);
  Max = min(Max, p->second);
}
int MAIN() {
  int m, n, k;
  scanf("%d%d%d", &m, &n, &k);
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j) {
      scanf("%d", &a[i][j]);
      if (a[i][j] == 1) turnon(i, j);
    }
  while (k--) {
    int opt, x, y;
    scanf("%d%d%d", &opt, &x, &y);
    if (opt == 1) {
      a[x][y] ^= 1;
      if (a[x][y] == 0)
        turnof(x, y);
      else
        turnon(x, y);
    } else {
      int area = 0;
      int Min, Max;
      Min = 0;
      Max = n + 1;
      for (int i = x; i <= m; ++i) {
        getvalue(ngang[i], y, Min, Max);
        if (Max - Min + 1 <= 0) break;
        area = max(area, (i - x + 1) * (Max - Min + 1));
      }
      Min = 0;
      Max = n + 1;
      for (int i = x; i >= 1; --i) {
        getvalue(ngang[i], y, Min, Max);
        if (Max - Min + 1 <= 0) break;
        area = max(area, (x - i + 1) * (Max - Min + 1));
      }
      Min = 0;
      Max = m + 1;
      for (int i = y; i <= m; ++i) {
        getvalue(doc[i], x, Min, Max);
        if (Max - Min + 1 <= 0) break;
        area = max(area, (i - y + 1) * (Max - Min + 1));
      }
      Min = 0;
      Max = m + 1;
      for (int i = y; i >= 1; --i) {
        getvalue(doc[i], x, Min, Max);
        if (Max - Min + 1 <= 0) break;
        area = max(area, (y - i + 1) * (Max - Min + 1));
      }
      printf("%d\n", area);
    }
  }
  return 0;
}
