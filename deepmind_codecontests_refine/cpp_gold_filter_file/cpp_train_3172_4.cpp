#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> x, y;
int main() {
  scanf("%d", &n);
  x.resize(n);
  y.resize(n);
  for (int i = 0; i < n; i++) scanf("%d%d", &x[i], &y[i]);
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  long long side = max(x[n - 1] - x[0], y[n - 1] - y[0]);
  cout << side * side;
  return 0;
}
