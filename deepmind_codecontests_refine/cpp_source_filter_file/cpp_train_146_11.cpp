#include <bits/stdc++.h>
using namespace std;
const double INF = 0x7ffffff;
const int N = 250;
int n, a[N];
int main() {
  ios::sync_with_stdio(false);
  while (scanf("%d", &n) != EOF) {
    int tot = 0;
    int t1 = 0, t2 = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      tot += a[i] / 100;
      if (a[i] == 100)
        t1++;
      else
        t2++;
    }
    if (tot % 2 || (t2 == 1 && t1 == 0))
      puts("NO");
    else {
      puts("YES");
    }
  }
  return 0;
}
