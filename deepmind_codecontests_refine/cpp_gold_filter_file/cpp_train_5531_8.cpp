#include <bits/stdc++.h>
using namespace std;
const int mn = 1e5 + 10;
bool vis[mn];
vector<int> v[mn];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  while (m--) {
    int a, b;
    scanf("%d %d", &a, &b);
    if (a > b) swap(a, b);
    v[a].push_back(b);
  }
  int s = -1, e = -1;
  for (int i = 1; i <= n; i++) {
    int sz = v[i].size();
    if (sz >= n - i) continue;
    for (int j = 0; j < sz; j++) vis[v[i][j]] = 1;
    for (int j = i + 1; j <= n; j++)
      if (!vis[j]) {
        s = i, e = j;
        break;
      }
    break;
  }
  if (s == -1)
    printf("NO\n");
  else {
    printf("YES\n");
    int t = 2;
    for (int i = 1; i <= n; i++) {
      if (i == s)
        printf("1 ");
      else if (i == e)
        printf("2 ");
      else
        printf("%d ", ++t);
    }
    printf("\n");
    t = 2;
    for (int i = 1; i <= n; i++) {
      if (i == s || i == e)
        printf("1 ");
      else
        printf("%d ", ++t);
    }
    printf("\n");
  }
  return 0;
}
