#include <bits/stdc++.h>
using namespace std;
vector<int> q[3111];
int d[3333][3333];
long long com(int n) {
  long long ans = 1;
  ans = n * n - 1;
  ans /= 2;
  return ans;
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    q[x].push_back(y);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < q[i].size(); j++) {
      for (int k = 0; k < q[q[i][j]].size(); k++) {
        d[i][q[q[i][j]][k]] += 1;
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i != j) {
        ans += com(d[i][j]);
      }
    }
  }
  printf("%d", ans);
}
