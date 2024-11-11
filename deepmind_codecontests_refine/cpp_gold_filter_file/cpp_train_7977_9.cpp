#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, u, flag = 0, j, ctr = 0;
  scanf("%d", &n);
  vector<int> graph[n + 1];
  for (i = 1; i < n; i++) {
    scanf("%d", &u);
    graph[u].push_back(i + 1);
  }
  for (i = 1; i <= n; i++) {
    if (graph[i].size() != 0) {
      ctr = 0;
      for (j = 0; j < graph[i].size(); j++) {
        int k = graph[i][j];
        if (graph[k].size() == 0) {
          ctr++;
        }
      }
      if (ctr < 3) {
        flag = 1;
        break;
      }
    }
  }
  if (flag == 1) {
    printf("NO\n");
  } else {
    printf("YES\n");
  }
  return 0;
}
