#include <bits/stdc++.h>
using namespace std;
void fre() {
  freopen("c://test//input.in", "r", stdin);
  freopen("c://test//output.out", "w", stdout);
}
template <class T1, class T2>
inline void gmax(T1 &a, T2 b) {
  if (b > a) a = b;
}
template <class T1, class T2>
inline void gmin(T1 &a, T2 b) {
  if (b < a) a = b;
}
const int N = 4e5 + 10, M = 0, Z = 1e9 + 7, inf = 0x3f3f3f3f;
template <class T1, class T2>
inline void gadd(T1 &a, T2 b) {
  a = (a + b) % Z;
}
int casenum, casei;
int n, m;
int a[N];
int link[N];
int nxt[N];
struct node {
  int x;
  bool operator<(const node &b) const { return nxt[x] > nxt[b.x]; }
};
int main() {
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    memset(nxt, 63, sizeof(nxt));
    for (int i = n; i >= 1; --i) {
      link[i] = nxt[a[i]];
      nxt[a[i]] = i;
    }
    set<node> sot;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      int x = a[i];
      if (sot.count({x})) {
        sot.erase({x});
        nxt[x] = link[i];
        sot.insert({x});
      } else if (sot.size() < m) {
        nxt[x] = link[i];
        sot.insert({x});
        ++ans;
      } else {
        sot.erase(sot.begin());
        nxt[x] = link[i];
        sot.insert({x});
        ++ans;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
