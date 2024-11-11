#include <bits/stdc++.h>
using namespace std;
int n, m, arr[100000 + 10] = {0};
int main() {
  while (~scanf("%d %d", &n, &m)) {
    for (int i = 0; i < m; i++) {
      int u, v, c;
      scanf("%d %d %d", &u, &v, &c);
      arr[u] += c;
      arr[v] -= c;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
      if (arr[i] >= 0) sum += arr[i];
    printf("%d\n", sum);
  }
  return 0;
}
