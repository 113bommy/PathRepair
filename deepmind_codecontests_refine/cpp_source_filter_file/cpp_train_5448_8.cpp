#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
int n, m;
int a[MAXN], b[MAXN];
int pos[MAXN];
int main(int argc, char *argv[]) {
  scanf("%d%d", &n, &m);
  memset(pos, -1, sizeof(pos));
  for (int i = 0, _i = n; i < _i; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 0, _i = m; i < _i; ++i) {
    scanf("%d", b + i);
    pos[b[i]] = i;
  }
  deque<int> dq;
  int ans = 0;
  for (int i = 0, _i = 2 * n; i < _i; ++i) {
    int where = pos[a[i % n]];
    if (where == -1) {
      dq.clear();
    } else {
      while (dq.size() >= 2) {
        if (dq.back() > dq.front()) {
          if (where >= dq.front() && where <= dq.back()) {
            dq.pop_front();
          } else {
            break;
          }
        } else if (dq.front() > dq.back()) {
          if (where > dq.back() && where < dq.front()) {
            break;
          } else {
            dq.pop_front();
          }
        }
      }
      dq.push_back(where);
      ans = max(ans, (int)dq.size());
    }
  }
  printf("%d\n", ans);
  return 0;
}
