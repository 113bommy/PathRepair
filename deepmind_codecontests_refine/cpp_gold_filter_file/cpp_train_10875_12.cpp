#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
int a[51][51];
int main() {
  int n, m;
  cin >> n >> m;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) cin >> a[i][j];
  int x, y;
  int sol = 10000;
  cin >> x >> y;
  for (long long i = 1; i <= n - x + 1; i++)
    for (long long j = 1; j <= m - y + 1; j++) {
      int counter = 0;
      for (long long i1 = i; i1 <= i + x - 1; i1++)
        for (long long j1 = j; j1 <= j + y - 1; j1++)
          if (a[i1][j1]) ++counter;
      if (counter < sol) sol = counter;
    }
  for (long long i = 1; i <= n - y + 1; i++)
    for (long long j = 1; j <= m - x + 1; j++) {
      int counter = 0;
      for (long long i1 = i; i1 <= i + y - 1; i1++)
        for (long long j1 = j; j1 <= j + x - 1; j1++)
          if (a[i1][j1]) ++counter;
      if (counter < sol) sol = counter;
    }
  cout << sol;
}
