#include <bits/stdc++.h>
const long long oo = (long long)1e18;
using namespace std;
pair<int, int> cost[102];
int x[102], y[102], z[102], t[102];
int main() {
  int n;
  scanf("%i", &n);
  for (int i = (1); i <= (n); i++)
    scanf("%i %i %i %i", &x[i], &y[i], &z[i], &t[i]);
  int m = 0;
  for (int i = (1); i <= (n); i++) {
    bool ok = true;
    for (int j = (1); j <= (n); j++)
      if (x[j] > x[i] && y[j] > y[i] && z[j] > z[i]) {
        ok = false;
        break;
      }
    if (ok) {
      m++;
      cost[m] = make_pair(t[i], i);
    }
  }
  sort(cost + 1, cost + m + 1);
  printf("%i\n", cost[1].second);
  return 0;
}
