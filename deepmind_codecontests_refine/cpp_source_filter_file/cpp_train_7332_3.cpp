#include <bits/stdc++.h>
using namespace std;
struct node {
  long long x, y, s;
} nd[1003];
bool cp(node a, node b) {
  return a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y;
}
int main() {
  int n, s;
  cin >> n >> s;
  for (int i = 1; i <= n; i++) cin >> nd[i].x >> nd[i].y >> nd[i].s;
  sort(nd, nd + n, cp);
  int p = 0;
  nd[0] = {0, 0, 0};
  while (s < 1000000 && p < n) {
    s += nd[++p].s;
  }
  if (s < 1000000)
    cout << -1 << endl;
  else
    printf("%.7lf\n", sqrt(nd[p].x * nd[p].x + nd[p].y * nd[p].y));
}
