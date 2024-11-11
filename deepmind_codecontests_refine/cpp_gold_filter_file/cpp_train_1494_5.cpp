#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;
const int N = 200100;
vector<int> cols[100100];
int main() {
  int n, m, k;
  while (~scanf("%d%d%d", &n, &m, &k)) {
    for (int i = 1; i <= m; ++i) {
      cols[i].clear();
    }
    int val;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &val);
      cols[val].push_back(i);
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
      int cnt = cols[i].size();
      int s = 0;
      int e = s;
      int num = 0;
      while (1) {
        while (e < cnt && num <= k) {
          ++e;
          if (e >= cnt) {
            break;
          }
          num += cols[i][e] - cols[i][e - 1] - 1;
        }
        ans = max(ans, e - s);
        if (e >= cnt) {
          break;
        }
        ++s;
        num -= cols[i][s] - cols[i][s - 1] - 1;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
