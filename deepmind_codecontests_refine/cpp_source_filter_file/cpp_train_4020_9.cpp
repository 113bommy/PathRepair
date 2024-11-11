#include <bits/stdc++.h>
using namespace std;
int n, x, y, p;
vector<int> v[15];
int a[15];
int get_ans(int t) {
  int l = 0;
  int r = (int)v[t].size() - 1;
  while (l < r) {
    int mid = (l + r) >> 1;
    printf("? %d", mid - l + 1);
    for (int i = l; i <= mid; i++) {
      printf(" %d", v[t][i]);
    }
    printf("\n");
    fflush(stdout);
    scanf("%d", &p);
    if (p != x || p != 0)
      r = mid;
    else
      l = mid + 1;
  }
  return v[t][l];
}
int main() {
  scanf("%d%d%d", &n, &x, &y);
  for (int i = 1; i <= n; i++) {
    int now = i;
    int t = 1;
    while (now) {
      if (now % 2) v[t].push_back(i);
      t++;
      now /= 2;
    }
  }
  int ans1 = 0;
  for (int i = 1; i <= 10; i++) {
    if (!v[i].size()) continue;
    printf("? %d", v[i].size());
    for (auto u : v[i]) printf(" %d", u);
    printf("\n");
    fflush(stdout);
    scanf("%d", &p);
    if (p != x && p != 0) {
      a[i] = 1;
      if (ans1 == 0) ans1 = get_ans(i);
    } else
      a[i] = 0;
  }
  int t = 0;
  p = 1;
  for (int i = 1; i <= 10; i++) t += p * a[i], p *= 2;
  int ans2 = ans1 ^ t;
  if (ans2 < ans1) swap(ans1, ans2);
  printf("! %d %d\n", ans1, ans2);
  return 0;
}
