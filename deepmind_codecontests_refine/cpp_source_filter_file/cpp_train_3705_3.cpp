#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int INF = 1e8;
vector<int> ans, a, b;
int pos;
inline int query(int x, int y) {
  printf("0 %d %d\n", x, y);
  fflush(stdout);
  scanf("%d", &x);
  return x;
}
inline void Solve(int l, int r) {
  if (l > r) return;
  int Mid = l + r >> 1, val = query(Mid, Mid);
  if (!val) {
    ans.push_back(val);
    val = 1;
  } else
    pos = Mid;
  Solve(l, Mid - val);
  Solve(Mid + val, r);
}
int main() {
  Solve(-INF, INF);
  for (auto it : ans) {
    if (query(it, pos) == 0) a.push_back(it);
    if (query(pos, it) == 0) b.push_back(it);
  }
  printf("1 %d %d\n", a.size(), b.size());
  for (auto it : a) printf("%d ", it);
  puts("");
  for (auto it : b) printf("%d ", it);
  puts("");
  return 0;
}
