#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const double PI = acos(-1.0);
const int N = 10;
int ma[N][N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) scanf("%d", &ma[i][j]);
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 4; k++)
        for (int l = 2; l < 4; l++)
          if (ma[i][j] + ma[k][l] == n && ma[k][l] >= ma[i][l] &&
              ma[i][j] + ma[i][l] <= n) {
            printf("%d %d %d\n", i + 1, ma[i][j], ma[k][l]);
            return 0;
          }
  puts("-1");
  return 0;
}
