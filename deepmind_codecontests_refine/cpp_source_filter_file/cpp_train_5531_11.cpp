#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
vector<int> V[N];
int sol1[N], sol2[N];
int n, m, a, b, cnt1 = 1, cnt2 = 2, st = 1, ok = 0;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &a, &b);
    V[a].push_back(b);
    V[b].push_back(a);
  }
  int cur = 1;
  for (int i = 1; i <= n && !ok; i++) {
    cur = 1;
    if (V[i].size() != n - 1) {
      sort(V[i].begin(), V[i].end());
      for (int j = 0; j < V[i].size(); j++) {
        if (cur == i) cur++;
        if (cur != V[i][j]) {
          cnt1 = i;
          cnt2 = cur;
          ok = 1;
          break;
        }
        cur++;
      }
      if (!ok) {
        cnt1 = i;
        cnt2 = cur;
        if (cur == cnt1) cur++;
        ok = 1;
      }
    }
  }
  if (!ok) {
    printf("NO");
    return 0;
  }
  printf("YES\n", cnt1, cnt2);
  if (cnt1 > cnt2) swap(cnt1, cnt2);
  int lol = 1;
  for (int i = 1; i <= n; i++) {
    if (cnt1 == i) {
      printf("%d ", n);
      continue;
    }
    if (cnt2 == i) {
      printf("%d ", n - 1);
      continue;
    }
    printf("%d ", lol++);
  }
  printf("\n");
  lol = 1;
  for (int i = 1; i <= n; i++) {
    if (cnt1 == i || cnt2 == i) {
      printf("%d ", n);
      continue;
    }
    printf("%d ", lol++);
  }
  return 0;
}
