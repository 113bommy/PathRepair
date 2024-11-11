#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
map<pair<int, int>, int> MP;
int chk(int i, int j) {
  if (MP[{i, j}]) return MP[{i, j}] == +1;
  ++cnt;
  assert(cnt <= 60LL);
  printf("? %d %d\n", i, j);
  fflush(stdout);
  char ans[1];
  scanf("%s", ans);
  if (ans[0] == 'y')
    MP[{i, j}] = +1;
  else
    MP[{i, j}] = -1;
  return ans[0] == 'y';
}
int find(int l, int r) {
  int ans = -1;
  r = min(r, 2000000000);
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (!chk(mid, min(2000000000, mid + mid)))
      l = mid + 1, ans = mid;
    else
      r = mid - 1;
  }
  return ans;
}
int32_t main() {
  char str[10];
  while (scanf("%s", str) && str[0] == 's') {
    cnt = 0;
    MP.clear();
    if (!chk(1, 2)) {
      if (chk(2, 1))
        printf("! 2\n");
      else
        printf("! 1\n");
      fflush(stdout);
      continue;
    }
    int l = 1, r = 1;
    while (chk(r, r + r)) {
      l = r;
      r += r;
    }
    l = r;
    r += r;
    int p = find(l, r);
    printf("! %d\n", p);
    fflush(stdout);
  }
  return 0;
}
