#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200100;
int main() {
  int n = 0, u = 0, v = 0;
  int d[MAXN] = {0};
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d %d", &u, &v);
    d[u] += 1;
    d[v] += 1;
  }
  for (int i = 0; i < n; i++) {
    if (d[i] == 2) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  return 0;
}
