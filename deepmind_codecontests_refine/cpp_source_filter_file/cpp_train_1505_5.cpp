#include <bits/stdc++.h>
using namespace std;
int n, m;
int first[1000001], p[1000001], a[1000001], b[1000001];
int main() {
  cin >> n;
  for (int k = 1; k <= n; ++k) {
    scanf("%d", &p[k]);
    ;
    int x;
    for (x = k + 1; x != 1; x = p[x]) {
      int y = max(a[x], b[x] + 1);
      if (y <= first[x]) break;
      first[x] = y;
      if (y > a[p[x]])
        a[p[x]] = y;
      else if (y > b[p[x]])
        b[p[x]] = y;
    }
    printf("%d ", max(a[1], b[1]));
    ;
  }
  return 0;
}
