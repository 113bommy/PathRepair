#include <bits/stdc++.h>
using namespace std;
int per[1000005];
pair<int, int> mx[1000005][2];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i <= n; i++) {
  }
  per[1] = -1;
  int all = 1;
  n++;
  for (int i = 2; i <= n; i++) {
    scanf("%d", &per[i]);
    int x = i;
    int z = 0;
    int pr = -1;
    while (x >= 1) {
      if ((z <= mx[x][0].first && mx[x][0].second) ||
          (!mx[x][0].second && z <= mx[x][1].first && mx[x][1].second == pr))
        break;
      if (pr != -1) {
        if (mx[x][0].second == pr) {
          mx[x][0] = make_pair(z, pr);
        } else if (mx[x][1].second == pr) {
          mx[x][1] = make_pair(z, pr);
        } else if (mx[x][0].first < z)
          mx[x][0] = make_pair(z, pr);
        else if (mx[x][1].first < z)
          mx[x][1] = make_pair(z, pr);
        sort(mx[x], mx[x] + 2);
      }
      pr = x;
      z = max(mx[x][1].first, mx[x][0].first + 1);
      x = per[x];
    }
    printf("%d ", mx[1][1].first);
  }
  return 0;
}
