#include <bits/stdc++.h>
using namespace std;
struct edge {
  int u, v;
  edge() {}
  edge(int k, int l) {
    u = k;
    v = l;
  }
};
vector<edge> edges;
int mat[110][110];
int main() {
  int i, j, k, l, n;
  scanf("%d", &n);
  if (n == 1) {
    printf("0\n");
    return 0;
  }
  if (n == 2) {
    printf("1\n1 2\n");
    return 0;
  }
  int currdis = 1;
  edge temp;
  temp = edge(1, 2);
  edges.push_back(temp);
  mat[1][2] = mat[2][1] = 1;
  int turn = 0;
  for (i = 3; i <= n; i++) {
    temp = edge(i, i - 1);
    edges.push_back(temp);
    mat[i][i - 1] = mat[i - 1][i] = 1;
    for (j = 1; j < i - 2; j++) {
      if (mat[j][i - 1]) continue;
      temp = edge(j, i);
      edges.push_back(temp);
      mat[j][i] = mat[i][j] = 1;
    }
  }
  printf("%d\n", edges.size());
  for (i = 0; i < edges.size(); i++) {
    printf("%d %d\n", edges[i].u, edges[i].v);
  }
  return 0;
}
