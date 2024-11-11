#include <bits/stdc++.h>
using namespace std;
const int maxm = 1e5 + 10;
int x[3000], y[3000];
int sumx[100], sumy[100];
int vis[300][3000];
int main() {
  int a1, a2, b1, b2, c1, c2;
  scanf("%d%d%d%d%d%d", &a1, &a2, &b1, &b2, &c1, &c2);
  printf("3\n");
  printf("%d %d\n", b1 + c1 - a1, b2 + c2 - a2);
  printf("%d %d\n", a1 + b1 - c1, a2 + b2 - c2);
  printf("%d %d\n", a1 + c1 - b1, a2 + c2 - b2);
}
