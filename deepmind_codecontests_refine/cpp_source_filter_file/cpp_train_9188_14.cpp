#include <bits/stdc++.h>
using namespace std;
int query(int x, int y) {
  printf("? %d %d\n", x, y);
  fflush(stdout);
  int mod;
  scanf("%d", &mod);
  return mod;
}
int main() {
  int n;
  scanf("%d", &n);
  set<int> unknown;
  for (int i = 0; i < n; i++) unknown.insert(i);
  int ans[n];
  while (unknown.size() > 1) {
    int x = *(unknown.begin());
    int y = *(unknown.rbegin());
    int qxy = query(x, y);
    int qyx = query(y, x);
    if (qxy > qyx) {
      ans[x] = qxy;
      unknown.erase(x);
    } else {
      ans[y] = qyx;
      unknown.erase(y);
    }
  }
  ans[*(unknown.begin())] = n;
  printf("! ");
  for (int i = 0; i < n; i++) {
    printf("%d ", ans[i]);
  }
  cout << endl;
}
