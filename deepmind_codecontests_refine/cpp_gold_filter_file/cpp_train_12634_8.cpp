#include <bits/stdc++.h>
using namespace std;
vector<int> e[100001];
int main(void) {
  int n;
  scanf("%d", &n);
  printf("%d\n", n - 1);
  for (int i = 1; i < n; ++i) {
    int j, k;
    scanf("%d %d", &j, &k);
    printf("2 %d %d\n", j, k);
    e[j].push_back(i);
    e[k].push_back(i);
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j < (int)e[i].size(); ++j)
      printf("%d %d\n", e[i][j - 1], e[i][j]);
  return 0;
}
