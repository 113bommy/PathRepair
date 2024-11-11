#include <bits/stdc++.h>
using namespace std;
const int N = 1234;
int a[N][N];
vector<int> r[N], c[N];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
      r[i].push_back(a[i][j]);
      c[j].push_back(a[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    sort(r[i].begin(), r[i].end());
    r[i].erase(unique(r[i].begin(), r[i].end()), r[i].end());
  }
  for (int i = 0; i < m; i++) {
    sort(c[i].begin(), c[i].end());
    c[i].erase(unique(c[i].begin(), c[i].end()), c[i].end());
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int p1 = lower_bound(r[i].begin(), r[i].end(), a[i][j]) - r[i].begin();
      int p2 = lower_bound(c[i].begin(), c[i].end(), a[i][j]) - c[i].begin();
      int p3 = r[i].end() - lower_bound(r[i].begin(), r[i].end(), a[i][j]);
      int p4 = c[i].end() - lower_bound(c[i].begin(), c[i].end(), a[i][j]);
      printf("%d", max(p1, p2) + max(p3, p4));
      if (j == m - 1)
        printf("\n");
      else
        printf(" ");
    }
  }
  return 0;
}
