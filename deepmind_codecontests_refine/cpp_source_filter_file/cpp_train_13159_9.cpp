#include <bits/stdc++.h>
using namespace std;
int main() {
  int c1, c2, c3, c4;
  scanf("%d%d%d%d", &c1, &c2, &c3, &c4);
  int n, m;
  scanf("%d%d", &n, &m);
  int buses[n], trolleys[n];
  for (int i = 0; i < n; i++) scanf("%d", buses + i);
  for (int i = 0; i < m; i++) scanf("%d", trolleys + i);
  int minOnBuses = 0, minOnTrolleys = 0;
  for (int i = 0; i < n; i++) minOnBuses += min(c2, c1 * buses[i]);
  for (int i = 0; i < m; i++) minOnTrolleys += min(c2, c1 * trolleys[i]);
  minOnBuses = min(minOnBuses, c3);
  minOnTrolleys = min(minOnTrolleys, c3);
  printf("%d\n", min(minOnBuses + minOnTrolleys, c4));
  return 0;
}
