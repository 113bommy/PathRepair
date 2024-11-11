#include <bits/stdc++.h>
using namespace std;
set<int> v, cover;
int res = 0, n = 0;
void bfs(set<int> &last, int cur) {
  set<int> next;
  for (auto val : last) {
    for (auto add : v) {
      int tmp = val + add;
      if (tmp == 0) {
        res = cur + 1;
        return;
      }
      if (tmp > 1000 || tmp < -1000 || cover.count(tmp)) {
        continue;
      }
      next.insert(tmp);
      cover.insert(tmp);
    }
  }
  bfs(next, cur + 1);
}
int main() {
  int k = 0, a = 0;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < k; ++i) {
    scanf("%d", &a);
    a -= n;
    v.insert(a);
    cover.insert(a);
  }
  if (*v.rbegin() < 0 || *v.begin() > 0) {
    printf("-1");
  } else if (v.count(0)) {
    printf("1");
  } else {
    bfs(v, 1);
  }
  printf("%d", res);
  return 0;
}
