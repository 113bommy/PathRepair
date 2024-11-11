#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, l, m, n, z;
  scanf("%d", &n);
  vector<vector<int> > best;
  for (int s = 2; s < 100; s++) {
    int m = s;
    vector<vector<int> > curr;
    vector<int> first;
    for (int i = 0; i < s; i++) first.push_back(i + 1);
    int x = s + 1;
    curr.push_back(first);
    for (int r = 1; r < s + 1; r++) {
      vector<int> c;
      for (int j = 0; j < r; j++) {
        c.push_back(curr[j][r - 1]);
      }
      for (int j = 0; j < s - r; j++) {
        m = max(m, x);
        c.push_back(x++);
      }
      curr.push_back(c);
    }
    if (m <= n) {
      best = curr;
    } else
      break;
  }
  printf("%d\n", best.size());
  for (int i = 0; i < best.size(); i++) {
    for (int j = 0; j < best[i].size(); j++) printf("%d ", best[i][j]);
    printf("\n");
  }
  return 0;
}
