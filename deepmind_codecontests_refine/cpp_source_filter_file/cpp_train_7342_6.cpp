#include <bits/stdc++.h>
using namespace std;
int a[1005];
map<int, int> mm;
vector<int> vv;
int main() {
  int n, i, zero, ans, j, k, x, y, tmp, cnt;
  while (scanf("%d", &n) != EOF) {
    zero = 0;
    mm.clear();
    for (i = 0; i < n; i++) {
      scanf("%d", &a[i]);
      mm[a[i]]++;
      if (a[i] == 0) zero++;
    }
    sort(a, a + n);
    ans = 2;
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (i == j) continue;
        if (a[i] == 0 && a[j] == 0) continue;
        vv.clear();
        x = a[i], y = a[j];
        vv.push_back(x);
        mm[x]--;
        vv.push_back(y);
        mm[y]--;
        cnt = 2;
        while (x + y < a[n - 1] && mm[x + y]) {
          tmp = x, x = y, y += tmp;
          vv.push_back(y);
          mm[y]--;
          cnt++;
        }
        for (k = 0; k < vv.size(); k++) mm[vv[k]]++;
        ans = max(ans, cnt);
      }
    }
    printf("%d\n", max(ans, zero));
  }
  return 0;
}
