#include <bits/stdc++.h>
using namespace std;
int n, t, m;
int a[200050];
vector<int> r[200050];
vector<int> q[200050];
int main() {
  scanf("%d%d%d", &n, &t, &m);
  for (int i = 1; i <= t; i++) scanf("%d", &a[i]);
  int tot = 1;
  r[0].push_back(1);
  for (int i = 1; i <= t; i++) {
    for (int j = 0; j < a[i]; j++) {
      tot++;
      r[i].push_back(tot);
    }
  }
  q[1].push_back(2);
  for (int i = 1; i < t; i++) {
    q[r[i][0]].push_back(r[i + 1][0]);
  }
  int minn = 1;
  int maxx = 1;
  a[t + 1] = 1;
  for (int i = 1; i <= t; i++) {
    maxx += (a[i] - 1);
    minn += (max(a[i] - a[i + 1], 0));
  }
  if (m < minn || m > maxx) {
    printf("-1\n");
    return 0;
  }
  m -= minn;
  for (int i = 1; i <= t; i++) {
    for (int j = 1; j < r[i].size(); j++) {
      int k = j + 1;
      if (k > a[i - 1]) {
        q[r[i - 1][0]].push_back(r[i][j]);
      } else {
        if (m > 0) {
          m--;
          q[r[i - 1][j]].push_back(r[i][j]);
        } else {
          q[r[i - 1][0]].push_back(r[i][j]);
        }
      }
    }
  }
  printf("%d\n", n);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < q[i].size(); j++) {
      printf("%d %d\n", i, q[i][j]);
    }
  }
}
