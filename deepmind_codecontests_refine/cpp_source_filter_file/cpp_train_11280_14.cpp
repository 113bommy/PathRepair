#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000000;
const int maxn = 105;
vector<int> an;
int main() {
  int n, m, k;
  int a, b;
  int i, j;
  while (scanf("%d%d%d", &n, &m, &k) != -1) {
    an.clear();
    for (i = 0; i < k; i++) an.push_back(1);
    int ans = k;
    int now = 0;
    if (k == 1) {
      while (1) {
        an.push_back(now + n);
        now += n - 1;
        ans += k;
        if (now >= m + 1) break;
      }
    } else {
      while (1) {
        an.push_back(now + n);
        for (j = 1; j < k; j++) an.push_back(now + n + 1);
        now += n;
        ans += k;
        if (now >= m) break;
      }
      if (now == m) {
        ans++;
        an.push_back(now - 1 + n);
      }
    }
    printf("%d\n", ans);
    for (i = 0; i < an.size(); i++) {
      if (i) printf(" ");
      printf("%d", an[i]);
    }
    puts("");
  }
  return 0;
}
