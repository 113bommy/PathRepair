#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1005;
int grid[MAX_N][MAX_N];
int main() {
  int n;
  cin >> n;
  int m = n / 2;
  int x = 1, y = 1;
  cout << m << endl;
  for (int i = 1; i <= n; i++) {
    cout << x << ' ' << y << endl;
    if (x < m)
      x++;
    else
      y++;
  }
  return 0;
}
