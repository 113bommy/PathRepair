#include <bits/stdc++.h>
using namespace std;
int N, answer;
int X_axe[2010], Y_axe[2010];
bool is_triangle(int x1, int y1, int x2, int y2, int x3, int y3) {
  return (((x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3)) != 0);
}
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d%d", &X_axe[i], &Y_axe[i]);
  for (int i = 0; i < N - 2; i++)
    for (int j = i + 1; j < N - 1; j++)
      for (int k = i + 1; k < N; k++)
        if (is_triangle(X_axe[i], Y_axe[i], X_axe[j], Y_axe[j], X_axe[k],
                        Y_axe[k]))
          ++answer;
  printf("%d\n", answer);
  return 0;
}
