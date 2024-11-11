#include <bits/stdc++.h>
using namespace std;
int G[1003][1003];
vector<int> v;
int main() {
  int N, M, K;
  int i, u, v;
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 0; i < K; i++) {
    scanf("%d%d", &u, &v);
    G[u][v] = 1;
    if (G[u][v] == 1 && G[u - 1][v] && G[u - 1][v - 1] && G[u][v - 1]) {
      printf("%d\n", i + 1);
      break;
    }
    if (G[u][v] == 1 && G[u - 1][v] && G[u - 1][v + 1] && G[u][v + 1]) {
      printf("%d\n", i + 1);
      break;
    }
    if (G[u][v] == 1 && G[u + 1][v] && G[u + 1][v - 1] && G[u][v - 1]) {
      printf("%d\n", i + 1);
      break;
    }
    if (G[u][v] == 1 && G[u + 1][v] && G[u + 1][v + 1] && G[u][v + 1]) {
      printf("%d\n", i + 1);
      break;
    }
  }
  if (i == K) printf("0\n");
  return 0;
}
