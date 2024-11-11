#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 10;
int gi() {
  int x = 0, o = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
int n, k;
struct scc {
  int sz, mx[20], mn[20];
  bool operator<(const scc &A) const {
    for (int i = 1; i <= k; i++)
      if (mx[i] > A.mn[i]) return 0;
    return 1;
  }
};
set<scc> s;
int main() {
  n = gi(), k = gi();
  for (int i = 1; i <= n; i++) {
    scc cur;
    cur.sz = 1;
    for (int j = 1; j <= k; j++) cur.mx[j] = cur.mn[j] = gi();
    auto it = s.find(cur);
    while (it != s.end()) {
      cur.sz += it->sz;
      for (int j = 1; j <= k; j++)
        cur.mx[j] = max(cur.mx[j], it->mx[j]),
        cur.mn[j] = min(cur.mn[j], it->mn[j]);
      s.erase(it);
      it = s.find(cur);
    }
    s.insert(cur);
    printf("%d\n", s.rbegin()->sz);
  }
  return 0;
}
