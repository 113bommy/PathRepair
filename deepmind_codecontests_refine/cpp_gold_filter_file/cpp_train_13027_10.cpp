#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(2));
  for (int i = 0; i < 2 * n; i++) {
    int q;
    cin >> q;
    if (a[q - 1][0] == 0)
      a[q - 1][0] = i;
    else
      a[q - 1][1] = i;
  }
  long long c1 = 0, z1 = 0, z2 = 0, c2 = 0, s = a[0][0] + a[0][1];
  for (int i = 1; i < n; i++) {
    s += min(abs(a[i - 1][0] - a[i][0]) + abs(a[i - 1][1] - a[i][1]),
             abs(a[i - 1][1] - a[i][0]) + abs(a[i - 1][0] - a[i][1]));
  }
  cout << s;
}
