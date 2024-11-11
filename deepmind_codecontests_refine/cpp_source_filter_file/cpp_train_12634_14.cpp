#include <bits/stdc++.h>
using namespace std;
vector<int> gr[100010];
int main() {
  int n, u, v;
  scanf("%d", &n);
  printf("%d\n", n - 1);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d %d", &u, &v);
    --u;
    --v;
    printf("2 %d %d\n", u + 1, v + 1);
    gr[u].push_back(i);
    gr[v].push_back(i);
  }
  for (u = 0; u < n - 1; u++) {
    for (v = 0; v < gr[u].size() - 1; v++) {
      printf("%d %d\n", gr[u][v] + 1, gr[u][v + 1] + 1);
    }
  }
  return 0;
}
