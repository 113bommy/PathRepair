#include <bits/stdc++.h>
using namespace std;
int p[50001], n, l, r;
queue<int> ver[50001];
void go(int pre, int v) {
  int t;
  p[v] = pre;
  if (v != l) {
    while (!ver[v].empty()) {
      t = ver[v].front();
      ver[v].pop();
      if (t != pre) go(v, t);
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &l, &r);
  l--;
  r--;
  for (int i = 0; i < n; i++)
    if (i == l)
      continue;
    else {
      scanf("%d", &p[i]);
      p[i]--;
      ver[p[i]].push(i);
      ver[i].push(p[i]);
    }
  go(-1, r);
  for (int i = 0; i < n; i++)
    if (i == r)
      continue;
    else
      printf("%d ", p[i] + 1);
  return 0;
}
