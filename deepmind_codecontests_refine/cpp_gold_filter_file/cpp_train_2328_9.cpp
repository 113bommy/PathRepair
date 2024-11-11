#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int inf = (int)1e9;
int main() {
  int n, m, v;
  cin >> n >> m >> v;
  if ((n - 1) * (n - 2) / 2 < m - 1 || m < n - 1) {
    cout << -1;
    return 0;
  }
  int st = 1;
  if (v == 1) st = 2;
  cout << st << " " << v << endl;
  int count = 0;
  for (int i = 1; i <= n; ++i)
    if (i != st)
      for (int j = i + 1; j <= n; ++j)
        if (j != st) {
          printf("%d %d\n", i, j);
          count++;
          if (count == m - 1) return 0;
        }
  return 0;
}
