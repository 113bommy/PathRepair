#include <bits/stdc++.h>
using namespace std;
typedef struct {
  int x, y;
} Point;
Point pts[505];
vector<pair<int, int> > rod;
bool used[505];
int ptrod[505];
int m;
int findrod(int n) {
  int i;
  for (i = 0; i < m; i++) {
    if (used[i]) continue;
    if (rod[i].first == n) {
      used[i] = true;
      return i;
    }
  }
  return -1;
}
bool solve(int a, int n) {
  memset(used, false, sizeof(used));
  memset(ptrod, -1, sizeof(ptrod));
  int dif, i, prev, nxt, ind;
  for (i = a + 1; i < n; i += 2) {
    dif = 0;
    prev = (i + n - 1) % n;
    nxt = (i + 1) % n;
    dif = abs(pts[i].x - pts[prev].x) + abs(pts[i].y - pts[prev].y);
    dif = dif + abs(pts[i].x - pts[nxt].x) + abs(pts[i].y - pts[nxt].y);
    ind = findrod(dif);
    if (ind == -1) break;
    ptrod[i] = rod[ind].second + 1;
  }
  if (i < n) return false;
  return true;
}
int main() {
  int n;
  int i, j, tmp;
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%d %d", &pts[i].x, &pts[i].y);
  }
  rod.clear();
  for (i = 0; i < m; i++) {
    scanf("%d", &tmp);
    rod.push_back(make_pair(tmp, i));
  }
  sort(rod.begin(), rod.end());
  bool flag = solve(-1, n);
  if (!flag) {
    solve(0, n);
    if (!flag)
      printf("NO\n");
    else {
      printf("YES\n");
      for (i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", ptrod[i]);
      }
      printf("\n");
    }
  } else {
    printf("YES\n");
    for (i = 0; i < n; i++) {
      if (i > 0) printf(" ");
      printf("%d", ptrod[i]);
    }
    printf("\n");
  }
  return 0;
}
