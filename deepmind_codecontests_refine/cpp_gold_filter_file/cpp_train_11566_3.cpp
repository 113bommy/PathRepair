#include <bits/stdc++.h>
using namespace std;
vector<int> g;
int main() {
  int n;
  int ans = 1;
  scanf("%d", &n);
  int x;
  scanf("%d", &x);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    if (x == 1) {
      g.push_back(ans);
      ans = x;
    } else
      ans = x;
  }
  if (x > 1) g.push_back(x);
  printf("%d\n", g.size());
  for (int i = 0; i < g.size(); i++) {
    printf("%d ", g[i]);
  }
  printf("\n");
  return 0;
}
