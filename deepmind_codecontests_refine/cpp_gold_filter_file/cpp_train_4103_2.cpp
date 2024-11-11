#include <bits/stdc++.h>
using namespace std;
int main() {
  map<int, int> teeth;
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    int r, c;
    cin >> r >> c;
    if (teeth.count(r))
      teeth[r] = min(teeth[r], c);
    else
      teeth[r] = c;
  }
  int may_eat = 0;
  for (auto& health : teeth) may_eat += health.second;
  printf("%d\n", min(k, may_eat));
  return 0;
}
