#include <bits/stdc++.h>
using namespace std;
int const INF = 1e9 + 9;
int main() {
  int ans = 0;
  int R, C;
  scanf("%d %d", &R, &C);
  for (int r = 0; r < R; r++) {
    int mini = INF;
    for (int r = 0; r < R; r++) {
      int tmp;
      scanf("%d", &tmp);
      mini = min(mini, tmp);
    }
    ans = max(ans, mini);
  }
  printf("%d\n", ans);
}
