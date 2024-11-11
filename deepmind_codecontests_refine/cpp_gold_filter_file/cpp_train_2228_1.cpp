#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[m];
  for (int i = 1; i <= m; i++) cin >> a[i];
  sort(a + 1, a + m + 1);
  int mn = INT_MAX;
  for (int i = 1; i <= m - n + 1; i++) {
    int x = (a[i + n - 1] - a[i]);
    if (x < mn) mn = x;
  }
  cout << mn << "\n";
  return 0;
}
