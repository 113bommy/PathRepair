#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 10;
const int INF = 1e18 + 10;
int a[1000];
int main(int argc, char const *argv[]) {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d %d", &n, &m);
    int max1 = 0;
    for (int i = 1; i <= m; i++) {
      scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + m);
    for (int i = 2; i <= m; i++) {
      max1 = max(max1, (abs(a[i] - a[i - 1] + 2) / 2));
    }
    max1 = max(max1, a[1]);
    max1 = max(max1, n - a[m] + 1);
    printf("%d\n", max1);
  }
  return 0;
}
