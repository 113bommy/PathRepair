#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
vector<int> adjList[505];
char node[505];
void dfs(int x) {
  for (int i = 0; i < n; i++) {
    if (x == i) continue;
    if (node[i] != '-') continue;
    if (find(adjList[x].begin(), adjList[x].end(), i) == adjList[x].end()) {
      if (node[x] == 'a') {
        node[i] = 'c';
      } else {
        node[i] = 'a';
      }
      dfs(i);
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &x, &y);
    x--;
    y--;
    adjList[x].push_back(y);
    adjList[y].push_back(x);
  }
  memset(node, '-', sizeof(node));
  for (int i = 0; i < n; i++) {
    sort(adjList[i].begin(), adjList[i].end());
  }
  for (int i = 0; i < n; i++) {
    if (adjList[i].size() == n - 1) {
      node[i] = 'b';
    }
  }
  for (int i = 0; i < n; i++) {
    if (node[i] == '-') {
      node[i] = 'a';
      dfs(i);
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (find(adjList[i].begin(), adjList[i].end(), j) == adjList[i].end()) {
        if (node[i] == 'a' && node[j] == 'c') {
        } else if (node[i] == 'c' && node[j] == 'a') {
        } else {
          printf("No\n");
          return 0;
        }
      } else {
        if (node[i] == 'a' && node[j] == 'c') {
          printf("No\n");
          return 0;
        } else if (node[i] == 'c' && node[j] == 'a') {
          printf("No\n");
          return 0;
        } else {
        }
      }
    }
  }
  printf("Yes\n");
  for (int i = 0; i < n; i++) {
    printf("%c", node[i]);
  }
  printf("\n");
}
