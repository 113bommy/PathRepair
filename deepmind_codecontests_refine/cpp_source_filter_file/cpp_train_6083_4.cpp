#include <bits/stdc++.h>
using namespace std;
vector<int> *v;
int main() {
  int t, i, j, k, n, p;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &p);
    k = 2 * n + p;
    for (i = 1; i < n && k > 0; i++) {
      for (j = i + 1; j <= n && k > 0; j++) {
        printf("%d %d\n", i, j);
        k--;
      }
    }
    return 0;
  }
}
