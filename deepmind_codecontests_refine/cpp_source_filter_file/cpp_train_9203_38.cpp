#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  vector<int> vec[4];
  scanf("%d", &n);
  for (int i = 0; i < 4; i++) {
    for (int y = 0; y < 4; y++) {
      scanf("%d", &m);
      vec[i].push_back(m);
    }
  }
  int guard, cost1, cost2;
  bool found = false;
  for (int i = 0; i < 4; i++) {
    for (int y = 0; y < 2; y++) {
      for (int j = 2; j < 4; j++) {
        if (vec[i][y] + vec[i][j] <= n) {
          found = true;
          guard = i + 1;
          cost1 = vec[i][y];
          cost2 = vec[i][j];
          break;
        }
      }
      if (found) break;
    }
    if (found) break;
  }
  if (!found) {
    puts("-1");
  } else {
    if (cost1 + cost2 == n)
      printf("%d %d %d\n", guard, cost1, cost2);
    else
      printf("%d %d %d\n", guard, cost1, n - cost2);
  }
  return 0;
}
