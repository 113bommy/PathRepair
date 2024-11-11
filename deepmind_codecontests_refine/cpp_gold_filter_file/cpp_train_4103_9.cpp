#include <bits/stdc++.h>
using namespace std;
int a[1010];
vector<int> b[1010];
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d%d", &x, &a[i]);
    b[x].push_back(i);
  }
  int sum = 0;
  for (int i = 1; i <= m; i++) {
    int MIN = 2000000000;
    for (int j = 0; j < b[i].size(); j++) MIN = min(MIN, a[b[i][j]]);
    sum += MIN;
  }
  printf("%d", min(sum, k));
}
