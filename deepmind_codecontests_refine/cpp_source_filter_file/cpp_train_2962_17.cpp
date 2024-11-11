#include <bits/stdc++.h>
using namespace std;
int x[505];
double ans;
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 0; i < m; i++) {
    int from, to, weight;
    cin >> from >> to >> weight;
    ans = max(ans, ((double)(x[from] + x[to])) / (double)weight);
  }
  printf("%.15lf\n", ans);
  return 0;
}
