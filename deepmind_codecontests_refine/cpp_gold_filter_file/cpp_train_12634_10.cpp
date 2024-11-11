#include <bits/stdc++.h>
using namespace std;
vector<int> a[100010];
int main() {
  int n;
  scanf("%d", &n);
  printf("%d\n", n - 1);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    printf("2 %d %d\n", x, y);
    a[x].push_back(i);
    a[y].push_back(i);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < a[i].size() - 1; ++j)
      printf("%d %d\n", a[i][j] + 1, a[i][j + 1] + 1);
  }
  return 0;
}
