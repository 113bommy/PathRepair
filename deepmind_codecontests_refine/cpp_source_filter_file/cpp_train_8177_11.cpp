#include <bits/stdc++.h>
using namespace std;
int N, M;
class line {
 public:
  int x, y;
} P[500010];
bitset<4000> a[2000];
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= M; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    a[x][y] = 1;
    P[i].x = x;
    P[i].y = y;
  }
  for (int i = 0; i < N; i++) a[i][N + i] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++)
      if (a[j][i]) {
        swap(a[j], a[i]);
        break;
      }
    for (int j = 0; j < N; j++)
      if (j != i && a[j][i]) a[j] ^= a[i];
  }
  for (int i = 1; i <= M; i++)
    if (a[P[i].x][N + P[i].y])
      printf("NO\n");
    else
      printf("YES\n");
}
