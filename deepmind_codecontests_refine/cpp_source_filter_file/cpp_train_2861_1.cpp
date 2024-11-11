#include <bits/stdc++.h>
using namespace std;
struct mycmp {
  bool operator()(const pair<int, int>& u, const pair<int, int>& v) {
    if (u.first != v.first) return u.first > v.first;
    return u.second < v.second;
  }
};
set<pair<int, int>, mycmp> se;
int res[20005];
int n, m, t, maxId;
int toNum(int hh, int mm, int ss) { return 3600 * hh + 60 * mm + ss; }
int getId() {
  int id = ++maxId;
  return id;
}
int main() {
  scanf("%d%d%d", &n, &m, &t);
  bool okM = false;
  for (int i = 0; i < n; i++) {
    int hh, mm, ss;
    scanf("%d:%d:%d", &hh, &mm, &ss);
    int T = toNum(hh, mm, ss);
    while (!se.empty()) {
      pair<int, int> u = *se.begin();
      if (u.first + t - 1 < T) {
        se.erase(se.begin());
      } else
        break;
    }
    if ((int)se.size() < m) {
      int id = getId();
      se.insert(pair<int, int>(T, id));
      res[i] = id;
      if (se.size() == m) okM = true;
    } else {
      pair<int, int> u = *se.begin();
      se.erase(se.begin());
      se.insert(pair<int, int>(T, u.second));
      res[i] = u.second;
    }
  }
  if (!okM)
    puts("No solution");
  else {
    printf("%d\n", maxId);
    for (int i = 0; i < n; i++) printf("%d\n", res[i]);
  }
  return 0;
}
