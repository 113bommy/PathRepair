#include <bits/stdc++.h>
using namespace std;
vector<int> v[1005];
int col1[1005];
int col2[1005];
int vis[1005];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int i, j, k, l, n;
    scanf("%d", &n);
    for (i = 0; i <= n; i++) {
      v[i].clear();
      col1[i] = 0;
      col2[i] = 0;
      vis[i] = 0;
    }
    int m = n - 1;
    while (m--) {
      scanf("%d%d", &i, &j);
      v[i].push_back(j);
      v[j].push_back(i);
    }
    int k1, k2;
    scanf("%d", &k1);
    for (i = 0; i < k1; i++) {
      scanf("%d", &j);
      col1[j] = 1;
    }
    scanf("%d", &k2);
    int x;
    for (i = 0; i < k2; i++) {
      scanf("%d", &j);
      col2[j] = 2;
      x = j;
    }
    printf("B %d\n", x);
    fflush(stdout);
    scanf("%d", &x);
    if (col1[x] == 1) {
      printf("C %d\n", x);
      fflush(stdout);
    } else {
      queue<int> q;
      q.push(x);
      while (!q.empty()) {
        i = q.front();
        q.pop();
        if (vis[i] == 1) continue;
        vis[i] = 1;
        if (col1[i] == 1) {
          x = i;
          break;
        }
        for (auto pk : v[i]) {
          if (vis[pk] == 1) continue;
          q.push(pk);
        }
      }
      printf("A %d\n", x);
      fflush(stdout);
      scanf("%d", &i);
      if (col2[i] == 2)
        printf("C %d\n", x);
      else
        printf("C -1\n");
      fflush(stdout);
    }
  }
}
