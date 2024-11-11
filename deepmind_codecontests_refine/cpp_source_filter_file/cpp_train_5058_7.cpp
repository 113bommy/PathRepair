#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  int ara1[n], ara2[n];
  for (int i = 0; i < n; i++) cin >> ara1[i] >> ara2[i];
  cin >> m;
  int ara3[m], ara4[m];
  for (int i = 0; i < m; i++) cin >> ara3[i] >> ara4[i];
  sort(ara1, ara1 + n);
  sort(ara2, ara2 + n);
  sort(ara3, ara3 + n);
  sort(ara4, ara4 + n);
  int x = ara3[m - 1] - ara2[0];
  int y = ara1[n - 1] - ara4[0];
  int z = x > y ? x : y;
  if (z < 0)
    cout << 0;
  else
    cout << z;
}
